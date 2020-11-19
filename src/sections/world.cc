#include <interface/breakout_app.h>
#include <sections/world.h>

#include <glm/gtc/random.hpp>

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
}

World::World(const dvec2& bottom_left, const dvec2& top_right, Ball ball) {
  bottom_left_ = bottom_left;
  top_right_ = top_right;
  ball_ = ball;
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
  // todo remove bottom wall
  if (y_position >= bottom_left_.y - top_right_.y - ball_.GetRadius()) {
    if (ball_.GetVelocity().y > 0) {
      ball_.InvertYVelocity();
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
}  // namespace breakout