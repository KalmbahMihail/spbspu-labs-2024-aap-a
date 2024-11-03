#ifndef MTX_TRANSFORM_HPP
#define MTX_TRANSFORM_HPP
#include <iostream>
#include <cstdlib>
namespace nikonov
{
  bool inputCheck(int argc, char** argv);
  std::istream& readMatrix(std::istream& input, int* mtx, size_t m, size_t n, size_t& read);
  void printMatrix(std::ostream& output, int* mtx, size_t m, size_t n);
  void transformMatrix(int* mtx, size_t m, size_t n, size_t decreaser, size_t vertMove);
}
#endif
