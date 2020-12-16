
#include "C_readline.hpp"
#include <readline/history.h>
#include <readline/readline.h>

namespace CompoMe {
  namespace Tools {
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
  } // Tools
} // CompoMe
