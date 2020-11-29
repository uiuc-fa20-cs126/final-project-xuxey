#include "logic/gamemodes/easy_mode.h"

#include <glm/gtc/random.hpp>
#include <vector>

namespace breakout {

ci::Color EasyMode::GetBrickColor(size_t strength) {
  std::vector<ci::Color> colors = {ci::Color("white"), ci::Color("orange"),
                                   ci::Color("red"), ci::Color("green"),
                                   ci::Color("darkcyan")};
  int randomIndex = glm::linearRand(static_cast<size_t>(0), colors.size() - 1);
  return colors[randomIndex];
}

size_t EasyMode::GetBrickStrength(size_t row_index, Brick& brick) {
  return 1;
}
}  // namespace breakout