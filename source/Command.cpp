
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
  int *data = new int[size];
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

  cout << "ALGORITHM MODE" << endl;
  cout << "Algorithm: " << algorithmName << endl;
  cout << "Input Size: " << size << endl;
  cout << endl;

  // For random data
  int *data1 = new int[size];
  GenerateData(data1, size, 0);
  writeFile(data1, size, "input1.txt");
  auto start1 = chrono::high_resolution_clock::now();
  long long count1 = algorithm->sort(data1, size);
  auto stop1 = chrono::high_resolution_clock::now();
  auto duration1 = chrono::duration_cast<chrono::milliseconds>(stop1 - start1);
  printTerminal(outputParameter, 0, duration1.count(), count1);
  delete[] data1;

  // For sorted data
  int *data2 = new int[size];
  GenerateData(data2, size, 1);
  writeFile(data2, size, "input2.txt");
  auto start2 = chrono::high_resolution_clock::now();
  long long count2 = algorithm->sort(data2, size);
  auto stop2 = chrono::high_resolution_clock::now();
  auto duration2 = chrono::duration_cast<chrono::milliseconds>(stop2 - start2);
  printTerminal(outputParameter, 1, duration2.count(), count2);
  delete[] data2;

  // For reverse sorted data
  int *data3 = new int[size];
  GenerateData(data3, size, 2);
  writeFile(data3, size, "input3.txt");
  auto start3 = chrono::high_resolution_clock::now();
  long long count3 = algorithm->sort(data3, size);
  auto stop3 = chrono::high_resolution_clock::now();
  auto duration3 = chrono::duration_cast<chrono::milliseconds>(stop3 - start3);
  printTerminal(outputParameter, 2, duration3.count(), count3);
  delete[] data3;

  // For nearly sorted data
  int *data4 = new int[size];
  GenerateData(data4, size, 3);
  writeFile(data4, size, "input4.txt");
  auto start4 = chrono::high_resolution_clock::now();
  long long count4 = algorithm->sort(data4, size);
  auto stop4 = chrono::high_resolution_clock::now();
  auto duration4 = chrono::duration_cast<chrono::milliseconds>(stop4 - start4);
  printTerminal(outputParameter, 3, duration4.count(), count4);
  delete[] data4;
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
  int *originalData = readDataFromFile(inputFile, size);

  int *data1 = new int[size];
  for (int i = 0; i < size; i++) {
    data1[i] = originalData[i];
  }

  auto start1 = chrono::high_resolution_clock::now();
  long long count1 = algorithm1->sort(data1, size);
  auto stop1 = chrono::high_resolution_clock::now();
  auto duration1 = chrono::duration_cast<chrono::milliseconds>(stop1 - start1);
  writeFile(data1, size, "output1.txt");
  
  int *data2 = new int[size];
  for (int i = 0; i < size; i++) {
    data2[i] = originalData[i];
  }

  auto start2 = chrono::high_resolution_clock::now();
  long long count2 = algorithm2->sort(data2, size);
  auto stop2 = chrono::high_resolution_clock::now();
  auto duration2 = chrono::duration_cast<chrono::milliseconds>(stop2 - start2);
  writeFile(data2, size, "output2.txt");
  cout << "COMPARE MODE" << endl;
  cout << "Input file: " << inputFile << endl;
  cout << "Input size: " << size << endl;
  cout << "------------------------------" << endl;
  cout << "RunningTime: " << "Sort time 1: " << duration1.count() << " ms" << " | "
       << "Sort time 2: " << duration2.count() << " ms" << endl;
  cout << "Comparasions: " << count1 << " | " << count2 << endl;
  
  delete[] data1;
  delete[] data2;
  delete[] originalData;
}

