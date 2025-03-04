
#include "algorithms.hpp"

vector<AlgorithmInfo> algorithms = {
    {"selection-sort", SelectionSort}
};

// Define the function
void SelectionSort(int data[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < size; j++) {
            if (data[j] < data[min_idx]) {
                min_idx = j;
            }
        }
        std::swap(data[i], data[min_idx]);
    }
}