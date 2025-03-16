
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
    {"heap-sort", HeapSort},
    {"merge-sort", MergeSort},
    {"flash-sort", FlashSort},
    {"binary-insertion-sort", BinaryInsertionSort},
    {"counting-sort", CountingSort},
    {"bubble-sort", BubbleSort},
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


long long BinaryInsertionSort(int a[], int n) {
  long long count = 1;
  for (int i = 1; i < n; i++) {
      count++;
      int key = a[i];
      int left = 0;
      int right = i - 1;

      // Perform binary search to find the correct position for the key
      count += 1;
      while (left <= right) {
          count++;
          int mid = left + (right - left) / 2;
          if (a[mid] <= key) {
              left = mid + 1;
          } else {
              right = mid - 1;
          }
      }

      // Shift elements to make space for the key
      count += 1;
      for (int j = i - 1; j >= left; j--) {
          count++;
          a[j + 1] = a[j];
      }
      a[left] = key;
  }
  return count;
}


long long SelectionSort(int a[], int n) {
  long long count = 1;
  for (int i = 0; i < n - 1; i++) {
    count += 1;
    int min_idx = i;
    for (int j = i + 1; j < n; j++) {
      count += 2;
      if (a[j] < a[min_idx]) {
        min_idx = j;
      }
    }
    swap(a[i], a[min_idx]);
  }
  return count;
}


long long InsertionSort(int a[], int n) {
  long long count = 1;
  for (int i = 1; i < n; i++) {
    count++;
    int key = a[i];
    int j = i - 1;

    while (j >= 0 && a[j] > key) {
      count += 2;
      a[j + 1] = a[j];
      j--;
    }
    if(j < 0)
    {
      count += 1;
    }
    else
    {
      count += 2;
    }

    a[j + 1] = key;
  }
  return count;
}


long long FlashSort(int a[], int n) {
  long long ComparisonCount = 0;
  ComparisonCount += 1;
  if (n == 0) 
  {
    return ComparisonCount + 1;
  }

  int m = int(0.45 * n); // Number of classes
  int L[m];
  ComparisonCount += 1;
  for(int i = 0; i < m; i++)
  {
    ComparisonCount += 1;
    L[i] = 0;
  }

  // Find the minimum and maximum values in the array
  int min_val = a[0], max_val = a[0];
  ComparisonCount += 1;
  for (int i = 1; i < n; i++) {
    ComparisonCount += 3;
    if (a[i] < min_val)
    {
      min_val = a[i];
    }
    if (a[i] > max_val)
    {  
      max_val = a[i];
    }
  }

  if (min_val == max_val) 
  {
    return ComparisonCount + 1;
  }

  // Classify the elements into classes
  ComparisonCount += 1;
  for (int i = 0; i < n; i++) {
    ComparisonCount += 1;
    int k = int((m - 1) * (a[i] - min_val) / (max_val - min_val));
    L[k]++;
  }

  // Accumulate the counts
  ComparisonCount += 1;
  for (int i = 1; i < m; i++) {
    L[i] += L[i - 1];
    ComparisonCount += 1;
  }

  // Permute the elements into their correct classes
  int count = 0, i = 0, k = m - 1;
  ComparisonCount += 1;
  while (count < n) {
    ComparisonCount += 1;

    ComparisonCount += 1;
    while (i >= L[k]) {
      ComparisonCount += 1;
      i++;
      k = int((m - 1) * (a[i] - min_val) / (max_val - min_val));
    }
    int flash = a[i];

    ComparisonCount += 1;
    while (i < L[k]) {
      ComparisonCount += 1;
      k = int((m - 1) * (flash - min_val) / (max_val - min_val));
      swap(a[i], a[--L[k]]);
      count++;
    }
  }

  // Insertion sort to finish up
  ComparisonCount += 1;
  for (int i = 1; i < n; i++) {
    ComparisonCount += 1;
    int key = a[i];
    int j = i - 1;
    
    while (j >= 0 && a[j] > key) {
      ComparisonCount += 2;
      a[j + 1] = a[j];
      j--;
    }
    if(j < 0)
    {
      ComparisonCount += 1;
    }
    else
    {
      ComparisonCount += 2;
    }

    a[j + 1] = key;
  }

  return ComparisonCount;
}


