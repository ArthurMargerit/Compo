#include "CompoMe/Tools/Term.hpp"
#include "CompoMe/Tools/Call.hpp"

#include "Interfaces/Caller_stream.hpp"

#include <iostream>
#include <readline/history.h>
#include <readline/readline.h>
#include <stdio.h>

namespace CompoMe {
namespace Tools {
namespace {
std::string C_readline(std::string prompt) {
  while (true) {
    char *cmd = readline(prompt.c_str());

    if (cmd == nullptr) {
      return "exit";
    }

    std::string s_cmd(cmd);

    if (s_cmd != "") {
      add_history(cmd);
    } else {
      continue;
    }

    free(cmd);
    return s_cmd;
  }
}
} // Namespace

void term(std::map<std::string, Caller_stream *> &c, std::string prompt) {

  while (true) {
    std::string s_cmd = C_readline(prompt);

    if (s_cmd == "exit") {
      std::cout << "exit"
                << "\n";
      break;
    }

    if (s_cmd == "?" || s_cmd == "help") {
      std::cout << "O help"
                << "\n";
      std::cout << "O exit"
                << "\n";
      std::cout << "O term Interface"
                << "\n";
      for (auto &v : c) {
        std::cout << "O " << v.first << "\n";
        std::cout << "L";
        v.second->introspection(std::cout);
      }

      continue;
    }

    if (std::string(s_cmd, 0, 5) == "term ") {
      std::string Interface_name = std::string(s_cmd, 5, s_cmd.length());
      auto find_interface = c.find(Interface_name);
      if (find_interface == c.end()) {
        std::cout << "The Interface " << Interface_name << " do not exist"
                  << "\n";
        continue;
      }
      CompoMe::Caller_stream *caller_s = c[Interface_name];
      term(caller_s, prompt + Interface_name + ">>>");
      continue;
    }

    auto l_r = call(c, s_cmd);
    if (l_r.first) {
      std::cout << s_cmd << " => " << l_r.second << "\n";
    } else {
      std::cout << "Error: " << l_r.second << "\n";
    }
  }
}

void term(std::map<std::string, std::map<std::string, Caller_stream *>> &c,
          std::string prompt) {

  while (true) {
    std::string s_cmd = C_readline(">>>");

    if (s_cmd == "exit") {
      break;
    }

    if (s_cmd == "?" || s_cmd == "help") {
      std::cout << "O help"
                << "\n";
      std::cout << "O exit"
                << "\n";
      std::cout << "O term Interface"
                << "\n";
      for (auto &com : c) {
        std::cout << "O " << com.first << "\n";
        for (auto &inter : com.second) {
          std::cout << "  L " << inter.first << "\n";
          std::cout << "    L ";
          inter.second->introspection(std::cout);
        }
      }
      continue;
    }

    if (std::string(s_cmd, 0, 5) == "term ") {
      std::string component_name = std::string(s_cmd, 5, s_cmd.length());
      auto find_interface = c.find(component_name);
      if (find_interface == c.end()) {
        std::cout << "The component " << component_name << " do not exist"
                  << "\n";
        continue;
      }
      auto caller_s = c[component_name];
      term(caller_s, prompt + component_name + ">>>");
      continue;
    }

    auto l_r = call(c, s_cmd);
    if (l_r.first) {
      std::cout << s_cmd << " => " << l_r.second << "\n";
    } else {
      std::cout << "Error: " << l_r.second << "\n";
    }
  }
}
void term(Caller_stream *c, std::string prompt) {
  while (true) {
    std::string s_cmd = C_readline(prompt);

    if (s_cmd == "exit") {
      std::cout << "exit"
                << "\n";
      break;
    }

    if (s_cmd == "?" || s_cmd == "help") {
      std::cout << "O help"
                << "\n";
      std::cout << "O exit"
                << "\n";

      std::cout << "O ";
      c->introspection(std::cout);
      continue;
    }

    auto l_r = call(c, s_cmd);
    if (l_r.first) {
      std::cout << s_cmd << " => " << l_r.second << "\n";
    } else {
      std::cout << "Error: " << l_r.second << "\n";
    }
  }
}

} // namespace Tools
} // namespace CompoMe
