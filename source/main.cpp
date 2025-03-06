#include "Command.hpp"

int main(int argc, char *argv[]) {
  if (argc == 5 && stoll(argv[3])) {
    Command3(argv[1], argv[2], argv[3], argv[4]);
  } else if (argc == 5) {
    Command1(argv[1], argv[2], argv[3], argv[4]);
  } else if (argc == 6) {
    Command2(argv[1], argv[2], argv[3], argv[4], argv[5]);
  }
}
