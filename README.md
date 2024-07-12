# MyMatrix

## Overview
MyMatrix is a simple C++ project that provides a foundation for working with matrices and vectors. It includes basic functionalities to initialize, access elements, and perform operations on one-dimensional vectors and two-dimensional matrices. The project aims to prioritize speed, clarity, and memory safety by using contiguous vector spaces for data storage and minimal overhead for translating between one-dimensional and two-dimensional coordinates.

## Features
- **Matrix Initialization:** Initialize matrices with specified row and column sizes.
- **Element Access:** Access elements using row and column indices.
- **Matrix Operations:** Perform basic matrix operations such as addition, subtraction, multiplication (both matrix-matrix and scalar), and reshaping.
- **Memory Safety:** Includes bounds checking to ensure safe access to matrix elements.
- **Simplicity:** Designed to be simple yet efficient for educational and small-scale applications.

## Objective
This project serves as an intermediate step towards developing a machine learning library from scratch in C++. By focusing on fundamental matrix operations and memory management, it lays the groundwork for more complex functionalities required in machine learning algorithms.

## Usage
To use MyMatrix in your C++ project:
1. Include the `matrix.hpp` header file in your source files.
2. Initialize matrices using the `matrix` class with desired dimensions.
3. Perform operations like addition, subtraction, and multiplication using overloaded operators or member functions.
4. Ensure to handle exceptions like `std::out_of_range` and `std::invalid_argument` for safe matrix operations.

## Example
```cpp
#include <iostream>
#include "matrix.hpp"

int main() {
    matrix A(3, 3); // Create a 3x3 matrix A
    matrix B(3, 3); // Create another 3x3 matrix B

    // Initialize matrix elements
    for (size_t i = 0; i < A.getRowSize(); ++i) {
        for (size_t j = 0; j < A.getColSize(); ++j) {
            A.set(i, j, i * 3 + j);
            B.set(i, j, j * 3 + i);
        }
    }

    // Perform matrix addition
    matrix C = A + B;

    // Display result
    std::cout << "Matrix A:\n";
    for (size_t i = 0; i < A.getRowSize(); ++i) {
        for (size_t j = 0; j < A.getColSize(); ++j) {
            std::cout << A.at(i, j) << " ";
        }
        std::cout << "\n";
    }

    std::cout << "\nMatrix B:\n";
    for (size_t i = 0; i < B.getRowSize(); ++i) {
        for (size_t j = 0; j < B.getColSize(); ++j) {
            std::cout << B.at(i, j) << " ";
        }
        std::cout << "\n";
    }

    std::cout << "\nMatrix A + B:\n";
    for (size_t i = 0; i < C.getRowSize(); ++i) {
        for (size_t j = 0; j < C.getColSize(); ++j) {
            std::cout << C.at(i, j) << " ";
        }
        std::cout << "\n";
    }

    return 0;
}
```

```console
User@Github:~$ g++ -o example example.cpp matrix.cpp
User@Github:~$ ./example
Matrix A:
0 1 2
3 4 5
6 7 8

Matrix B:
0 3 6
1 4 7
2 5 8

Matrix A + B:
0 4 8
4 8 12
8 12 16
```

