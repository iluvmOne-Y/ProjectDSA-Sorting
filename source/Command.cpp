
#include "Command.hpp"
#include "DataGenerator.hpp"
#include "HelperFunction.hpp"
#include <chrono>
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
  auto start = chrono::high_resolution_clock::now();
  long long count = algorithm->sort(data, size);
  auto stop = chrono::high_resolution_clock::now();
  auto duration = chrono::duration_cast<chrono::milliseconds>(stop - start);

 
  cout << "ALGORITHM MODE" << endl;
  cout << "Algorithm: " << algorithmName << endl;
  cout << "Input file: " << intputFile << endl;
  cout << "Input Size: " << size << endl;
  cout << "-------------------------------------" << endl;
  printOutputBasedOnParameter(outputParameter, duration.count(), count);
  writeFile(data, size, "output.txt");
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
  auto start = chrono::high_resolution_clock::now();
  long long count = algorithm->sort(data, size);
  auto stop = chrono::high_resolution_clock::now();
  auto duration = chrono::duration_cast<chrono::milliseconds>(stop - start);
  writeFile(data, size, "input.txt");
  cout << "ALGORITHM MODE" << endl;
  cout << "Algorithm: " << algorithmName << endl;
  cout << "Input Size: " << size << endl;
  cout << "Input Order: " << inputOrder<<endl;
  cout << "-----------------------------" << endl;
  printOutputBasedOnParameter(outputParameter, duration.count(), count);
  writeFile(data, size, "output.txt");
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
  double runningTime = 0;
  cout << "ALGORITHM MODE" << endl;
  cout << "Algorithm: " << algorithmName << endl;
  cout << "Input Size: " << size << endl;
  cout << endl;
  GenerateData(data, size, 0);
  writeFile(data, size, "input1.txt");
  auto start1 = chrono::high_resolution_clock::now();

  long long count1 = algorithm->sort(data, size);
  auto stop1 = chrono::high_resolution_clock::now();
  auto duration1 = chrono::duration_cast<chrono::milliseconds>(stop1 - start1);
  printTerminal(outputParameter,0, duration1.count(), count1);
  GenerateData(data, size, 1);
  writeFile(data, size, "input2.txt");
  auto start2 = chrono::high_resolution_clock::now();
  long long count2 = algorithm->sort(data, size);
  auto stop2 = chrono::high_resolution_clock::now();
  auto duration2 = chrono::duration_cast<chrono::milliseconds>(stop2 - start2);
  printTerminal(outputParameter,1, duration2.count(), count2);
  GenerateData(data, size, 2);
  writeFile(data, size, "input3.txt");
  auto start3 = chrono::high_resolution_clock::now();
  long long count3 = algorithm->sort(data, size);
  auto stop3 = chrono::high_resolution_clock::now();
  auto duration3 = chrono::duration_cast<chrono::milliseconds>(stop3 - start3);
  printTerminal(outputParameter,2, runningTime, count3);
  GenerateData(data, size, 3);
  writeFile(data, size, "input4.txt");
  auto start4 = chrono::high_resolution_clock::now();
  long long count4 = algorithm->sort(data, size);
  auto stop4 = chrono::high_resolution_clock::now();
  auto duration4 = chrono::duration_cast<chrono::milliseconds>(stop4 - start4);
  printTerminal(outputParameter,3, runningTime, count4);
  
  
}
void Command4(string algorithmMode, string algorithmName1,
              string algorithmName2, string inputFile) {
  AlgorithmInfo *algorithm1 = findAlgorithm(algorithmName1);
  AlgorithmInfo *algorithm2 = findAlgorithm(algorithmName2);
  if (algorithm1 == nullptr || algorithm2 == nullptr) {
    cout << "Not found algorithm" << endl;
    return;
  }

  int size = 0;
  int *data = readDataFromFile(inputFile, size);

  auto start1 = chrono::high_resolution_clock::now();
  long long count1 = algorithm1->sort(data, size);
  auto stop1 = chrono::high_resolution_clock::now();
  auto duration1 = chrono::duration_cast<chrono::milliseconds>(stop1 - start1);
  writeFile(data, size, "output1.txt");
  auto start2 = chrono::high_resolution_clock::now();
  long long count2 = algorithm2->sort(data, size);
  auto stop2 = chrono::high_resolution_clock::now();
  auto duration2 = chrono::duration_cast<chrono::milliseconds>(stop2 - start2);
  writeFile(data, size, "output2.txt");
  cout << "COMPARE MODE" << endl;
  cout << "Input file: " << inputFile << endl;
  cout << "Input size: " << size << endl;
  cout << "------------------------------" << endl;
  cout << "RunningTime: " << "Sort time 1: " << duration1.count() << " ms" << " | "
       << "Sort time 2: " << duration2.count() << " ms" << endl;
  cout << "Comparasions: " << count1 << " | " << count2 << endl;
}
void Command5(string algorithmMode, string algorithmName1,
              string algorithmName2, string inputSize, string inputOrder) {

  AlgorithmInfo *algorithm1 = findAlgorithm(algorithmName1);
  AlgorithmInfo *algorithm2 = findAlgorithm(algorithmName2);

  long long size = stoll(inputSize);
  int data[size];
  GenerateData(data, size, chooseInputOrder(inputOrder));
  writeFile(data, size, "input.txt");
  auto start1 = chrono::high_resolution_clock::now();
  long long count1 = algorithm1->sort(data, size);
  auto stop1 = chrono::high_resolution_clock::now();
  auto duration1 = chrono::duration_cast<chrono::milliseconds>(stop1 - start1);
  auto start2 = chrono::high_resolution_clock::now();
  long long count2 = algorithm2->sort(data, size);
  auto stop2 = chrono::high_resolution_clock::now();
  auto duration2 = chrono::duration_cast<chrono::milliseconds>(stop2 - start2);
  cout << "COMPARE MODE" << endl;
  cout << "Input size: " << inputSize << endl;
  cout << "Input order: " << inputOrder << endl;
  cout << "------------------------------" << endl;
  cout << "RunningTime: " << "Sort time 1: " << duration1.count() << "ms" << " | "
       << "Sort time 2: " << duration2.count() << " ms" << endl;
  cout << "Comparasions: " << count1 << " | " << count2 << endl;

}
