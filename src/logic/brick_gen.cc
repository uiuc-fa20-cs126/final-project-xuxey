#include <cinder/Rand.h>
#include <logic/brick_gen.h>

#include <vector>

namespace breakout {
std::vector<Brick> WallGen::GenerateWall(size_t num_rows, dvec2 top_right,
                                         dvec2 bottom_left,
                                         GameMode* game_mode) {
  // Filter/Sanitize constraints
  double row_length = top_right.x - bottom_left.x;
  double total_height = bottom_left.y - top_right.y;
  int num_bricks =
      static_cast<int>((row_length - kPadding) / (kAvgBrickLength + kPadding));
  double brick_height = (total_height - ((num_rows - 1) * kPadding)) / num_rows;
  dvec2 row_bottom_left = bottom_left + dvec2(kPadding, 0);
  // Generate Wall
  std::vector<Brick> wall;
  wall.reserve(num_bricks * num_rows);
  for (size_t row_index = 0; row_index < num_rows; row_index++) {
    std::vector<Brick> row =
        GenerateRow(num_bricks, brick_height, row_length - (2 * kPadding),
                    row_bottom_left, row_index, game_mode);
    // Insert all bricks from the row into the wall
    wall.insert(wall.end(), row.begin(), row.end());
    row_bottom_left += dvec2(0, -(brick_height + kPadding));
  }
  return wall;
}

std::vector<Brick> WallGen::GenerateRow(int num_bricks, double brick_height,
                                        double row_length,
                                        dvec2 row_bottom_left, size_t row_index,
                                        GameMode* game_mode) {
  std::vector<Brick> bricks;
  double remaining_length = row_length;
  dvec2 brick_bottom_left = row_bottom_left;

  for (int i = 1; i < num_bricks; ++i) {
    // Generate random brick length
    double random_length =
        kAvgBrickLength +
        ci::Rand::randPosNegFloat(
            0, kAvgBrickLength *
                   (static_cast<float>(remaining_length / (2 * row_length))));
    dvec2 brick_top_right =
        brick_bottom_left + dvec2(random_length, -brick_height);
    // Create and push brick
    Brick brick(brick_top_right, brick_bottom_left);
    brick.strength = game_mode->GetBrickStrength(row_index, brick);
    brick.color_ = game_mode->GetBrickColor(brick.strength);
    bricks.push_back(brick);
    // Update fields for next brick
    brick_bottom_left += dvec2(random_length + kPadding, 0);
    remaining_length -= random_length + kPadding;
  }
  // Create and push final brick (for constant top right corner across rows)
  Brick brick(row_bottom_left + dvec2(row_length, -brick_height),
              brick_bottom_left);
  brick.strength = game_mode->GetBrickStrength(row_index, brick);
  brick.color_ = game_mode->GetBrickColor(brick.strength);
  bricks.push_back(brick);
  return bricks;
}
}  // namespace breakout