void Command5(string algorithmMode, string algorithmName1,
              string algorithmName2, string inputSize, string inputOrder) {

  AlgorithmInfo *algorithm1 = findAlgorithm(algorithmName1);
  AlgorithmInfo *algorithm2 = findAlgorithm(algorithmName2);
  
  if (algorithm1 == nullptr || algorithm2 == nullptr) {
    cout << "Not found algorithm" << endl;
    return;
  }

  long long size = stoll(inputSize);
  int *originalData = new int[size];
  GenerateData(originalData, size, chooseInputOrder(inputOrder));
  writeFile(originalData, size, "input.txt");

  int *data1 = new int[size];
  for (int i = 0; i < size; i++) {
    data1[i] = originalData[i];
  }

  auto start1 = chrono::high_resolution_clock::now();
  long long count1 = algorithm1->sort(data1, size);
  auto stop1 = chrono::high_resolution_clock::now();
  auto duration1 = chrono::duration_cast<chrono::milliseconds>(stop1 - start1);
  
  int *data2 = new int[size];
  for (int i = 0; i < size; i++) {
    data2[i] = originalData[i];
  }

  auto start2 = chrono::high_resolution_clock::now();
  long long count2 = algorithm2->sort(data2, size);
  auto stop2 = chrono::high_resolution_clock::now();
  auto duration2 = chrono::duration_cast<chrono::milliseconds>(stop2 - start2);

  cout << "COMPARE MODE" << endl;
  cout << "Input size: " << inputSize << endl;
  cout << "Input order: " << inputOrder << endl;
  cout << "------------------------------" << endl;
  cout << "RunningTime: " << "Sort time 1: " << duration1.count() << "ms" << " | "
       << "Sort time 2: " << duration2.count() << " ms" << endl;
  cout << "Comparasions: " << count1 << " | " << count2 << endl;
  
  delete[] data1;
  delete[] data2;
  delete[] originalData;
}
// Function to calculate performance metrics for all algorithms with various input sizes
void CommandBenchmarkAll(string outputParameter) {
  // Array of input sizes to test
  int inputSizes[] = {10000, 30000, 50000, 100000, 300000, 500000};
  int numSizes = 6;
  
  // Array of input orders to test
  string inputOrders[] = {"-rand", "-sorted", "-rev", "-nsorted"};
  string orderNames[] = {"Randomized", "Sorted", "Reversed", "Nearly Sorted"};
  int numOrders = 4;
  
  // Open output file for results
  ofstream resultsFile("benchmark_results.csv");
  resultsFile << "Algorithm,Input Size,Input Order,Time (ms),Comparisons\n";
  
  cout << "BENCHMARK ALL ALGORITHMS" << endl;
  cout << "=========================" << endl;
  
  // Loop through each algorithm
  for (auto& algorithm : algorithms) {
      cout << "\nTesting algorithm: " << algorithm.name << endl;
      cout << "-------------------------" << endl;
      
      // Loop through each input size
      for (int i = 0; i < numSizes; i++) {
          int size = inputSizes[i];
          cout << "  Input Size: " << size << endl;
          
          // Loop through each input order
          for (int j = 0; j < numOrders; j++) {
              cout << "    Order: " << orderNames[j] << " - ";
              
              // Generate data with the current order
              int* data = new int[size];
              GenerateData(data, size, j);
              
              // Run the algorithm and measure performance
              auto start = chrono::high_resolution_clock::now();
              long long count = algorithm.sort(data, size);
              auto stop = chrono::high_resolution_clock::now();
              auto duration = chrono::duration_cast<chrono::milliseconds>(stop - start);
              
              // Print and save results
              cout << "Time: " << duration.count() << " ms, ";
              cout << "Comparisons: " << count << endl;
              
              // Write results to CSV file
              resultsFile << algorithm.name << "," << size << "," 
                         << orderNames[j] << "," << duration.count() 
                         << "," << count << "\n";
              
              // Clean up
              delete[] data;
          }
      }
  }
  
  resultsFile.close();
  cout << "\nBenchmark completed. Results saved to benchmark_results.csv" << endl;
}