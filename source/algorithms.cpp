
#include "algorithms.hpp"
// Binary Insertion Sort,//  Merge Sort,
// Counting Sort,  and Flash Sort
// arr[5] = 1 5 3 4 2
// arr[5] = 1 3 5 4 2 key =4
// arr[5] = 1 2 3 4 5 key =2 j=0

std::vector<AlgorithmInfo> algorithms = {
    {"bubble-sort", BubbleSort},
    {"selection-sort", SelectionSort},
    {"insertion-sort", InsertionSort},
    {"quick-sort", QuickSort},
    {"radix-sort", RadixSort},
    {"shaker-sort", ShakerSort},
    {"shell-sort", ShellSort},
    {"heap-sort", HeapSort},
    {"binary-insertion-sort", BinaryInsertionSort},
    {"merge-sort", MergeSort},
    {"counting-sort", CountingSort},
    {"flash-sort", FlashSort}
};


long long BubbleSort(int a[], int n) {
    long long count = 0;

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
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
        int min_idx = i;

        for (int j = i + 1; j < n; j++) {
            ++count;

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
        int key = a[i];
        int j = i - 1;

        while (j >= 0 && ++count && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }

        a[j + 1] = key;
    }

    return count;
}


int partition(int a[], int low, int high, long long& count) {
    int pivot = a[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        ++count;

        if (a[j] < pivot) {
            i++;
            swap(a[i], a[j]);
        }
    }

    swap(a[i + 1], a[high]);
    return i + 1;
}

void QuickSortRecursion(int a[], int low, int high, long long& count) {
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

long long countSortForRadixSort(int a[], int n, int exponent) {
    int* output = new int[n];
    int count[10] = {0};

    long long comparisons = 0;

    for (int i = 0; i < n; i++) {
        count[(a[i] / exponent) % 10]++;
    }

    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--) {
        output[count[(a[i] / exponent) % 10] - 1] = a[i];
        count[(a[i] / exponent) % 10]--;
    }

    for (int i = 0; i < n; i++) {
        a[i] = output[i];
    }

    delete[] output;

    return comparisons;
}

int findMax(int a[], int n, long long& comparisons) {
    int max = a[0];

    for (int i = 1; i < n; i++) {
        ++comparisons;

        if (a[i] > max) {
            max = a[i];
        }
    }

    return max;
}

long long RadixSort(int a[], int n) {
    long long count = 0;
    int max = findMax(a, n, count);

    for (int exp = 1; max / exp > 0; exp *= 10) {
        count += countSortForRadixSort(a, n, exp);
    }

    return count;
}

long long ShakerSort(int data[], int size) {
    long long count = 0;
    int left = 0;
    int right = size - 1;
    int k = 0;

    while (left < right) {
        for (int i = left; i < right; i++) {
            ++count;

            if (data[i] > data[i + 1]) {
                std::swap(data[i], data[i + 1]);
                k = i;
            }
        }

        right = k;

        for (int i = right; i > left; i--) {
            ++count;

            if (data[i] < data[i - 1]) {
                std::swap(data[i], data[i - 1]);
                k = i;
            }
        }

        left = k;
    }

    return count;
}

long long ShellSort(int data[], int size) {
    long long count = 0;

    for (int gap = size / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < size; i++) {
            int temp = data[i];
            int j = i;

            for ( ; j >= gap; j -= gap) {
                ++count;

                if (data[j - gap] <= temp) {
                    break;
                }

                data[j] = data[j - gap];
            }

            data[j] = temp;
        }
    }

    return count;
}

long long heapify(int a[], int n, int i, long long& count) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    ++count;

    if (left < n && a[left] > a[largest]) {
        largest = left;
    }

    ++count;

    if (right < n && a[right] > a[largest]) {
        largest = right;
    }


    if (largest != i) {
        swap(a[i], a[largest]);
        heapify(a, n, largest, count);
    }

    return count;
}

long long HeapSort(int a[], int n) {
    long long count = 0;

    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(a, n, i, count);
    }

    for (int i = n - 1; i > 0 ; i--) {
        swap(a[0], a[i]);
        heapify(a, i, 0, count);
    }

    return count;
}

