#include <objects/ball.h>
#include <sections/world.h>

namespace breakout {
const ci::Color Ball::color_ = ci::Color("blue");

const glm::dvec2& Ball::GetPos() const {
  return position_;
}

const glm::dvec2& Ball::GetVelocity() const {
  return velocity_;
}

Ball::Ball(const glm::dvec2& position, const glm::dvec2& velocity)
    : position_(position), velocity_(velocity) {
}

void Ball::UpdateNextPosition() {
  position_ += velocity_;
}

const glm::dvec2 Ball::GetNextPosition() const {
  return position_ + velocity_;
}

void Ball::InvertXVelocity() {
  velocity_.x = -velocity_.x;
}

void Ball::InvertYVelocity() {
  velocity_.y = -velocity_.y;
}

const cinder::Color& Ball::GetColor() const {
  return color_;
}

double Ball::GetRadius() const {
  return radius_;
}

Ball::Ball(Ball const& source) {
}
}  // namespace breakout