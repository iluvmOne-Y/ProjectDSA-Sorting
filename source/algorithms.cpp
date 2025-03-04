
#include "algorithms.hpp"
// Selection Sort, Insertion Sort, Binary Insertion Sort, Bubble Sort,
// Shaker Sort, Shell Sort, Heap Sort, Merge Sort,
// Quick Sort, Counting Sort, Radix Sort, and Flash Sort
// arr[5] = 1 5 3 4 2
// arr[5] = 1 3 5 4 2 key =4
// arr[5] = 1 2 3 4 5 key =2 j=0
vector<AlgorithmInfo> algorithms = {
    {"selection-sort", SelectionSort},
    {"insertion-sort", InsertionSort},
    {"quick-sort", QuickSort},
};

void SelectionSort(int data[], int size) {
  for (int i = 0; i < size - 1; i++) {
    int min_idx = i;
    for (int j = i + 1; j < size; j++) {
      if (data[j] < data[min_idx]) {
        min_idx = j;
      }
    }
    swap(data[i], data[min_idx]);
  }
}
void InsertionSort(int a[], int n) {
  for (int i = 1; i < n; i++) {
    int key = a[i];
    int j = i - 1;
    while (j >= 0 && a[j] > key) {
      a[j + 1] = a[j];
      j--;
    }
    a[j + 1] = key;
  }
}
int partition(int a[], int low, int high) {
  int pivot = a[high];
  int i = low - 1;
  for (int j = low; j < high; j++) {
    if (a[j] < pivot) {
      i++;
      swap(a[i], a[j]);
    }
  }
  swap(a[i + 1], a[high]);
  return i + 1;
}
void QuickSortRecursion(int a[], int low, int high) {
  if (low < high) {
    int pi = partition(a, low, high);
    QuickSortRecursion(a, low, pi - 1);
    QuickSortRecursion(a, pi + 1, high);
  }
}
void QuickSort(int a[], int n) { QuickSortRecursion(a, 0, n - 1); }
