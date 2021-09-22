#define COMPOME_LOG true
#include "CompoMe/Log.hpp"
#include "Interfaces/CompoMe/Log/Log_I/Log_I.hpp"
#include "Links/CompoMe/Posix/Udp_client_out/Udp_client_out.hpp"
#include <iostream>
#include <mutex>
#include <sstream>
#include <stdio.h>
#include <string>
#include <thread>

const char *DEFAULT_IP = "127.0.0.1";
const int DEFAULT_PORT = 5555;

int main(int argc, char *argv[]) {

  if( argc != 5) {
    std::cout << "CMD PORT_PATH TYPE TAGS MESSAGE"  << "\n";
    std::cout << "./LogCli_bin \"/sw/log\" INFO notifications,test,tag1 \"Ceci est un message\""  << "\n";

    std::cout << "\n";
    std::cout << "PORT_PATH: PATH" << "\n";;
    std::cout << "TYPE: ERROR|WARNING|INFO|DEBUG,"<< "\n";;
    std::cout << "TAGS: tags1,tags2,tags3,tags4"<< "\n";;
    std::cout << "MESSAGE: \"one message string\"" << "\n";;

    return 1;
  }

  CompoMe::Posix::Udp_client_out cli;
  cli.set_addr(DEFAULT_IP);
  cli.set_port(DEFAULT_PORT);

  CompoMe::Require_helper_t<CompoMe::Log::Log_I> req;

  std::cout << DEFAULT_IP << ":" << DEFAULT_PORT << argv[1] << " " << argv[2] << " "
            << argv[3] << " " << argv[4] << "\n";

  cli.get_many().connect_require(argv[1], req);

  cli.main_connect();

  try {
    std::stringstream ss;
    ss << argv[2];
    CompoMe::Log::Kind_e e;
    ss >> e;

    switch (e) {
    case CompoMe::Log::Kind_e::ERROR: {
      C_TO_ERROR_TAG(req, argv[3], argv[4]);
      break;
    }
    case CompoMe::Log::Kind_e::WARNING: {
      C_TO_WARNING_TAG(req, argv[3], argv[4]);
      break;
    }
    case CompoMe::Log::Kind_e::INFO: {
      C_TO_INFO_TAG(req, argv[3], argv[4]);
      break;
    }
    case CompoMe::Log::Kind_e::DEBUG: {
      C_TO_DEBUG_TAG(req, argv[3], argv[4]);

      break;
    }
    }

  } catch (const char *c) {
    std::cout << "Error: " << c << "\n";
  }

  cli.main_disconnect();
  return 0;
}
