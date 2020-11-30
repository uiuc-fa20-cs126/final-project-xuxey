//
// Created by soham on 11/27/2020.
//

#ifndef FINAL_PROJECT_GAME_MODE_H
#define FINAL_PROJECT_GAME_MODE_H

#include <cinder/Color.h>
#include <objects/brick.h>
namespace breakout {
// Abstract class for game mode implementations
class GameMode {
 public:
  // Returns the brick color from the given strength
  virtual ci::Color GetBrickColor(size_t strength) const = 0;
  // Returns the brick strength from the given row index and Brick
  virtual size_t GetBrickStrength(size_t row_index,
                                  const Brick& brick) const = 0;
  // returns the name of the game mode
  virtual inline std::string GetName() const = 0;
  // Virtual Destructor
  virtual ~GameMode(){};
};
}  // namespace breakout
#endif  // FINAL_PROJECT_GAME_MODE_H
