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

long long SelectionSort(int a[], int n);
long long InsertionSort(int a[], int n);
long long QuickSort(int a[], int n);
long long RadixSort(int a[], int n);
long long ShakerSort(int data[], int n);
long long ShellSort(int data[], int n);
long long HeapSort(int a[], int n);
long long BubbleSort(int a[], int n);
long long BinaryInsertionSort(int a[], int n);
long long MergeSort(int a[], int n);
long long CountingSort(int a[], int n);
long long FlashSort(int a[], int n);

#endif
