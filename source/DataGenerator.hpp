
#include <cmath>
#include <fstream>
#include <iostream>
#include <time.h>
using namespace std;

template <class T> void HoanVi(T &a, T &b) {
  T x = a;
  a = b;
  b = x;
}
void GenerateRandomData(int a[], int n);
void GenerateSortedData(int a[], int n);
void GenerateReverseData(int a[], int n);
void GenerateData(int a[], int n, int dataType);
void GenerateNearlySortedData(int a[], int n);
