#include "HelperFunction.hpp"

using namespace std;


int* readDataFromFile(const string &filename, int& n) {
    ifstream file(filename);

    file >> n;
    int* a = new int[n];

    for (int i = 0; i < n; i++) {
        file >> a[i];
    }

    file.close();
    return a;
}

AlgorithmInfo* findAlgorithm(const string &name) {
    for (auto &algorithm : algorithms) {
        if (algorithm.name == name) {
            return &algorithm;
        }
    }

    return nullptr;
}

//-rand: randomized data0  -nsorted: nearly sorted data3 -sorted: sorted data1
//-rev: reverse sorted data2
int chooseInputOrder(string s) {
    if (s == "-rand") {
        return 0;
    } else if (s == "-sorted") {
        return 1;
    } else if (s == "-rev") {
        return 2;
    } else if (s == "-nsorted") {
        return 3;
    } else {
        return -1;
    }
}

void printOutputBasedOnParameter(string outputParameter, double time, long long comparisons) {
    if (outputParameter == "-time") {
        cout << "Running Time: " << time << " ms" << endl;
    } else if (outputParameter == "-comp") {
        cout << "Comparisons: " << comparisons << endl;
    } else if (outputParameter == "-both") {
        cout << "Running Time: " << time << " ms" << endl;
        cout << "Comparisons: " << comparisons << endl;
    }
}

void printTerminal(string outputParameter, int order, double runningTime, long long comparasion) {
    if (order == 0) {
        cout << "Input order: Randomized" << endl;
    } else if (order == 1) {
        cout << "Input order: Sorted" << endl;

    } else if (order == 2) {
        cout << "Input order: Reversed" << endl;

    } else {
        cout << "Input order:Nearly Sorted " << endl;
    }

    cout << "-------------------------------------" << endl;
    printOutputBasedOnParameter(outputParameter, runningTime, comparasion);
    cout << endl;
}

void writeFile(int a[], int size, string fileName) {
    ofstream output(fileName);
    output << size << endl;

    for (int i = 0; i < size; i++) {
        output << a[i] << " ";
    }
}
