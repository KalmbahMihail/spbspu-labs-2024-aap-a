#include <iostream>
#include <fstream>


int main(int argc, char ** argv)
{
  for (int i = 0; i < argc; ++i)
  {
    std::cout << argv[i] << "\n";
  }
  std::ifstream input(argv[2]);
  //...
  std::ofstream output(argv[3]);
}
