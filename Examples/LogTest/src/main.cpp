#include "Components/CompoMe/Log/To_Stream.hpp"
#include "Components/Component.hpp"
#include "Deployments/Log_server/Log_server.hpp"
#include <Types/CompoMe/Json.hpp>
#include <iostream>
#include <mutex>
#include <stdio.h>
#include <string>
#include <thread>

namespace {
constexpr unsigned int str2int(const char *str, int h = 0) {
  return !str[h] ? 5381 : (str2int(str, h + 1) * 33) ^ str[h];
}

} // Namespace
void wait(CompoMe::Deployment &a) {
  char ch;
  std::mutex m;
  m.lock();

  // main loop
  std::thread t([&m, &a]() {
    while (!m.try_lock()) {
      a.step();
    }
  });

  // cmd loop
  while (true) {
    std::string cmd;
    std::cin >> cmd;
    if (cmd == "exit") {
      m.unlock();
      break;
    } else {
      std::cout << "You need to write \"exit\"."
                << "\n";
    }
  }

  t.join();

  return;
}

int main(int argc, char *argv[]) {

  std::map<std::string, CompoMe::Component *> map_compo;
  std::map<std::string, CompoMe::Log::Log_I *> map_log;

  std::ifstream ifs("test.json");
  CompoMe::Json file_content;
  if (ifs.is_open()) {
    file_content = CompoMe::Json::parse(ifs);
    ifs.close();
  }

  std::string addr = file_content["addr"];
  int port = file_content["port"];

  for (auto &i_j : file_content["Output"].items()) {
    auto &val = i_j.value();
    switch (str2int(val["type"].get<std::string>().c_str())) {
    case str2int("Stream"): {
      auto r = new CompoMe::Log::To_Stream();
      map_compo[i_j.key()] = r;
      map_log[i_j.key()] = &r->get_log();
      break;
    }

    case str2int("File"): {
      auto r = new CompoMe::Log::To_File();
      r->set_path(val["path"].get<std::string>().c_str());
      map_compo[i_j.key()] = r;
      map_log[i_j.key()] = &r->get_log();
      break;
    }

    case str2int("Circular"): {
      auto r = new CompoMe::Log::To_CircularFile();
      r->set_path(val["path"].get<std::string>().c_str());

      map_compo[i_j.key()] = r;
      map_log[i_j.key()] = &r->get_log();

      break;
    }
    }
  }

  // pipeline /////////////////////////////////////////////////////////////////
  CompoMe::Posix::Udp_server_in udp;
  udp.set_addr(file_content["addr"].get<std::string>());
  udp.set_port(file_content["port"].get<std::uint32_t>());
  udp.configuration();
  bool first_is_udp = true;

  for (auto &i_log : file_content["Log"].items()) {
    auto distri = new CompoMe::Log::Distri_log();
    
    if (first_is_udp) {
      first_is_udp = false;
      udp.get_main().connect_interface(distri->get_c());
    }

    std::string p = i_log.value()["Log_in"].get<std::string>();
    std::cout << i_log.key() << ">" << p << "\n";
    udp.get_many().connect_interface(p, distri->get_c());

    if (i_log.value()["Alert_log"].get<bool>()) {
      auto alert_filter = new CompoMe::Log::Filter();
      map_compo[i_log.key()+"_Alert_filter"] = alert_filter;

      if (i_log.value().contains("Alert_filter_in")) {
        std::string path = i_log.value()["Alert_filter_in"];
        udp.get_many().connect_interface(path, alert_filter->get_filter_Manager());
      }

      {
        CompoMe::Log::Kind_e kind = CompoMe::Log::Kind_e::NONE;
        for (auto &i_flag : i_log.value()["Alert_filter_type"]) {
          CompoMe::Log::Kind_e l_kind;
          std::stringstream ss;
          ss << i_flag.get<std::string>();
          ss >> l_kind;
          kind = kind | l_kind;
        }

        alert_filter->set_filter(kind);

        std::vector<CompoMe::String> v;
        for (auto &i_l : i_log.value()["Alert_filter_tag"]) {
          v.push_back(CompoMe::String(i_l));
        }
        alert_filter->set_filter_tag(v);
      }

      distri->list_r.add(&alert_filter->get_input_log());
      alert_filter->pass_log.set(map_log[i_log.value()["Alert_out"]]);
    }

    if (i_log.value()["File_log"].get<bool>()) {
      auto file_filter = new CompoMe::Log::Filter();
      map_compo[i_log.key()+"_File_filter"] = file_filter;

      if (i_log.value().contains("File_filter_in")) {
        std::string path = i_log.value()["File_filter_in"];
        udp.get_many().connect_interface(path, file_filter->get_filter_Manager());
      }

      {
        CompoMe::Log::Kind_e kind = CompoMe::Log::Kind_e::NONE;
        for (auto &i_flag : i_log.value()["File_filter_type"]) {
          CompoMe::Log::Kind_e l_kind;
          std::stringstream ss;
          ss << i_flag.get<std::string>();
          ss >> l_kind;
          kind = kind | l_kind;
        }
        file_filter->set_filter(kind);

        std::vector<CompoMe::String> v;
        for (auto &i_l : i_log.value()["File_filter_tag"]) {
          v.push_back(CompoMe::String(i_l));
        }
        file_filter->set_filter_tag(v);
      }

      distri->list_r.add(&file_filter->get_input_log());

      file_filter->pass_log.set(map_log[i_log.value()["File_out"]]);
    }

    if (i_log.value()["Circular_log"].get<bool>()) {
      distri->list_r.add(map_log[i_log.value()["Circular_out"]]);
    }
  }

  udp.main_connect();

  for (auto i_s : map_compo) {
    std::cout << "connect-> " << i_s.first << "\n";
    i_s.second->connection();
  }

  for (auto i_s : map_compo) {
    std::cout << "configure-> " << i_s.first << "\n";
    i_s.second->configuration();
  }

  for (auto i_s : map_compo) {
    std::cout << "start-> " << i_s.first << "\n";
    i_s.second->start();
  }

  while (true) {
    udp.step();
  }

  for (auto i_s : map_compo) {
    std::cout << "stop-> " << i_s.first << "\n";
    i_s.second->stop();
  }

  for (auto i_s : map_compo) {
    delete i_s.second;
  }

  // Log_server a;
  // a.init();
  // a.configuration();
  // a.link();
  // a.start();

  // std::cout << "Server is started... tape \"exit\""
  //           << "\n";
  // wait(a);

  // a.stop();
  // a.quit();
  return 0;
}
