#include <cinder/Rand.h>
#include <logic/brick_gen.h>
#include <objects/brick.h>

#include <vector>

namespace breakout {
std::vector<Brick> BrickGen::GenerateBricks(size_t num_rows, dvec2 top_right,
                                            dvec2 bottom_left,
                                            size_t max_brick_strength) {
  std::vector<Brick> bricks;
  double row_length = top_right.x - bottom_left.x;
  double total_height = bottom_left.y - top_right.y;
  int num_bricks =
      static_cast<int>((row_length - kPadding) / (kAvgBrickLength + kPadding));
  double brick_height = (total_height - ((num_rows - 1) * kPadding)) / num_rows;
  // preallocate memory
  bricks.reserve(num_bricks * num_rows);
  dvec2 row_bottom_left = bottom_left + dvec2(kPadding, 0);
  for (size_t i = 0; i < num_rows; i++) {
    // Build row
    std::vector<Brick> row =
        GenerateRow(num_bricks, brick_height, row_length - (2 * kPadding),
                    row_bottom_left, max_brick_strength);
    bricks.insert(bricks.end(), row.begin(), row.end());
    row_bottom_left += dvec2(0, -(brick_height + kPadding));
  }
  return bricks;
}

std::vector<Brick> BrickGen::GenerateRow(int num_bricks, double brick_height,
                                         double row_length,
                                         dvec2 row_bottom_left,
                                         size_t brick_strength) {
  std::vector<Brick> bricks;
  float max_stretch = static_cast<float>((row_length / (2 * num_bricks)));
  dvec2 brick_bottom_left = row_bottom_left;
  for (int i = 1; i < num_bricks; ++i) {
    double random_length = static_cast<double>(
        kAvgBrickLength + ci::Rand::randPosNegFloat(0, max_stretch));
    dvec2 brick_top_right =
        brick_bottom_left + dvec2(random_length, -brick_height);
    Brick brick(brick_top_right, brick_bottom_left, brick_strength,
                ci::Color("white"));
    bricks.push_back(brick);
    brick_bottom_left += dvec2(random_length + kPadding, 0);
  }
  Brick brick(row_bottom_left + dvec2(row_length, -brick_height),
              brick_bottom_left, brick_strength, ci::Color("white"));
  bricks.push_back(brick);
  return bricks;
}
const float BrickGen::GetKPadding() {
  return kPadding;
}
const float BrickGen::getKMinBrickLength() {
  return kAvgBrickLength;
}
}  // namespace breakout