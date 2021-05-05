//
// Created by soham on 11/20/2020.
//

#ifndef FINAL_PROJECT_PLATE_H
#define FINAL_PROJECT_PLATE_H
#include <glm/detail/type_vec2.hpp>
#include <glm/fwd.hpp>
namespace breakout {
struct Plate {
  // Bottom left coordinate, origin bottom left relative to world
  glm::dvec2 bottom_left;
  // Length of the plate
  unsigned int length_ = 300;
  // Vertical width of the plate
  const unsigned int kWidth = 5;
};
}  // namespace breakout

#endif  // FINAL_PROJECT_PLATE_H
