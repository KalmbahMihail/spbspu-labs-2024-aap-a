#include "sinh_taylor_calculator.hpp"
#include <stdexcept>
#include <cmath>

double kushekbaev::taylorCalc(double x, double error)
{
  double next = x;
  double result = next;
  size_t n = 1;

  while (std::abs(next) > error)
  {
    next *= x * x / ((2 * n) * (2 * n + 1));
    result += next;
    n++;
  }
  return result;
}
