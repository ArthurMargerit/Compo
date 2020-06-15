
#include "Data/User.hpp"
#include <fstream>
#include <iostream>
#include <string.h>

int main(int argc, char *argv[]) {
  if (argc != 2) {
    std::cout << "You need to specified add or list."
              << "\n";
    return 0;
  }

  if (strcmp(argv[1], "add") == 0) {
    User u;
    std::cout << "Id:";

    std::cin >> u.a_id();

    std::cout << "Fist Name:";
    std::cin >> u.a_first_name();

    std::cout << "Last Name:";
    std::cin >> u.a_last_name();

    std::cout << "Score:";
    std::cin >> u.a_score();

    std::cout << "Path to img profile:";
    std::cin >> u.a_profile_img().a_path();

    std::ofstream ofs("bdd.txt", std::ios_base::app);
    ofs << u;
    ofs.close();
  } else if (strcmp(argv[1], "list") == 0) {

    std::ifstream ifs("bdd.txt");
    while (ifs.peek() != -1) {
      User u;
      ifs >> u;
      std::cout << u.get_id() << ":" << u.get_first_name().str << " "
                << u.get_last_name().str << " with a score of " << u.get_score() << " | "
                << u.a_profile_img().get_path() << "\n";
    }
    ifs.close();
  }

  return 0;
}
