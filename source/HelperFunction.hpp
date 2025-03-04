#ifndef HELPER_FUNCTION_HPP
#define HELPER_FUNCTION_HPP

#include "algorithms.hpp"
#include <cmath>
#include <fstream>
#include <string>
int *readDataFromFile(const std::string &filename, int &n);
AlgorithmInfo *findAlgorithm(const std::string &name);
int chooseInputOrder(string s);
#endif
