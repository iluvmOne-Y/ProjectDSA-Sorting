#ifndef COMMAND_HPP
#define COMMAND_HPP

#include <chrono>
#include <iostream>
#include <math.h>
#include <string>
#include <cstring>

using namespace std;


void Command1(std::string algorithmMode, std::string algorithmName,
    std::string intputFile, std::string outputParameter);

void Command2(string algorithmMode, string algorithmName, string InputSize,
    string inputOrder, string outputParameter);
void Command3(string algorithmMode, string algorithmName, string InputSize,
    string outputParameter);
void Command4(string algorithmMode, string algorithmName1,
    string algorithmName2, string Inputfile);

void Command5(string algorithmMode, string algorithmName1,
    string algorithmName2, string inputSize, string inputOrder);

void CommandBenchmarkAll(string outputParameter);

#endif
