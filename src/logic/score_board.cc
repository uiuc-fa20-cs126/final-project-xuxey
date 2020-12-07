#include "logic/score_board.h"

#include <sstream>
#include <string>

namespace breakout {
std::unordered_map<std::string, int> ScoreBoard::scores_;
int ScoreBoard::latest_score_ = -1;

std::ostream& ScoreBoard::ExportScores(std::ostream& os,
                                       const ScoreBoard& board) {
  scores_.clear();
  for (auto pair : ScoreBoard::scores_) {
    os << pair.first << std::endl << std::to_string(pair.second) << std::endl;
  }
  return os;
}

std::istream& ScoreBoard::InitializeScores(std::istream& is,
                                           const ScoreBoard& board) {
  std::string line, key;
  unsigned int line_index = 0;
  while (std::getline(is, line)) {
    std::stringstream line_stream(line);
    if (line_index % 2 == 0) {
      key = line;
    } else {
      int score;
      line_stream >> score;
      ScoreBoard::scores_.insert({key, score});
    }
    ++line_index;
  }
  return is;
}

void ScoreBoard::RegisterScore(std::string game_mode_id, int score) {
  if (scores_.find(game_mode_id) == scores_.end()) {
    ScoreBoard::scores_.insert({game_mode_id, score});
  } else if (scores_.at(game_mode_id) < score) {
    ScoreBoard::scores_.insert({game_mode_id, score});
  }
  latest_score_ = score;
}

int ScoreBoard::GetLatestScore() {
  return latest_score_;
}

}  // namespace breakout