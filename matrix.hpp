#include <vector>
#include <stdio.h>
#include <stdexcept>

class matrix{
  private:
    std::vector<double> data;
    size_t rowSize, colSize;
  public:
    matrix(size_t rowSize, size_t colSize) : rowSize(rowSize), colSize(colSize){
      data.resize(rowSize * colSize);
    };
    size_t getRowSize() const;
    size_t getColSize() const;
    void resize();
    double at(size_t row, size_t col) const;
    void set(size_t row, size_t col, double value);
    matrix operator+(const matrix addend) const;
    matrix operator-(const matrix subtrahend) const;
    matrix operator*(const matrix multiplicand) const;
    matrix operator*(const double multiplier) const;
}