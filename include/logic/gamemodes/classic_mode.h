//
// Created by soham on 11/27/2020.
//

#ifndef FINAL_PROJECT_CLASSIC_MODE_H
#define FINAL_PROJECT_CLASSIC_MODE_H

#include <logic/game_mode.h>

namespace breakout {
class ClassicMode : public GameMode {
 public:
  ci::Color GetBrickColor(size_t strength) override;
  size_t GetBrickStrength(size_t row_index, Brick& brick) override;
};
}  // namespace breakout
#endif  // FINAL_PROJECT_CLASSIC_MODE_H
