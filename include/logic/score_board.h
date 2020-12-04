//
// Created by soham on 12/5/2020.
//

#ifndef FINAL_PROJECT_SCORE_BOARD_H
#define FINAL_PROJECT_SCORE_BOARD_H

#include <ostream>
#include <unordered_map>

namespace breakout {
class ScoreBoard {
  static std::unordered_map<std::string, int> scores_;

 public:
  friend std::ostream& operator<<(std::ostream& os, const ScoreBoard& board);
  friend std::istream& operator>>(std::istream& os, const ScoreBoard& board);
};
}  // namespace breakout

#endif  // FINAL_PROJECT_SCORE_BOARD_H
