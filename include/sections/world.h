#pragma once

#include <objects/ball.h>
#include <objects/brick.h>

#include <string>
#include <vector>

#include "cinder/gl/gl.h"
#include "interface/ui_section.h"
#include "objects/brick.h"

namespace breakout {
class World : public UISection {
  Ball ball_;
  std::vector<Brick> bricks_;
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
