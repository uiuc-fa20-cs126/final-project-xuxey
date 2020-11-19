#pragma once

#include <objects/ball.h>
#include <objects/brick.h>
#include <objects/plate.h>

#include <string>
#include <vector>

#include "cinder/gl/gl.h"
#include "interface/ui_section.h"
#include "objects/brick.h"

namespace breakout {
class World : public UISection {
  Ball ball_;
  std::vector<Brick> bricks_;
  Plate plate_;

  const double kPlateSpeed = 18.0;
  const size_t kBrickStrength = 1;
  const size_t kNumBrickRows = 5;
  bool is_playing_ = true;
  // ------------------
  void HandleWallCollision();
  void InitializeObjects(const dvec2& bottom_left, const dvec2& top_right);

 public:
  World(const dvec2& bottom_left, const dvec2& top_right);
  World(const dvec2& bottom_left, const dvec2& top_right, Ball ball);
  void TogglePlayPause();
  void Render() const override;
  void Update() override;
  void OnClick(glm::dvec2 relative_pos) override{};
  void OnKeyPress(ci::app::KeyEvent event) override;
  const Ball& GetBall() const;
};

}  // namespace breakout
