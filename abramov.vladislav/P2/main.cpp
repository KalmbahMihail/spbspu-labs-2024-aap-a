#include <iostream>
#include <cstring>
#include <cmath>
#include "taylorPolynomial.hpp"

int main()
{
  double left = 0.0;
  double right = 0.0;
  int k = 0;
  std::cin >> left >> right >> k;
  if (!std::cin)
  {
    std::cerr << "Wrong input!\n";
    return 1;
  }
  if (k <= 0 || left > right || left <= -1 || right >= 1)
  {
    std::cerr << "Wrong input!\n";
    return 1;
  }
  constexpr double error = 0.001;
  constexpr double step = 0.05;
  for (auto i = left; i < right; i += step)
  {
    std::fabs(i) < 1e-10 ? abramov::str_of_table(0, k, error) : abramov::str_of_table(i, k, error);
    std::cout << "\n";
  }
  abramov::str_of_table(right, k, error);
  std::cout << "\n";
}
