#include "logic/gamemodes/easy_mode.h"

#include <glm/gtc/random.hpp>
#include <vector>

namespace breakout {

ci::Color EasyMode::GetBrickColor(size_t strength) const {
  std::vector<ci::Color> colors = {
      ci::Color("white"),     ci::Color("blueviolet"),
      ci::Color("lightgrey"), ci::Color("lightskyblue"),
      ci::Color("limegreen"), ci::Color("yellow"),
      ci::Color("orange"),    ci::Color("red")};
  int randomIndex = glm::linearRand(static_cast<size_t>(0), colors.size() - 1);
  return colors[randomIndex];
}

size_t EasyMode::GetBrickStrength(size_t row_index, const Brick& brick) const {
  return 1;
}

std::string EasyMode::GetName() const {
  return "Easy";
}
}  // namespace breakout