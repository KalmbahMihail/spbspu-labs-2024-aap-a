#include "base-types.hpp"
bocharov::point_t bocharov::scalePoint(bocharov::point_t p, bocharov::point_t pos, double ratio)
{
  p.x = (p.x - pos.x) * ratio + pos.x;
  p.y = (p.y - pos.y) * ratio + pos.y;
  return {p.x, p.y};
}

bocharov::point_t bocharov::movePoint(bocharov::point_t p, double x, double y)
{
  p.x += x;
  p.y += y;
  return {p.x, p.y};
}
