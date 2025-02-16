#ifndef SHAPE_HPP
#define SHAPE_HPP
#include "base-types.hpp"

namespace zakirov
{
  struct Shape
  {
    public:
      virtual ~Shape() = default;
      virtual double getArea() const = 0;
      virtual rectangle_t getFrameRect() const = 0;
      virtual void move(const point_t & target) = 0;
      virtual void move(double bias_x, double bias_y) = 0;
      virtual void scale_without_check(double k) noexcept = 0;
      void scale_with_check(double k);
      virtual Shape * clone() const = 0;
  };
}

#endif
