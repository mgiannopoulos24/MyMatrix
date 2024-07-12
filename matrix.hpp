#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <vector>
#include <stdexcept>

class matrix {
private:
    std::vector<double> data;
    size_t rowSize, colSize;

public:
    matrix(size_t rowSize, size_t colSize);

    size_t getRowSize() const;
    size_t getColSize() const;

    double at(size_t row, size_t col) const;
    void set(size_t row, size_t col, double value);

    void reshape(size_t rowSize, size_t colSize);
    void resize(size_t rowSize, size_t colSize);

    matrix operator+(const matrix& addend) const;
    matrix operator-(const matrix& subtrahend) const;
    matrix operator*(const matrix& multiplicand) const;
    matrix operator*(const double multiplier) const;
};

#endif // MATRIX_HPP
