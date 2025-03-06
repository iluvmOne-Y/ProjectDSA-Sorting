
#include "algorithms.hpp"
//  Binary Insertion Sort,// Shaker Sort, Shell Sort, Heap Sort, Merge Sort,
//  Counting Sort, Radix Sort, and Flash Sort
// arr[5] = 1 5 3 4 2
// arr[5] = 1 3 5 4 2 key =4
// arr[5] = 1 2 3 4 5 key =2 j=0
vector<AlgorithmInfo> algorithms = {
    {"selection-sort", SelectionSort},
    {"insertion-sort", InsertionSort},
    {"quick-sort", QuickSort},
    {"binary-insertion-sort", BinaryInsertionSort}};
long long BubbleSort(int a[], int n) {
  long long count = 0;
  for (int i = 0; i < n - 1; i++) {
    count++;
    for (int j = 1; j < n; j++) {
      count++;
      if (a[i] > a[j]) {
        swap(a[i], a[j]);
      }
    }
  }
  return count;
}
long long SelectionSort(int a[], int n) {
  long long count = 0;
  for (int i = 0; i < n - 1; i++) {
    count++;
    int min_idx = i;
    for (int j = i + 1; j < n; j++) {
      count++;
      if (a[j] < a[min_idx]) {
        min_idx = j;
      }
    }
    swap(a[i], a[min_idx]);
  }
  return count;
}
long long InsertionSort(int a[], int n) {
  int count = 0;
  for (int i = 1; i < n; i++) {
    count++;
    int key = a[i];
    int j = i - 1;
    while (j >= 0 && a[j] > key) {
      count++;
      a[j + 1] = a[j];
      j--;
    }
    a[j + 1] = key;
  }
  return count;
}
void BinaryInsertionSortRecursion(int a[], int low, int high) {
  for (int i = low; i < high; i++) {
    int key = a[i];
    int j = i - 1;
    while (j >= 0 && a[j] > key) {
      a[j + 1] = a[j];
      j--;
    }
    a[j + 1] = key;
  }
}
long long BinaryInsertionSort(int a[], int n) {
  int low = 0;
  int high = n - 1;
  int mid = (low + high) / 2;
  if (low < high) {
    BinaryInsertionSortRecursion(a, low, mid - 1);
    BinaryInsertionSortRecursion(a, mid + 1, high);
  }
  return 0;
}
int partition(int a[], int low, int high, long long &count) {

  int pivot = a[high];
  int i = low - 1;
  for (int j = low; j < high; j++) {
    count++;
    if (a[j] < pivot) {
      i++;
      swap(a[i], a[j]);
    }
  }
  swap(a[i + 1], a[high]);
  return i + 1;
}
void QuickSortRecursion(int a[], int low, int high, long long &count) {
  if (low < high) {
    int pi = partition(a, low, high, count);
    QuickSortRecursion(a, low, pi - 1, count);
    QuickSortRecursion(a, pi + 1, high, count);
  }
}
long long QuickSort(int a[], int n) {
  long long count = 0;
  QuickSortRecursion(a, 0, n - 1, count);
  return count;
}
