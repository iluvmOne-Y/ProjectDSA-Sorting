
Data Structures and Algorithms - Sorting Algorithms Implementation

This project implements and analyzes 12 different sorting algorithms, measuring their performance in terms of execution time and number of comparisons across various input sizes and data distributions.

## Project Structure

```
ProjectDSA-Sorting/
├── source/
│   ├── algorithms.cpp       # Implementation of all sorting algorithms
│   ├── algorithms.hpp       # Declarations for sorting algorithms
│   ├── Command.cpp          # Command-line parsing and execution functions
│   ├── Command.hpp          # Command function declarations
│   ├── DataGenerator.cpp    # Functions to generate different data distributions
│   ├── DataGenerator.hpp    # Data generation function declarations
│   ├── HelperFunction.cpp   # Utility functions (file I/O, algorithm selection)
│   ├── HelperFunction.hpp   # Utility function declarations
│   └── main.cpp             # Entry point and command-line parsing
├── Report.pdf               # Analysis report of algorithm performance
└── Checklist-withFormula.xlsx  # Performance data spreadsheet
```

## Sorting Algorithms Implemented

1. **Bubble Sort** - Simple comparison-based sorting with O(n²) average time complexity
2. **Selection Sort** - In-place comparison sort with O(n²) complexity
3. **Insertion Sort** - Builds sorted array one element at a time
4. **Quick Sort** - Divide and conquer algorithm with O(n log n) average time complexity
5. **Radix Sort** - Non-comparative integer sorting algorithm
6. **Shaker Sort** (Cocktail Sort) - Bidirectional bubble sort variation
7. **Shell Sort** - Generalization of insertion sort with varying gap sequences
8. **Heap Sort** - Comparison-based sort using a binary heap data structure
9. **Binary Insertion Sort** - Insertion sort using binary search to find insertion position
10. **Merge Sort** - Divide and conquer algorithm with stable O(n log n) time complexity
11. **Counting Sort** - Integer sorting algorithm with O(n+k) time complexity
12. **Flash Sort** - Distribution sorting algorithm with O(n) best case

## Features

- Command-line interface for running different sorting benchmarks
- Support for various input data distributions:
  - Random data
  - Sorted data
  - Reversed data
  - Nearly sorted data
- Performance measurement:
  - Execution time in milliseconds
  - Number of comparisons performed
- Output options to display:
  - Execution time only
  - Comparison count only
  - Both metrics
- Built-in benchmarking to compare all algorithms across multiple data sizes

## Usage

The program supports five primary command modes:

### Command 1: Sort from file
```
./test -a <algorithm> <input-file> <output-parameter>
```

### Command 2: Sort generated data with specified size and order
```
./test -a <algorithm> <input-size> <input-order> <output-parameter>
```

### Command 3: Run algorithm on all four data distributions
```
./test -a <algorithm> <input-size> <output-parameter>
```

### Command 4: Compare two algorithms using data from file
```
./test -c <algorithm1> <algorithm2> <input-file>
```

### Command 5: Compare two algorithms using generated data
```
./test -c <algorithm1> <algorithm2> <input-size> <input-order>
```

### Parameters

- `<algorithm>`: One of the 12 implemented sorting algorithms (e.g., `bubble-sort`, `quick-sort`)
- `<input-file>`: Path to input data file
- `<input-size>`: Number of elements to sort
- `<input-order>`: Data distribution (`-rand`, `-sorted`, `-rev`, `-nsorted`)
- `<output-parameter>`: What to display (`-time`, `-comp`, `-both`)

## Dependencies

- C++ Standard Library
- `<chrono>` for precise time measurements
- `<fstream>` for file I/O operations
- `<vector>` for dynamic arrays
- `<string>` for string operations

## Performance Considerations

- Some algorithms (like Quick Sort) may experience performance degradation or segmentation faults with large sorted/reversed arrays.
- Memory usage varies by algorithm, with some requiring additional storage proportional to the input size.
- The comparison count metric provides insights into algorithmic efficiency independent of hardware.

## Building and Running

Compile the project with:
```
g++ -o test source/*.cpp
```

Run benchmarks for all algorithms:
```
./test
```

Or run a specific command as detailed in the Usage section.

## License

This project is available for educational purposes.
