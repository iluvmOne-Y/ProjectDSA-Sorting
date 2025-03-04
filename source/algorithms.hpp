#ifndef ALGORITHMS_HPP
#define ALGORITHMS_HPP

#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef void (*SortFunction)(int[], int);

struct AlgorithmInfo {
  string name;
  SortFunction sort;
};

extern std::vector<AlgorithmInfo> algorithms;

void SelectionSort(int data[], int size);
void InsertionSort(int a[], int n);
void QuickSort(int a[], int n);
#endif
