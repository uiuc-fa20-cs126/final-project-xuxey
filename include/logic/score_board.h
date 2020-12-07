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
  static int latest_score_;

 public:
  static std::ostream& ExportScores(std::ostream& os, const ScoreBoard& board);
  static std::istream& InitializeScores(std::istream& os,
                                        const ScoreBoard& board);
  static int GetLatestScore();
  static void RegisterScore(std::string game_mode_id, int score);
};
}  // namespace breakout

#endif  // FINAL_PROJECT_SCORE_BOARD_H
