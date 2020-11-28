//
// Created by soham on 11/27/2020.
//

#ifndef FINAL_PROJECT_CLASSIC_SCHEMA_H
#define FINAL_PROJECT_CLASSIC_SCHEMA_H

#include <logic/brick_schema.h>

namespace breakout {
class ClassicSchema : public BrickSchema {
 public:
  ci::Color GetBrickColor(size_t strength) override;
  size_t GetBrickStrength(size_t row_index, Brick& brick) override;
};
}  // namespace breakout
#endif  // FINAL_PROJECT_CLASSIC_SCHEMA_H
