#include <iostream>
#include <string>
#include "rectangle.hpp"
#include "diamond.hpp"
#include "square.hpp"
#include "processShapes.hpp"
#include "createShapes.hpp"

int main()
{
  smirnov::Shape * shapes[1000] = {};
  std::string shapeType = "";
  size_t countShapes = 0;
  bool hasError = false;
  smirnov::point_t centerPoint;
  double scaleFactor = 0.0;
  while (std::cin >> shapeType)
  {
    if (shapeType == "RECTANGLE")
    {
      try
      {
        shapes[countShapes] = smirnov::createRectangle(std::cin);
        countShapes++;
      }
      catch (const std::invalid_argument & e)
      {
        hasError = true;
      }
    }
    else if (shapeType == "DIAMOND")
    {
      try
      {
        shapes[countShapes] = smirnov::createDiamond(std::cin);
        countShapes++;
      }
      catch (const std::invalid_argument & e)
      {
        hasError = true;
      }
    }
    else if (shapeType == "SQUARE")
    {
      try
      {
        shapes[countShapes] = smirnov::createSquare(std::cin);
        countShapes++;
      }
      catch (const std::invalid_argument & e)
      {
        hasError = true;
      }
    }
    else if (shapeType == "SCALE")
    {
      double xCoord = 0.0;
      double yCoord = 0.0;
      std::cin >> xCoord >> yCoord >> scaleFactor;
      centerPoint = {xCoord, yCoord};
      if (scaleFactor <= 0)
      {
        destroyShapes(shapes, countShapes);
        std::cerr << "Incorrect scaleFactor\n";
        return 1;
      }
      break;
    }
        if (std::cin.eof())
    {
      smirnov::destroyShapes(shapes, countShapes);
      std::cerr << "EOF input\n";
      return 1;
    }
  }
  if (countShapes == 0)
  {
    std::cerr << "No figures found\n";
    return 1;
  }
  if (hasError)
  {
    std::cerr << "Incorrect shape size\n";
    return 1;
  }
  std::cout << std::fixed;
  std::cout.precision(1);
  std::cout << smirnov::sumArea(shapes, countShapes);
  smirnov::printFrameRect(shapes, countShapes);
  smirnov::scaleShapes(shapes, countShapes, centerPoint, scaleFactor);
  std::cout << smirnov::sumArea(shapes, countShapes);
  smirnov::printFrameRect(shapes, countShapes);
  std::cout << "\n";
  smirnov::destroyShapes(shapes, countShapes);
}
