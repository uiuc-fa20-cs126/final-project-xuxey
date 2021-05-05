#pragma once

#include <objects/ball.h>
#include <objects/brick.h>
#include <objects/plate.h>

#include <string>
#include <vector>

#include "cinder/audio/Voice.h"
#include "cinder/gl/gl.h"
#include "interface/ui_section.h"
#include "objects/brick.h"

namespace breakout {
// Game World
class World : public UISection {
  Ball ball_;
  std::vector<Brick> bricks_;
  Plate plate_;
  cinder::gl::Texture2dRef ball_texture;
  int score_ = 0;
  // Speed of the plate in pixels/frame
  const double kPlateSpeed = 18.0;
  // Number of rows of bricks
  const size_t kNumBrickRows = 5;
  // Speed of the ball in pixels/frame
  const double kBallSpeed = 5.0;
  // Score bonus after destroying all bricks
  const int kGameWinScoreBonus = 400;
  bool is_playing_ = true;
  static ci::audio::VoiceRef bounce_sound;
  // Helper methods
  void HandleWallCollision();
  void HandleBrickCollisions();
  void HandlePlateCollision();
  void HandleGameEnd();
  void PlaySound();

 public:
  World(const dvec2& bottom_left, const dvec2& top_right);
  World(const dvec2& bottom_left, const dvec2& top_right, Ball ball,
        std::vector<Brick> bricks);
  void Render() const override;
  void Update() override;
  void OnClick(glm::dvec2 relative_pos) override{};
  void OnKeyPress(ci::app::KeyEvent event) override;
  void Setup() override;
  // Getter for Ball
  const Ball& GetBall() const;
};

}  // namespace breakout
