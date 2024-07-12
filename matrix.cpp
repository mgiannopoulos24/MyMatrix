#include "matrix.hpp"

matrix::matrix(size_t rowSize, size_t colSize) : rowSize(rowSize), colSize(colSize) {
    data.resize(rowSize * colSize);
}

size_t matrix::getRowSize() const {
    return this->rowSize;
}

size_t matrix::getColSize() const {
    return this->colSize;
}

double matrix::at(size_t row, size_t col) const {
    if (row >= rowSize || col >= colSize) {
        throw std::out_of_range("Index is out of range.");
    }
    return this->data[row * colSize + col];
}

void matrix::set(size_t row, size_t col, double value) {
    if (row >= rowSize || col >= colSize) {
        throw std::out_of_range("Index is out of range.");
    }
    this->data[row * colSize + col] = value;
}

void matrix::reshape(size_t rowSize, size_t colSize) {
    if (rowSize * colSize != this->rowSize * this->colSize) {
        throw std::invalid_argument("New dimensions must contain the same total number of elements as the current dimensions.");
    }
    this->rowSize = rowSize;
    this->colSize = colSize;
}

void matrix::resize(size_t rowSize, size_t colSize) {
    this->rowSize = rowSize;
    this->colSize = colSize;
    this->data.resize(rowSize * colSize);
}

matrix matrix::operator+(const matrix& addend) const {
    if (this->rowSize != addend.rowSize || this->colSize != addend.colSize) {
        throw std::invalid_argument("The two matrices must have the same dimensions.");
    }
    matrix result(this->rowSize, this->colSize);
    for (size_t i = 0; i < this->rowSize; ++i) {
        for (size_t j = 0; j < this->colSize; ++j) {
            result.set(i, j, this->at(i, j) + addend.at(i, j));
        }
    }
    return result;
}

matrix matrix::operator-(const matrix& subtrahend) const {
    if (this->rowSize != subtrahend.rowSize || this->colSize != subtrahend.colSize) {
        throw std::invalid_argument("The two matrices must have the same dimensions.");
    }
    matrix result(this->rowSize, this->colSize);
    for (size_t i = 0; i < this->rowSize; ++i) {
        for (size_t j = 0; j < this->colSize; ++j) {
            result.set(i, j, this->at(i, j) - subtrahend.at(i, j));
        }
    }
    return result;
}

matrix matrix::operator*(const matrix& multiplicand) const {
    if (this->colSize != multiplicand.rowSize) {
        throw std::invalid_argument("Left-hand side column size must be equal to right-hand side row size.");
    }
    matrix result(this->rowSize, multiplicand.colSize);
    for (size_t i = 0; i < this->rowSize; ++i) {
        for (size_t j = 0; j < multiplicand.colSize; ++j) {
            double sum = 0;
            for (size_t k = 0; k < this->colSize; ++k) {
                sum += this->at(i, k) * multiplicand.at(k, j);
            }
            result.set(i, j, sum);
        }
    }
    return result;
}

matrix matrix::operator*(const double multiplier) const {
    matrix result(this->rowSize, this->colSize);
    for (size_t i = 0; i < this->rowSize; ++i) {
        for (size_t j = 0; j < this->colSize; ++j) {
            result.set(i, j, this->at(i, j) * multiplier);
        }
    }
    return result;
}
