//
// Created by soham on 11/19/2020.
//

#ifndef FINAL_PROJECT_BRICK_GEN_H
#define FINAL_PROJECT_BRICK_GEN_H

#include <logic/gamemodes/game_mode.h>
#include <objects/brick.h>

#include <vector>
namespace breakout {
// Brick Generator class for terrain generation
class BrickGen {
  // Padding between the bricks and rows in pixels
  constexpr static float kPadding = 20;
  // Average brick length in pixels
  constexpr static float kAvgBrickLength = 200;
  // Generates a row of bricks within the given constraints
  static std::vector<Brick> GenerateRow(int num_bricks, double brick_height,
                                        double row_length,
                                        dvec2 row_bottom_left,
                                        size_t brick_strength,
                                        GameMode* schema);

 public:
  // Generates a vector of bricks within the given constraints
  static std::vector<Brick> GenerateBricks(size_t num_rows, dvec2 top_right,
                                           dvec2 bottom_left, GameMode* schema);
};
}  // namespace breakout

#endif  // FINAL_PROJECT_BRICK_GEN_H
