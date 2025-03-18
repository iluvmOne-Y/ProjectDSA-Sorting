#ifndef HELPER_FUNCTION_HPP
#define HELPER_FUNCTION_HPP

#include "algorithms.hpp"
#include <cmath>
#include <fstream>
#include <string>


int* readDataFromFile(const std::string &filename, int& n);
AlgorithmInfo* findAlgorithm(const std::string &name);
int chooseInputOrder(string s);
void printTerminal(string outputParameter, int order, double runningTime, long long comparasion);
void writeFile(int a[], int size, string fileName);
void printOutputBasedOnParameter(string outputParameter, double time, long long comparisons);

#endif