void MergeArray(int a[], int left, int right, int mid, long long &count){
  int N1 = mid - left + 1,
      N2 = right - mid;
  int LEFT[N1];
  int RIGHT[N2];

  count += 1; // when i == N1, for loop still compare it with N1
  for(int i = 0; i < N1; i++)
  {
    count += 1;
    LEFT[i] = a[left + N1];
  }
  count += 1; // when i == N2, for loop still compare it with N2
  for(int i = 0; i < N2; i++)
  {
    count += 1;
    RIGHT[i] = a[mid + 1 + i];
  }

  int i = 0, j = 0, index = left;

  while(i < N1 && j < N2)
  {
    count += 3;
    if(LEFT[i] <= RIGHT[j])
    {
      a[index] = LEFT[i];
      i++;
    }
    else
    {
      a[index] = RIGHT[j];
      j++;
    }
    index++;
  }
  if(i == N1)
  {
    count += 1;
  }
  else
  {
    count += 2;
  }

  count += 1;
  while(i < N1)
  {
    a[index] = LEFT[i];
    index++;
    i++;
    count += 1;
  }
  
  count += 1;
  while(j < N2)
  {
    a[index] = RIGHT[j];
    index++;
    i++;
    count += 1;
  }
}
void MergeSortRecursion(int a[], int left, int right, long long &count){
  count += 1;
  if(left >= right) 
  {
    return;
  }
  int mid = left + (right - left) / 2;
  MergeSortRecursion(a, left, mid, count);
  MergeSortRecursion(a, mid + 1, right, count);
  MergeArray(a, left, right, mid, count);
}
long long MergeSort(int a[], int n){
  long long count = 0;
  MergeSortRecursion(a, 0, n-1, count);
  return count;
}


int partition(int a[], int low, int high, long long &count) {
  int pivot = a[high];
  int i = low - 1;
  count++;
  for (int j = low; j < high; j++) {
    count += 2;
    if (a[j] < pivot) {
      i++;
      swap(a[i], a[j]);
    }
  }
  swap(a[i + 1], a[high]);
  return i + 1;
}
void QuickSortRecursion(int a[], int low, int high, long long &count) {
  count += 1;
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

  countNum += 1;
  for (int i = 0; i < n; i++) {
    countNum++;
    count[(a[i] / exponent) % 10]++;
  }

  countNum += 1;
  for (int i = 1; i < 10; i++) {
    countNum++;
    count[i] = count[i - 1];
  }

  countNum += 1;
  for (int i = n - 1; i >= 0; i--) {
    countNum++;
    output[count[(a[i] / exponent) % 10] - 1] = a[i];
    count[(a[i] / exponent) % 10]--;
  }

  countNum += 1;
  for (int i = 0; i < n; i++) {
    countNum++;
    a[i] = output[i];
  }
}
long long RadixSort(int a[], int n) {
  long long count = 0;
  int max = findMax(a, n);

  count += 1;
  for (int exp = 1; max / exp>0; exp *= 10) {
    count += 1;
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

  count += 1;
  while (left < right)
  {
    count += 2;
    for (int i = left; i < right; i++)
    {
      count += 2;
      if (data[i] > data[i + 1])
      {
        std::swap(data[i], data[i + 1]);
        k = i;
      }
    }
    right = k;
    
    count += 1;
    for (int i = right; i > left; i--)
    {
      count += 2;
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
    count += 1;
    for (int gap = size / 2; gap > 0; gap /= 2)
    {
      count++;

      count += 1;
      for (int i = gap; i < size; i++)
      {
        count++;
        int temp = data[i];
        int j;

        for (j = i; j >= gap && data[j - gap] > temp; j -= gap)
        {
          count += 2;
          data[j] = data[j - gap];
        }
        if(j < gap)
        {
          count += 1;
        }
        else
        {
          count += 2;
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
      largest = left;
    }

    if(left >= n)
    {
      count += 1;
    }
    else
    {
      count += 2;
    }

    if (right < n && a[right] > a[largest])
    {
      largest = right;
    }
    if(right >= n)
    {
      count += 1;
    }
    else
    {
      count += 2;
    }

    count++;
    if (largest != i)
    {
      swap(a[i], a[largest]);
      heapify(a, n, largest, count);
    }
    return count;
}
long long HeapSort(int a[], int n)
{
    long long count = 0;

    count += 1;
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        count++;
        heapify(a, n, i, count);
    }

    count += 1;
    for (int i = n - 1; i > 0 ; i--)
    {
        swap(a[0], a[i]);  
        count++;
        heapify(a, i, 0, count);
    }

    return count;
}


long long CountingSort(int a[], int n) {
  long long count = 0;

  // Find the maximum element in the array
  int max = a[0];
  count += 1;
  for (int i = 1; i < n; i++) {
      count += 2;
      if (a[i] > max) {
          max = a[i];
      }
  }

  // Create a count array to store the count of each unique element
  int* countArray = new int[max + 1]();
  count += 1;
  for (int i = 0; i < n; i++) {
      count += 1;
      countArray[a[i]]++;
  }

  // Modify the count array by adding the previous counts
  count += 1;
  for (int i = 1; i <= max; i++) {
      count += 1;
      countArray[i] += countArray[i - 1];
  }

  // Build the output array
  int* output = new int[n];
  count += 1;
  for (int i = n - 1; i >= 0; i--) {
      count += 1;
      output[countArray[a[i]] - 1] = a[i];
      countArray[a[i]]--;
  }

  // Copy the sorted elements into the original array
  count += 1;
  for (int i = 0; i < n; i++) {
      count += 1;
      a[i] = output[i];
  }

  delete[] countArray;
  delete[] output;

  return count;
}