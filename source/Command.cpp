
#include "Command.hpp"
#include "DataGenerator.hpp"
#include "HelperFunction.hpp"
using namespace std;

void Command1(string algorithmMode, string algorithmName, string intputFile,
              string outputParameter) {

  AlgorithmInfo *algorithm = findAlgorithm(algorithmName);
  if (algorithm == nullptr) {
    cout << "Not found algorithm" << endl;
    return;
  }
  int size = 0;
  int *data = readDataFromFile(intputFile, size);
  algorithm->sort(data, size);
  for (int i = 0; i < size; i++) {
    cout << data[i] << " ";
  }
  cout << "ALGORITHM MODE" << endl;
  cout << "Algorithm: " << algorithmName << endl;
  cout << "Input file: " << intputFile << endl;
  cout << "Input Size: " << size << endl;
  ofstream file("output.txt");
  for (int i = 0; i < size; i++) {
    file << data[i] << " ";
  }
}
void Command2(string algorithmMode, string algorithmName, string InputSize,
              string inputOrder, string outputParameter) {
  AlgorithmInfo *algorithm = findAlgorithm(algorithmName);
  if (algorithm == nullptr) {
    cout << "Not found algorithm" << endl;
    return;
  }
  long long size = stoll(InputSize);
  int data[size];
  GenerateData(data, size, chooseInputOrder(inputOrder));
  algorithm->sort(data, size);
  for (int i = 0; i < size; i++) {
    cout << data[i] << " ";
  }
  cout << "ALGORITHM MODE" << endl;
  cout << "Algorithm: " << algorithmName << endl;
  cout << "Input Size: " << size << endl;
  cout << "Input Order" << inputOrder;
  ofstream file("output.txt");
  for (int i = 0; i < size; i++) {
    file << data[i] << " ";
  }
}
void Command3(string algorithmMode, string algorithmName, string InputSize,
              string outputParameter) {
  AlgorithmInfo *algorithm = findAlgorithm(algorithmName);
  if (algorithm == nullptr) {
    cout << "Not found algorithm" << endl;
    return;
  }
  long long size = stoll(InputSize);
  int data[size];

  GenerateData(data, size, 0);
  algorithm->sort(data, size);
  GenerateData(data, size, 1);
  algorithm->sort(data, size);
  GenerateData(data, size, 2);
  algorithm->sort(data, size);
  GenerateData(data, size, 3);
  algorithm->sort(data, size);
  cout << "ALGORITHM MODE" << endl;
  cout << "Algorithm: " << algorithmName << endl;
  cout << "Input Size: " << size << endl;
  ofstream file("output.txt");
  for (int i = 0; i < size; i++) {
    file << data[i] << " ";
  }
}
