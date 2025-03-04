#include "HelperFunction.hpp"

using namespace std;
int *readDataFromFile(const string &filename, int &n) {
  ifstream file(filename);

  file >> n;
  int *a = new int[n];
  for (int i = 0; i < n; i++) {
    file >> a[i];
  }
  file.close();
  return a;
}
AlgorithmInfo *findAlgorithm(const string &name) {
  for (auto &algorithm : algorithms) {
    if (algorithm.name == name) {
      return &algorithm;
    }
  }
  return nullptr;
}
//-rand: randomized data0  -nsorted: nearly sorted data3 -sorted: sorted data1
//-rev: reverse sorted data2
int chooseInputOrder(string s) {
  if (s == "-rand") {
    return 0;
  } else if (s == "-sorted") {
    return 1;

  } else if (s == "-rev") {
    return 2;
  } else
    return 3;
}
