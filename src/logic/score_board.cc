#include "logic/score_board.h"

#include <sstream>
#include <string>

namespace breakout {
std::unordered_map<std::string, int> ScoreBoard::high_scores_;
int ScoreBoard::latest_score_ = 0;

std::ostream& ScoreBoard::ExportScores(std::ostream& os) {
  for (auto pair : ScoreBoard::high_scores_) {
    os << pair.first << std::endl << std::to_string(pair.second) << std::endl;
  }
  return os;
}

std::istream& ScoreBoard::InitializeScores(std::istream& is) {
  high_scores_.clear();
  std::string line, key;
  unsigned int line_index = 0;
  while (std::getline(is, line)) {
    std::stringstream line_stream(line);
    if (line_index % 2 == 0) {
      key = line;
    } else {
      int score;
      line_stream >> score;
      ScoreBoard::high_scores_.insert({key, score});
    }
    ++line_index;
  }
  return is;
}

void ScoreBoard::RegisterScore(std::string game_mode_id, int score) {
  if (high_scores_.find(game_mode_id) == high_scores_.end()) {
    high_scores_[game_mode_id] = score;
  } else if (high_scores_.at(game_mode_id) < score) {
    high_scores_[game_mode_id] = score;
  }
  latest_score_ = score;
}

int ScoreBoard::GetLatestScore() {
  return latest_score_;
}

const std::unordered_map<std::string, int>& ScoreBoard::GetHighScores() {
  return high_scores_;
}

}  // namespace breakout