#ifndef HELPER_FUNCTION_HPP
#define HELPER_FUNCTION_HPP

#include "algorithms.hpp"
#include <string>
#include <fstream>
int* readDataFromFile(const std::string& filename, int &n);
AlgorithmInfo* findAlgorithm(const std::string& name);

#endif