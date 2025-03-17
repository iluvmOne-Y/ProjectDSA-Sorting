#include "Command.hpp"

int main(int argc, char *argv[]) {
  //benchmark all algorithms
  
/* if(argc == 1) {
    CommandBenchmarkAll("-both");
    return 0;
  }
*/
  //command mode
  if (strcmp(argv[1],"-a")==0) {
    if (argc == 5 && isdigit(argv[3][0])) {
      Command3(argv[1], argv[2], argv[3], argv[4]);
    } else if (argc == 5) {
      Command1(argv[1], argv[2], argv[3], argv[4]);
    } else if (argc == 6) {
      Command2(argv[1], argv[2], argv[3], argv[4], argv[5]);
    }
  } else {
    if (argc == 5) {
      Command4(argv[1], argv[2], argv[3], argv[4]);
    } else
      Command5(argv[1], argv[2], argv[3], argv[4], argv[5]);
  }
      
}
