//
// Created by soham on 11/19/2020.
//

#ifndef FINAL_PROJECT_BRICK_H
#define FINAL_PROJECT_BRICK_H
#include <cinder/Color.h>

#include <glm/glm.hpp>
using glm::dvec2;

namespace breakout {
struct Brick {
  dvec2 top_right_;
  dvec2 bottom_left_;
  size_t strength = 1;
  ci::Color color_;
  Brick(const dvec2& topRight, const dvec2& bottomLeft, size_t strength,
        ci::Color color)
      : top_right_(topRight),
        bottom_left_(bottomLeft),
        strength(strength),
        color_(color) {
  }
  Brick(const dvec2& topRight, const dvec2& bottomLeft)
      : top_right_(topRight), bottom_left_(bottomLeft) {
  }
};
}  // namespace breakout

#endif  // FINAL_PROJECT_BRICK_H
