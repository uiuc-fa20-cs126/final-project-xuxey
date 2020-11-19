#pragma once

#include <objects/ball.h>

#include <string>

#include "cinder/gl/gl.h"
#include "interface/ui_section.h"

namespace breakout {
class World : public UISection {
  Ball ball_;
  // todo vector of blocks
  bool is_playing_ = true;
  void HandleWallCollision();

 public:
  World(const dvec2& bottom_left, const dvec2& top_right);
  World(const dvec2& bottom_left, const dvec2& top_right, Ball ball);
  void TogglePlayPause();
  void Render() const override;
  void Update() override;
  void OnClick(glm::dvec2 relative_pos) override{};
  const Ball& GetBall() const;
};

}  // namespace breakout
