#ifndef MATRIX_H
#define MATRIX_H

#include <string>
namespace cherkasov
{
  bool readMatrix(const char* inputFile, int**& matrix, int& rows, int& cols, bool useFixedArray);
  int processMatrix(int** matrix, int rows, int cols);
  void freeMatrix(int** matrix, int rows);

  bool lowerTriangul(int** matrix, int rows, int cols);
  int readMatrix(std::istream& inFile, size_t& rows, size_t& cols, int* matrix);
  int countNonZeroDiagonals(const int* matrix, size_t rows, size_t cols);
  bool isMatrixLowerTriangular(const int* matrix, size_t rows, size_t cols);
}
#endif
