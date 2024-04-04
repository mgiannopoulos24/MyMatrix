#include "matrix.hpp"

size_t matrix::getRowSize() const{
  return this.rowSize;
}
size_T matrix::getColSize() const{
  return this.colSize;
}
double matrix::at(size_t row, size_t col) const{
  if(row >= rowSize || col >= ColSize){
    throw std::out_of_range("Index is out of range!");
  }
  return this.data[this.rowSize * row + col];
}
void matrix::set(size_t row, size_t col, double value){
  if(row >= rowSize || col >= ColSize){
    throw std::out_of_range("Index is out of range!");
  }
  this.data[this.rowSize * row + col] = value;
}
