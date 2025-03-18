
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
            ++count; // For comparison between a[j] and a[j + 1]

            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
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
            ++count; // For comparison between a[j] and a[min_idx]

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

        while (j >= 0) {
            ++count; // For comparison between a[j] and key

            if (a[j] <= key) {
                break;
            }

            a[j + 1] = a[j];
            j--;
        }

        a[j + 1] = key;
    }

    return count;
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
        int low = lowStack.back();
        int high = highStack.back();

        lowStack.pop_back();
        highStack.pop_back();

        if (low >= high) {
            continue;
        }

        int pivot = a[high];
        int i = low - 1;

        for (int j = low; j < high; j++) {
            ++count; // For comparison between a[j] and pivot

            if (a[j] < pivot) {
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

    return 0;
}

int findMax(int a[], int n, long long& comparisons) {
    int max = a[0];

    for (int i = 1; i < n; i++) {
        ++comparisons; // For comparison between a[i] and max

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
    int left = 0;
    int right = size - 1;

    int k = 0;

    long long count = 0;

    while (left < right) {
        for (int i = left; i < right; i++) {
            ++count; // For comparison between data[i] and data[i + 1]

            if (data[i] > data[i + 1]) {
                std::swap(data[i], data[i + 1]);
                k = i;
            }
        }

        right = k;

        for (int i = right; i > left; i--) {
            ++count; // For comparison between data[i] and data[i - 1]

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

            for (; j >= gap; j -= gap) {
                ++count; // For comparison between data[j - gap] and temp

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

void heapify(int a[], int n, int i, long long& count) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n) {
        ++count; // For comparison between a[left] and a[largest]

        if (a[left] > a[largest]) {
            largest = left;
        }
    }

    if (right < n) {
        ++count; // For comparison between a[right] and a[largest]

        if (a[right] > a[largest]) {
            largest = right;
        }
    }

    if (largest != i) {
        swap(a[i], a[largest]);
        heapify(a, n, largest, count);
    }
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

int binarySearch(int a[], int selectedItem, int low, int high, long long& count) {
    if (high <= low) {
        ++count; // For comparison between selectedItem and a[low]
        return (selectedItem > a[low]) ? (low + 1) : low;
    }

    int mid = (low + high) / 2;

    ++count; // For comparison between selectedItem and a[mid]

    if (selectedItem == a[mid]) {
        return mid + 1;
    }

    ++count; // For comparison between selectedItem and a[mid]

    if (selectedItem > a[mid]) {
        return binarySearch(a, selectedItem, mid + 1, high, count);
    }

    return binarySearch(a, selectedItem, low, mid - 1, count);
}

long long BinaryInsertionSort(int a[], int n) {
    long long count = 0;

    for (int i = 1; i < n; ++i) {
        int selected = a[i];
        int previousIndex = i - 1;

        int insertionIndex = binarySearch(a, selected, 0, previousIndex, count);

        while (previousIndex >= insertionIndex) {
            a[previousIndex + 1] = a[previousIndex];
            --previousIndex;
        }

        a[previousIndex + 1] = selected;
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
        ++count; // For comparison between L[i] and R[j]

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

        count += 2; // For comparisons between a[i] and minValue, and a[i] and a[maxIndex]
    }

    ++count; // For comparison between a[maxIndex] and minValue

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
            ++currentIndex;
            classIndex = int(scalingFactor * (a[currentIndex] - minValue));
        }

        flashValue = a[currentIndex];

        if (classIndex < 0) {
            continue;
        }

        while (currentIndex != classCounts[classIndex]) {
            classIndex = int(scalingFactor * (flashValue - minValue));
            std::swap(flashValue, a[classCounts[classIndex] - 1]);

            --classCounts[classIndex];
            ++numMoves;
        }
    }

    delete[] classCounts;

    for (int i = 1; i < n; i++) {
        int key = a[i];
        int j = i - 1;

        while (j >= 0) {
            ++count; // For comparison between a[j] and key

            if (a[j] > key) {
                a[j + 1] = a[j];
                j--;
            } else {
                break;
            }
        }

        a[j + 1] = key;
    }

    return count;
}