
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
    bool swapped;

    for (int i = 0; i < n - 1; i++) {
        swapped = false;

        for (int j = 0; j < n - i - 1; j++) {
            ++count;

            if (a[i] > a[j + 1]) {
                swap(a[i], a[j + 1]);
                swapped = true;
            }
        }

        if (!swapped) {
            break;
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

long long QuickSort(int a[], int n) {
    long long count = 0;

    if (n <= 1) {
        return count;
    }


    std::vector<int> lowStack;
    std::vector<int> highStack;
    lowStack.push_back(0);
    highStack.push_back(n - 1);

    while (!lowStack.empty()) {

        int high = highStack.back();
        highStack.pop_back();
        int low = lowStack.back();
        lowStack.pop_back();

        if (low >= high) {
            continue;
        }


        int mid = low + (high - low) / 2;
        int pivotValue;

        if (a[low] <= a[mid] && a[mid] <= a[high]) {
            pivotValue = a[mid];
            std::swap(a[mid], a[high]);
        } else if (a[low] <= a[high] && a[high] <= a[mid]) {
            pivotValue = a[high];
        } else {
            pivotValue = a[low];
            std::swap(a[low], a[high]);
        }

        int i = low - 1;

        for (int j = low; j < high; j++) {
            ++count;

            if (a[j] < pivotValue) {
                i++;
                std::swap(a[i], a[j]);
            }
        }

        int pi = i + 1;
        std::swap(a[pi], a[high]);

        // push sub-arrays to stack
        if (pi - 1 > low) {
            lowStack.push_back(low);
            highStack.push_back(pi - 1);
        }

        if (pi + 1 < high) {
            lowStack.push_back(pi + 1);
            highStack.push_back(high);
        }
    }

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


        while (left <= right) {
            int mid = left + (right - left) / 2;

            ++count;

            if (a[mid] <= key) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }


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

    int max = findMax(a, n, count);

    int* output = new int[n];
    int* countArray = new int[max + 1]();


    for (int i = 0; i < n; i++) {
        countArray[a[i]]++;
    }

    // Store the cumulative count
    for (int i = 1; i <= max; i++) {
        countArray[i] += countArray[i - 1];
    }


    for (int i = n - 1; i >= 0; i--) {
        output[countArray[a[i]] - 1] = a[i];
        countArray[a[i]]--;
    }


    for (int i = 0; i < n; i++) {
        a[i] = output[i];
    }

    delete[] output;
    delete[] countArray;

    return count;
}

long long FlashSort(int a[], int n) {
    long long count = 0;


    int numClasses = int(0.45 * n);
    int* classCounts = new int[numClasses]();


    int minValue = a[0];
    int maxIndex = 0;


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

    if (a[maxIndex] == minValue) {
        delete[] classCounts;
        return count;
    }


    double scalingFactor = (double)(numClasses - 1) / (a[maxIndex] - minValue);


    for (int i = 0; i < n; i++) {
        int classIndex = int(scalingFactor * (a[i] - minValue));
        classCounts[classIndex]++;
    }


    for (int i = 1; i < numClasses; i++) {
        classCounts[i] += classCounts[i - 1];
    }


    std::swap(a[maxIndex], a[0]);

    int numMoves = 0;
    int currentIndex = 0;
    int classIndex = numClasses - 1;
    int flashValue;


    while (numMoves < n - 1) {

        while (currentIndex > classCounts[classIndex] - 1) {
            currentIndex++;
            count++;
            classIndex = int(scalingFactor * (a[currentIndex] - minValue));
        }

        flashValue = a[currentIndex];


        while (currentIndex != classCounts[classIndex]) {
            count++;
            classIndex = int(scalingFactor * (flashValue - minValue));
            std::swap(flashValue, a[classCounts[classIndex] - 1]);

            classCounts[classIndex]--;
            numMoves++;
        }
    }

    delete[] classCounts;


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