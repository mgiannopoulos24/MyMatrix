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