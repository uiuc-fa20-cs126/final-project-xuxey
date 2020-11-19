//
// Created by soham on 11/19/2020.
//

#ifndef FINAL_PROJECT_BRICK_GEN_H
#define FINAL_PROJECT_BRICK_GEN_H

#include <objects/brick.h>

#include <vector>
namespace breakout {
class BrickGen {
  constexpr static float kPadding = 20;
  constexpr static float kAvgBrickLength = 250;
  static std::vector<Brick> GenerateRow(int num_bricks, double brick_height,
                                        double row_length,
                                        dvec2 row_bottom_left,
                                        size_t brick_strength);

 public:
  static std::vector<Brick> GenerateBricks(size_t num_rows, dvec2 top_right,
                                           dvec2 bottom_left,
                                           size_t max_brick_strength);
  static const float GetKPadding();
  static const float getKMinBrickLength();
};
}  // namespace breakout

#endif  // FINAL_PROJECT_BRICK_GEN_H