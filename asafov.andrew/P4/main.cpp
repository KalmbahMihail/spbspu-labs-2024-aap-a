#include <iostream>
#include "stringFunctions.hpp"
#include "../../asafov.andrew/common/inputString.hpp"

int main()
{
  char* str = asafov::inputString();
  if (str[0] == '\0')
  {
    delete[] str;
    return 1;
  }

  std::cout << asafov::countUniqLetters(str) << '\n';

  char* unusedLetters = nullptr;
  try
  {
    unusedLetters = new char[26];
  }
  catch (const std::bad_alloc&)
  {
    delete[] str;
    return 1;
  }
  for (size_t i = 0; i < 26; i++)
  {
    unusedLetters[i] = '\0';
  }
  asafov::getUnusedLetters(str, unusedLetters);
  std::cout << unusedLetters << '\n';

  delete[] unusedLetters;
  delete[] str;
  return 0;
}
