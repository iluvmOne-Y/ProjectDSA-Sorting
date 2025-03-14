
#include "algorithms.hpp"
//  Binary Insertion Sort,//  Merge Sort,
//  Counting Sort,  and Flash Sort
// arr[5] = 1 5 3 4 2
// arr[5] = 1 3 5 4 2 key =4
// arr[5] = 1 2 3 4 5 key =2 j=0
std::vector<AlgorithmInfo> algorithms = {
    {"selection-sort", SelectionSort},
    {"insertion-sort", InsertionSort},
    {"quick-sort", QuickSort},
    {"radix-sort", RadixSort},
    {"shaker-sort", shakerSort},
    {"shell-sort", shellSort},
    {"heap-sort", HeapSort}
  };
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
  long long count = 0;
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
void countSort(int a[], int n, int exponent, long long &countNum) {
  int output[n];
  int count[10] = {0};
  for (int i = 0; i < n; i++) {
    countNum++;
    count[(a[i] / exponent) % 10]++;
  }
  for (int i = 1; i < 10; i++) {
    countNum++;
    count[i] = count[i - 1];
  }
  for (int i = n - 1; i >= 0; i--) {
    countNum++;
    output[count[(a[i] / exponent) % 10] - 1] = a[i];
    count[(a[i] / exponent) % 10]--;
  }
  for (int i = 0; i < n; i++) {
    countNum++;
    a[i] = output[i];
  }
}
long long RadixSort(int a[], int n) {
  long long count = 0;
  int max = findMax(a, n);

  for (int exp = 1; max / exp>0; exp *= 10) {
    countSort(a, n, exp, count);
  }
  return count;
}
long long shakerSort(int data[], int size)
{
  long long count=0;
  int left = 0;
  int right = size - 1;
  int k = 0;

  while (left < right)
  {
    count++;
    for (int i = left; i < right; i++)
    {
      count++;
      if (data[i] > data[i + 1])
      {
        std::swap(data[i], data[i + 1]);
        k = i;
      }
    }
    right = k;

    for (int i = right; i > left; i--)
    {
      count++;
      if (data[i] < data[i - 1])
      {
        std::swap(data[i], data[i - 1]);
        k = i;
      }
    }
    left = k;
  }
  return count;
}

long long shellSort(int data[], int size)
{
  long long count = 0;
  for (int gap = size / 2; gap > 0; gap /= 2)
  {
    count++;
    for (int i = gap; i < size; i++)
    {
      count++;
      int temp = data[i];
      int j;
      for (j = i; j >= gap && data[j - gap] > temp; j -= gap)
      {
        count++;
        data[j] = data[j - gap];
      }
      data[j] = temp;
    }
  }
  return count;
}

long long heapify(int a[], int n, int i, long long &count)
{
    int largest = i;  
    int left = 2 * i + 1;  
    int right = 2 * i + 2;  

    if (left < n && a[left] > a[largest])
    {
        count++;
        largest = left;
    }

    if (right < n && a[right] > a[largest])
    {
        count++;
        largest = right;
    }

    if (largest != i)
    {
        swap(a[i], a[largest]);
        count++;
        heapify(a, n, largest, count);
    }
    return count;
}

long long HeapSort(int a[], int n)
{
    long long count = 0;

    for (int i = n / 2 - 1; i >= 0; i--)
    {
        count++;
        heapify(a, n, i, count);
    }

    for (int i = n - 1; i > 0 ; i--)
    {
        swap(a[0], a[i]);  
        count++;
        heapify(a, i, 0, count);
    }

    return count;
}