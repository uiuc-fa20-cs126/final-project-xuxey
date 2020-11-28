//
// Created by soham on 11/27/2020.
//

#include <logic/classic_schema.h>

namespace breakout {

ci::Color ClassicSchema::GetBrickColor(size_t strength) {
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
size_t ClassicSchema::GetBrickStrength(size_t row_index, Brick& brick) {
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
}  // namespace breakout