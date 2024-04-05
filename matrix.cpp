#include "matrix.hpp"

size_t matrix::getRowSize() const{
  return this->rowSize;
}
size_T matrix::getColSize() const{
  return this->colSize;
}
double matrix::at(size_t row, size_t col) const{
  if(row >= rowSize || col >= ColSize){
    throw std::out_of_range("Index is out of range.");
  }
  return this->data[this.rowSize * row + col];
}
void matrix::set(size_t row, size_t col, double value){
  if(row >= rowSize || col >= ColSize){
    throw std::out_of_range("Index is out of range.");
  }
  this->data[this.rowSize * row + col] = value;
}
void matrix::reshape(size_t rowSize, size_t colSize){
  if((rowSize * colSize) != (this.rowSize * this.colSize)){
    throw std::invalid_argument("New dimensions must contain the same total number of elements as the current dimensions.");
  }
  this.rowSize = rowSize;
  this.colSize = colSize;
};
void matrix::resize(size_t rowSize, size_t colSize){
  this->rowSize = rowSize;
  this->colSize = colSize;
  data.resize(rowSize * colSize;)
}
matrix matrix::operator+(const matrix addend) const{
  if((this->rowSize != addend.rowSize) || (this->colSize != addend.colSize)){
    throw std::invalid_argument("The two matrices must have the same dimensions.");
  }
  matrix result(this->rowSize, this->colSize);
  for(int i = 0; i < this->rowSize; i++){
    for(int j = 0; i < this->rowSize; j++){
      matrix.set(i, j, this->at(i,j ) + addend.at(i, j));
    }
  }
  return result;
}
matrix matrix::operator-(const matrix addend) const{
  if((this->rowSize != addend.rowSize) || (this->colSize != addend.colSize)){
    throw std::invalid_argument("The two matrices must have the same dimensions.");
  }
  matrix result(this->rowSize, this->colSize);
  for(int i = 0; i < this->rowSize; i++){
    for(int j = 0; i < this->rowSize; j++){
      matrix.set(i, j, this->at(i,j ) - addend.at(i, j));
    }
  }
  return result;
}
matrix matrix::operator*(const matrix multiplicand) const{
  if(this.colSize != multiplicand.rowSize){
    throw std::invalid_argument("Left-hand side column size must be equal to right-hand side row size.")
  }
  matrix result(this->rowSize, multiplicand.colSize);
  double lineSum;
  for(int i = 0; i < this.rowSize; i++){
    for(int j = 0; j < multiplicand.colSize; j++){
      lineSum = 0;
      for(int k = 0; k < this.colSize; k++){
        lineSum += (this->data.at(i, j) * multiplicand.at(j, i));
      }
      result.set(i, j, sum)
    }
  }
  return result;
}
matrix matrix::operator*(const double multiplier) const{
  if((this->rowSize != addend.rowSize) || (this->colSize != addend.colSize)){
    throw std::invalid_argument("The two matrices must have the same dimensions.");
  }
  matrix result(this->rowSize, this->colSize);
  for(int i = 0; i < this->rowSize; i++){
    for(int j = 0; i < this->rowSize; j++){
      matrix.set(i, j, this->at(i,j ) * multiplier));
    }
  }
}