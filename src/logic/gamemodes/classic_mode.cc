//
// Created by soham on 11/27/2020.
//

#include <logic/gamemodes/classic_mode.h>

namespace breakout {

ci::Color ClassicMode::GetBrickColor(size_t strength) const {
  switch (strength) {
    case 1:
      return ci::Color("white");
    case 2:
      return ci::Color("yellow");
    case 3:
      return ci::Color("orange");
    default:
      return ci::Color("red");
  }
}
size_t ClassicMode::GetBrickStrength(size_t row_index,
                                     const Brick& brick) const {
  switch (row_index) {
    case 0:
    case 1:
      return 1;
    case 2:
    case 3:
      return 2;
    case 4:
      return 3;
    default:
      return 3;
  }
}

std::string ClassicMode::GetName() const {
  return "classic";
}
}  // namespace breakout