//
// Created by soham on 11/8/2020.
//

#ifndef IDEAL_GAS_LAYOUT_H
#define IDEAL_GAS_LAYOUT_H

#include <interface/breakout_app.h>

#include <glm/glm.hpp>
using glm::dvec2;
namespace breakout {
/**
 * Struct containing all layout coordinates as constants
 */
struct Layout {
  // Dimensions of the square window in pixels
  constexpr static double kWindowHeight = 1200;
  // Margin size from the container edge to window edge in pixels
  constexpr static double kMargin = 100;
  static const dvec2 container_bottom_left_;
  static const dvec2 container_top_right_;
};
}  // namespace breakout

#endif  // IDEAL_GAS_LAYOUT_H
