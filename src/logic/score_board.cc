#include "logic/score_board.h"

#include <sstream>
#include <string>

namespace breakout {
std::unordered_map<std::string, int> ScoreBoard::scores_;

std::ostream& operator<<(std::ostream& os, const ScoreBoard& board) {
  for (auto pair : ScoreBoard::scores_) {
    os << pair.first << std::endl << std::to_string(pair.second) << std::endl;
  }
  return os;
}

std::istream& operator>>(std::istream& is, const ScoreBoard& board) {
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
}  // namespace breakout