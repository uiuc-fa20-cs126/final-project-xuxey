//
// Created by soham on 12/9/2020.
//

#include "sections/score_view.h"

#include <interface/breakout_app.h>
#include <logic/score_board.h>

namespace breakout {
void ScoreView::Render() const {
  dvec2 center = top_center_;
  ci::gl::drawStringCentered("High Scores", center, ci::Color("aqua"),
                             BreakoutApp::GetSecondaryFont());
  center += dvec2(0, BreakoutApp::GetSecondaryFont().getSize() * 2.5);
  for (auto pair : ScoreBoard::GetHighScores()) {
    ci::gl::drawStringCentered(pair.first + " - " + std::to_string(pair.second),
                               center, ci::Color("white"),
                               BreakoutApp::GetSecondaryFont());
    center += dvec2(0, BreakoutApp::GetSecondaryFont().getSize() * 2.5);
  }
}

ScoreView::ScoreView(dvec2 top_center) {
  top_center_ = top_center;
}
}  // namespace breakout
