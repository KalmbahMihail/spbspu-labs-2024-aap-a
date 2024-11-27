#include <iostream>
#include <dynamicArray.hpp>
#include "string_check.hpp"
int main()
{
  size_t capacity = 10;
  char* arr = nikonov::getLine(std::cin, capacity);
  if (!arr)
  {
    return 1;
  }
  if (!nikonov::is_float(arr))
  {
    std::cout << "false\n";
  }
  else
  {
    std::cout << "true\n";
  }
  free(arr);
  return 0;
}