long long BinaryInsertionSort(int a[], int n) {
    long long count = 0;

    for (int i = 1; i < n; i++) {
        int key = a[i];
        int left = 0;
        int right = i - 1;

        // Binary search to find the correct position for the key
        while (left <= right) {
            int mid = left + (right - left) / 2;

            ++count;

            if (a[mid] <= key) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        // Shift elements to make space for the key
        for (int j = i - 1; ++count && j >= left; j--) {
            a[j + 1] = a[j];
        }

        a[left] = key;
    }

    return count;
}

void merge(int a[], int left, int mid, int right, long long& count) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int* L = new int[n1];
    int* R = new int[n2];

    for (int i = 0; i < n1; i++) {
        L[i] = a[left + i];
    }

    for (int j = 0; j < n2; j++) {
        R[j] = a[mid + 1 + j];
    }

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        ++count;

        if (L[i] <= R[j]) {
            a[k] = L[i];
            i++;
        } else {
            a[k] = R[j];
            j++;
        }

        k++;
    }

    while (i < n1) {
        a[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        a[k] = R[j];
        j++;
        k++;
    }

    delete[] L;
    delete[] R;
}

void mergeSortRecursion(int a[], int left, int right, long long& count) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSortRecursion(a, left, mid, count);
        mergeSortRecursion(a, mid + 1, right, count);

        merge(a, left, mid, right, count);
    }
}

long long MergeSort(int a[], int n) {
    long long count = 0;
    mergeSortRecursion(a, 0, n - 1, count);
    return count;
}

long long CountingSort(int a[], int n) {
    long long count = 0;
    int max = *std::max_element(a, a + n);

    int* output = new int[n];
    int* countArray = new int[max + 1]();

    // Store the count of each element
    for (int i = 0; i < n; i++) {
        countArray[a[i]]++;
    }

    // Store the cumulative count
    for (int i = 1; i <= max; i++) {
        countArray[i] += countArray[i - 1];
    }

    // Build the output array
    for (int i = n - 1; i >= 0; i--) {
        output[countArray[a[i]] - 1] = a[i];
        countArray[a[i]]--;
    }

    // Copy the output array to the original array
    for (int i = 0; i < n; i++) {
        a[i] = output[i];
    }

    delete[] output;
    delete[] countArray;

    return count;
}

long long FlashSort(int a[], int n) {
    long long count = 0;

    // Calculate the number of classes
    int numClasses = int(0.45 * n);
    int* classCounts = new int[numClasses]();

    // Initialize min and max values
    int minValue = a[0];
    int maxIndex = 0;

    // Find the minimum and maximum values in the array
    for (int i = 1; i < n; i++) {
        if (a[i] < minValue) {
            minValue = a[i];
        }

        if (a[i] > a[maxIndex]) {
            maxIndex = i;
        }

        count += 2;
    }

    ++count;

    // If all elements are the same, return the count
    if (a[maxIndex] == minValue) {
        delete[] classCounts;
        return count;
    }

    // Calculate the scaling factor
    double scalingFactor = (double)(numClasses - 1) / (a[maxIndex] - minValue);

    // Count the number of elements in each class
    for (int i = 0; i < n; i++) {
        int classIndex = int(scalingFactor * (a[i] - minValue));
        classCounts[classIndex]++;
    }

    // Calculate the cumulative count
    for (int i = 1; i < numClasses; i++) {
        classCounts[i] += classCounts[i - 1];
    }

    // Move the maximum element to the first position
    std::swap(a[maxIndex], a[0]);

    int numMoves = 0;
    int currentIndex = 0;
    int classIndex = numClasses - 1;
    int flashValue;

    // Permute the elements to their correct classes
    while (numMoves < n - 1) {
        // Find the correct class for the current element
        while (currentIndex > classCounts[classIndex] - 1) {
            currentIndex++;
            classIndex = int(scalingFactor * (a[currentIndex] - minValue));
        }

        flashValue = a[currentIndex];

        // Place the element in its correct class
        while (currentIndex != classCounts[classIndex]) {
            classIndex = int(scalingFactor * (flashValue - minValue));
            std::swap(flashValue, a[classCounts[classIndex] - 1]);

            classCounts[classIndex]--;
            numMoves++;
        }
    }

    delete[] classCounts;

    // Use insertion sort to finish up
    for (int i = 1; i < n; i++) {
        int key = a[i];
        int j = i - 1;

        while (j >= 0 && ++count && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }

        a[j + 1] = key;
    }

    return count;
}