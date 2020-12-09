//
// Created by soham on 12/10/2020.
//

#ifndef FINAL_PROJECT_HARD_MODE_H
#define FINAL_PROJECT_HARD_MODE_H
#include <logic/gamemodes/game_mode.h>
namespace breakout {
// An easy mode with one-hit bricks
class HardMode : public GameMode {
 public:
  ci::Color GetBrickColor(size_t strength) const override;
  size_t GetBrickStrength(size_t row_index, const Brick& brick) const override;
  std::string GetName() const override;
};
}  // namespace breakout
#endif  // FINAL_PROJECT_HARD_MODE_H
