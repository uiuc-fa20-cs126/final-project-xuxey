//
// Created by soham on 11/27/2020.
//

#ifndef FINAL_PROJECT_BRICK_SCHEMA_H
#define FINAL_PROJECT_BRICK_SCHEMA_H

#include <cinder/Color.h>
#include <objects/brick.h>
namespace breakout {
class BrickSchema {
 public:
  virtual ci::Color GetBrickColor(size_t strength) = 0;
  virtual size_t GetBrickStrength(size_t row_index, Brick& brick) = 0;
};
}  // namespace breakout
#endif  // FINAL_PROJECT_BRICK_SCHEMA_H
