//
// Created by soham on 11/27/2020.
//

#ifndef FINAL_PROJECT_CLASSIC_MODE_H
#define FINAL_PROJECT_CLASSIC_MODE_H

#include <logic/gamemodes/game_mode.h>

namespace breakout {
class ClassicMode : public GameMode {
 public:
  ci::Color GetBrickColor(size_t strength) const override;
  size_t GetBrickStrength(size_t row_index, const Brick& brick) const override;
  std::string GetName() const override;
};
}  // namespace breakout
#endif  // FINAL_PROJECT_CLASSIC_MODE_H
