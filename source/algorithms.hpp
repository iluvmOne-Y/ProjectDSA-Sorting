#ifndef ALGORITHMS_HPP
#define ALGORITHMS_HPP

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long (*SortFunction)(int[], int);

struct AlgorithmInfo {
  string name;
  SortFunction sort;
};
int findMax(int a[], int n) {
  int max = a[0];
  for (int i = 1; i < n; i++) {
    if (a[i] > max) {
      max = a[i];
    }
  }
  return max;
}
extern std::vector<AlgorithmInfo> algorithms;
long long SelectionSort(int a[], int n);
long long InsertionSort(int a[], int n);
long long QuickSort(int a[], int n);
long long BinaryInsertionSort(int a[], int n);
long long RadixSort(int a[], int n);
#endif
