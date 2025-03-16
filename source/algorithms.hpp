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
extern std::vector<AlgorithmInfo> algorithms;
inline int findMax(int a[], int n) {
  int max = a[0];
  for (int i = 1; i < n; i++) {
    if (a[i] > max) {
      max = a[i];
    }
  }
  return max;
}

long long BinaryInsertionSort(int a[], int n);
long long SelectionSort(int a[], int n);
long long InsertionSort(int a[], int n);
long long FlashSort(int a[], int n);
long long MergeSort(int a[], int n);
long long QuickSort(int a[], int n);

long long RadixSort(int a[], int n);
long long shakerSort(int data[], int size, long long &count);
long long shellSort(int data[], int size, long long &count);
long long HeapSort(int a[], int n);
long long BubbleSort(int a[], int n);
#endif
