#!/bin/bash

# Compile the main.cpp file
g++ -o main.exe main.cpp algorithms.cpp Command.cpp DataGenerator.cpp HelperFunction.cpp

# Check if the compilation was successful
if [ $? -eq 0 ]; then
    echo "Compilation successful. Executable created: main"
else
    echo "Compilation failed."
fi