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
  const size_t kNumBrickRows = 5;
  const double kBallSpeed = 5.0;
  bool is_playing_ = true;
  // ------------------
  void HandleWallCollision();
  void HandleBrickCollisions();
  void HandleGameEnd();
 public:
  World(const dvec2& bottom_left, const dvec2& top_right);
  World(const dvec2& bottom_left, const dvec2& top_right, Ball ball,
        std::vector<Brick> bricks);
  void Render() const override;
  void Update() override;
  void OnClick(glm::dvec2 relative_pos) override{};
  void OnKeyPress(ci::app::KeyEvent event) override;
  const Ball& GetBall() const;
  void HandlePlateCollision();
  void Setup() override;
};

}  // namespace breakout
