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
  // Top Instructions
  static const dvec2 top_instructions_;
  // Bottom Instructions
  static const dvec2 bottom_instructions_;
  // Gas Container
  static const dvec2 container_bottom_left_;
  static const dvec2 container_top_right_;
  // Clear Button
  static const dvec2 clear_bottom_left_;
  static const dvec2 clear_top_right_;
  // Blue Button
  static const dvec2 blue_btn_bottom_left_;
  static const dvec2 blue_btn_top_right_;
  // Cyan Button
  static const dvec2 cyan_btn_bottom_left_;
  static const dvec2 cyan_btn_top_right_;
  // Aqua Button
  static const dvec2 aqua_btn_bottom_left_;
  static const dvec2 aqua_btn_top_right_;
  // Aqua Histogram
  static const dvec2 aqua_graph_bottom_left_;
  static const dvec2 aqua_graph_top_right_;
  // Cyan Histogram
  static const dvec2 cyan_graph_bottom_left_;
  static const dvec2 cyan_graph_top_right_;
  // Blue Histogram
  static const dvec2 blue_graph_bottom_left_;
  static const dvec2 blue_graph_top_right_;
};
}  // namespace breakout

#endif  // IDEAL_GAS_LAYOUT_H
