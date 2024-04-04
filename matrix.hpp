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
    double at(size_t row, size_t col) const;
    void set(size_t row, size_t col, double value);
}