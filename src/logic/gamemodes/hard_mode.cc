#include "logic/gamemodes/hard_mode.h"

#include <glm/gtc/random.hpp>
#include <vector>

namespace breakout {

ci::Color HardMode::GetBrickColor(size_t strength) const {
  return ci::Color("red");
}

size_t HardMode::GetBrickStrength(size_t row_index, const Brick& brick) const {
  return 3;
}

std::string HardMode::GetName() const {
  return "Hard";
}
}  // namespace breakout