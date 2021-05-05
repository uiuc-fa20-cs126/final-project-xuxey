//
// Created by soham on 12/9/2020.
//

#ifndef FINAL_PROJECT_SCORE_VIEW_H
#define FINAL_PROJECT_SCORE_VIEW_H

#include <interface/ui_section.h>
namespace breakout {
class ScoreView : public UISection {
  dvec2 top_center_;

 public:
  ScoreView(dvec2 top_center);
  void Render() const override;
  void Update() override{};
};
}  // namespace breakout

#endif  // FINAL_PROJECT_SCORE_VIEW_H
