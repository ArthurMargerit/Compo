
#include "C_readline.hpp"
#include <iostream>

namespace CompoMe {
  namespace Tools {
    std::string C_readline(std::string prompt) {
      while (true) {

        std::string cmd;

        std::cout << prompt << "\n";
        std::getline (std::cin, cmd);

        std::cout << "|" << cmd << "|" << "\n";

        if (cmd == "") {
           return "exit";
        }

        if (cmd != "") {
          // add_history(cmd);
        } else {
          continue;
        }

        // free(cmd);
        return cmd;
      }
    }
  } // Tools
} // CompoMe
