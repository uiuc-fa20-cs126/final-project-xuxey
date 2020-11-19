#include <interface/breakout_app.h>
#include <logic/brick_gen.h>
#include <objects/brick.h>
#include <sections/world.h>

#include <glm/gtc/random.hpp>
#include <vector>

namespace breakout {

using glm::dvec2;

void World::Render() const {
  // Draw Background
  ci::gl::color(ci::Color("black"));
  ci::gl::drawSolidRect(ci::Rectf(bottom_left_, top_right_));
  // Draw Ball
  ci::gl::color(ci::Color(ball_.GetColor()));
  ci::gl::drawSolidCircle(GetActualPos(ball_.GetPos()),
                          static_cast<float>(ball_.GetRadius()));
  for (Brick brick : bricks_) {
    ci::gl::color(brick.color);
    ci::gl::drawStrokedRect(ci::Rectf(GetActualPos(brick.bottom_left_),
                                      GetActualPos(brick.top_right_)),
                            5);
  }
}

void World::Update() {
  if (is_playing_) {
    HandleWallCollision();
    ball_.UpdateNextPosition();
  }
}

World::World(const dvec2& bottom_left, const dvec2& top_right) {
  bottom_left_ = bottom_left;
  top_right_ = top_right;
  glm::dvec2 midpoint((top_right_.x - bottom_left_.x) / 2, 300);
  ball_ = Ball(midpoint, glm::dvec2(5.0, -5.0));
  InitializeBricks(bottom_left, top_right);
}

World::World(const dvec2& bottom_left, const dvec2& top_right, Ball ball) {
  bottom_left_ = bottom_left;
  top_right_ = top_right;
  ball_ = ball;
  InitializeBricks(bottom_left, top_right);
}

void World::TogglePlayPause() {
  is_playing_ = !is_playing_;
}

void World::HandleWallCollision() {
  double x_position = ball_.GetNextPosition().x;
  double y_position = ball_.GetNextPosition().y;
  // top wall
  if (y_position <= ball_.GetRadius()) {
    if (ball_.GetVelocity().y < 0) {
      ball_.InvertYVelocity();
    }
  }
  if (y_position >= bottom_left_.y - top_right_.y - ball_.GetRadius()) {
    if (ball_.GetVelocity().y > 0) {
      is_playing_ = false;
    }
  }
  // right wall
  if (x_position >= top_right_.x - bottom_left_.x - ball_.GetRadius()) {
    if (ball_.GetVelocity().x > 0) {
      ball_.InvertXVelocity();
    }
  }
  // left wall
  if (x_position <= ball_.GetRadius()) {
    if (ball_.GetVelocity().x < 0) {
      ball_.InvertXVelocity();
    }
  }
}
const Ball& World::GetBall() const {
  return ball_;
}

void World::InitializeBricks(const dvec2& bottom_left, const dvec2& top_right) {
  double length = top_right.x - bottom_left.x;
  double height = bottom_left.y - top_right.y;
  bricks_ = BrickGen::GenerateBricks(kNumBrickRows, dvec2(length, 200),
                                     dvec2(0, height - 500), kBrickStrength);
}
}  // namespace breakout