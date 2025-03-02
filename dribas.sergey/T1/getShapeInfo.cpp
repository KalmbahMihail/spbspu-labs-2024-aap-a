#include "getShapeInfo.hpp"
#include <cstddef>
#include <iostream>
#include "composite-shape.hpp"
#include "concave.hpp"
#include "diamond.hpp"
#include "outputRes.hpp"
#include "rectangle.hpp"
#include "shape.hpp"
#include "triangle.hpp"

double dribas::getAllArea(const Shape* const* Shapes, size_t shapeCount)
{
  double allArea = 0.0;
  for (size_t i = 0; i < shapeCount; i++) {
    allArea += Shapes[i]->getArea();
  }
  return allArea;
}

void dribas::scaleOne(Shape& t, double ratio, point_t Point)
{
  point_t cneter = t.getFrameRect().pos;
  t.move(Point);
  point_t center2 = t.getFrameRect().pos;
  double diffenceX = (center2.x - cneter.x) * ratio * -1;
  double diffenceY = (center2.y - cneter.y) * ratio * -1;
  t.scale(ratio);
  t.move(diffenceX, diffenceY);
}

bool getPoint(std::istream& in, size_t pointCount, dribas::point_t* points)
{
  size_t i = 0;
  for (; i < pointCount && in; i++) {
    in >> points[i].x >> points[i].y;
  }
  return i == pointCount;
}

dribas::CompositeShape dribas::getShapeInfo(std::istream& input, std::ostream& error, CompositeShape shapes, double* scalingFactor)
{
  std::string inputStr;
  bool scaled = false;
  try {
    while (input >> inputStr && inputStr != "SCALE") {
      try {
        if (inputStr == "RECTANGLE") {
         point_t pointR[2] = { 0, 0 };
          if (getPoint(std::cin, 2, pointR)) {
            shapes.push_back(new Rectangle(pointR[0], pointR[1]));
          }
        } else if (inputStr == "TRIANGLE") {
          point_t pointT[3] = { 0, 0 };
          if (getPoint(std::cin, 3, pointT)) {
            shapes.push_back(new Triangle(pointT[0], pointT[1], pointT[2]));
          }
        } else if (inputStr == "DIAMOND") {
          point_t pointD[3] = { 0, 0 };
          if (getPoint(std::cin, 3, pointD)) {
            shapes.push_back(new Diamond(pointD[0], pointD[1], pointD[2]));
          }
        } else if (inputStr == "CONCAVE") {
          point_t pointC[4] = { 0, 0 };
          if (getPoint(std::cin, 4, pointC)) {
            shapes.push_back(new Concave(pointC[0], pointC[1], pointC[2], pointC[3]));
          }
        }
      } catch (const std::invalid_argument& e) {
        error << e.what() << '\n';
      }
    }
    if (inputStr == "SCALE") {
      scaled = true;
      if (shapes.size() == 0) {
        throw std::logic_error("No shapes for scale");
      }
      input >> scalingFactor[0];
      input >> scalingFactor[1];
      input >> scalingFactor[2];
      if (scalingFactor[2] <= 0) {
        throw std::invalid_argument("under zero ratio with scale");
      }
    }
  } catch (const std::exception& e) {
    throw e;
  }
  if (!scaled) {
    throw std::invalid_argument("No Arguments for scale");
  }
  return shapes;
}
