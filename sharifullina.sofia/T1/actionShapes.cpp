#include "actionShapes.hpp"

double sharifullina::getSumArea(const Shape* const* shapes, size_t n)
{
  double res = 0;
  for (size_t i = 0; i < n; i++)
  {
    res += shapes[i]->getArea();
  }
  return res;
}

void sharifullina::scaleOfShapes(Shape ** shapes, size_t n, point_t p, double k)
{
  if (k <= 0)
  {
    std::cerr << "Сoefficient must be positive.\n";
    return;
  }
  sharifullina::scaleShapesWithoutCheck(shapes, n, p, k);
}

void sharifullina::scaleShapesWithoutCheck(Shape ** shapes, size_t n, point_t p, double k)
{
  for (size_t i = 0; i < n; i++)
  {
    point_t ptr = shapes[i]->getFrameRect().pos;
    shapes[i]->move(p);
    shapes[i]->scale(k);
    point_t newptr = shapes[i]->getFrameRect().pos;
    point_t vectorMove = {(newptr.x - ptr.x) * k, (newptr.y - ptr.y) * k};
    shapes[i]->move(-vectorMove.x, -vectorMove.y);
  }
}

void sharifullina::printCoorRect(std::ostream& out, const Shape* const* shapes, size_t n)
{
  for (size_t i = 0; i < n; i++)
  {
    rectangle_t rect = shapes[i]->getFrameRect();
    double lx = rect.pos.x - rect.width / 2.0;
    double ly = rect.pos.y - rect.height / 2.0;
    double rx = rect.pos.x + rect.width / 2.0;
    double ry = rect.pos.y + rect.height / 2.0;
    out << lx << " " << ly << " " << rx << " " << ry;
  }
}

void sharifullina::destroyShapes(Shape ** shapes, size_t n)
{
  for (size_t i = 0; i < n; i++)
  {
    delete shapes[i];
  }
}
