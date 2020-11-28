#include <interface/breakout_app.h>
#include <logic/brick_gen.h>
#include <logic/classic_schema.h>
#include <sections/world.h>

#include <glm/gtc/random.hpp>

namespace breakout {

using glm::dvec2;

void World::Render() const {
  // Render Background
  ci::gl::color(ci::Color("black"));
  ci::gl::drawSolidRect(ci::Rectf(bottom_left_, top_right_));
  // Render Ball
  ci::gl::color(ci::Color(ball_.GetColor()));
  ci::gl::drawSolidCircle(GetActualPos(ball_.GetPos()),
                          static_cast<float>(ball_.GetRadius()));
  // Render Bricks
  for (const Brick& brick : bricks_) {
    ci::gl::color(brick.color_);
    ci::gl::drawStrokedRect(ci::Rectf(GetActualPos(brick.bottom_left_),
                                      GetActualPos(brick.top_right_)),
                            5);
  }
  // Render Plate
  ci::gl::color(ci::Color(ci::Color("white")));
  ci::gl::drawSolidRect(ci::Rectf(
      GetActualPos(plate_.bottom_left),
      GetActualPos(plate_.bottom_left + dvec2(plate_.length_, plate_.kWidth))));
}

void World::Update() {
  if (is_playing_) {
    HandlePlateCollision();
    HandleWallCollision();
    HandleBrickCollisions();
    ball_.UpdateNextPosition();
  }
}

World::World(const dvec2& bottom_left, const dvec2& top_right) {
  bottom_left_ = bottom_left;
  top_right_ = top_right;
  InitializeObjects();
}

World::World(const dvec2& bottom_left, const dvec2& top_right, Ball ball) {
  // todo remove
  bottom_left_ = bottom_left;
  top_right_ = top_right;
  InitializeObjects();
  ball_ = ball;
}

World::World(const dvec2& bottom_left, const dvec2& top_right, Ball ball,
             std::vector<Brick> bricks) {
  bottom_left_ = bottom_left;
  top_right_ = top_right;
  InitializeObjects();
  ball_ = ball;
  bricks_ = bricks;
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
  // bottom wall
  if (y_position >= bottom_left_.y - top_right_.y - ball_.GetRadius()) {
    if (ball_.GetVelocity().y > 0) {
      HandleGameEnd();
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

void World::InitializeObjects() {
  double length = top_right_.x - bottom_left_.x;
  double height = bottom_left_.y - top_right_.y;
  ClassicSchema schema;
  // Initialize Bricks
  bricks_ = BrickGen::GenerateBricks(kNumBrickRows, dvec2(length, height / 5),
                                     dvec2(0, height / 2), schema);
  // Initialize Plate
  plate_.bottom_left.x = ((length - plate_.length_) / 2);
  plate_.bottom_left.y = height - height / 40;
  // Initialize Ball
  glm::dvec2 midpoint(length / 2, height - (height / 25));
  ball_ = Ball(midpoint,
               dvec2(glm::linearRand(-kBallSpeed, kBallSpeed), -kBallSpeed));
}

void World::OnKeyPress(ci::app::KeyEvent event) {
  dvec2 plate_pos = GetActualPos(plate_.bottom_left);
  switch (event.getCode()) {
    case ci::app::KeyEvent::KEY_LEFT:
    case ci::app::KeyEvent::KEY_a:
      if (plate_pos.x - kPlateSpeed > bottom_left_.x) {
        plate_.bottom_left.x -= kPlateSpeed;
      }
      break;
    case ci::app::KeyEvent::KEY_RIGHT:
    case ci::app::KeyEvent::KEY_d:
      if (plate_pos.x + plate_.length_ + kPlateSpeed < top_right_.x) {
        plate_.bottom_left.x += kPlateSpeed;
      }
      break;
  }
}

void World::HandleBrickCollisions() {
  dvec2 ball_pos = GetActualPos(ball_.GetPos());
  auto brick_iterator = bricks_.begin();
  for (Brick& brick : bricks_) {
    bool flipX = false;
    bool flipY = false;
    dvec2 nearest_edge = ball_pos;
    dvec2 brick_top_right = GetActualPos(brick.top_right_);
    dvec2 brick_bottom_left = GetActualPos(brick.bottom_left_);

    if (ball_pos.x < brick_bottom_left.x) {
      nearest_edge.x = brick_bottom_left.x;
      flipX = true;
    }  // left edge
    else if (ball_pos.x > brick_top_right.x) {
      nearest_edge.x = brick_top_right.x;
      flipX = true;
    }  // right edge
    if (ball_pos.y < brick_top_right.y) {
      nearest_edge.y = brick_top_right.y;
      flipY = true;
    }  // top edge
    else if (ball_pos.y > brick_bottom_left.y) {
      nearest_edge.y = brick_bottom_left.y;
      flipY = true;
    }  // bottom edge

    if (glm::distance(nearest_edge, ball_pos) <= ball_.GetRadius()) {
      if (flipX) {
        ball_.InvertXVelocity();
      }
      if (flipY) {
        ball_.InvertYVelocity();
      }
      --brick.strength;
      if (brick.strength == 0) {
        bricks_.erase(brick_iterator);
        break;
      }
      brick.color_ = ClassicSchema().GetBrickColor(brick.strength);
    }
    brick_iterator++;
  }
}

void World::HandlePlateCollision() {
  if (ball_.GetPos().x > plate_.bottom_left.x &&
      ball_.GetPos().x < plate_.bottom_left.x + plate_.length_ &&
      ball_.GetVelocity().y > 0 &&
      plate_.bottom_left.y + plate_.kWidth - ball_.GetPos().y <=
          ball_.GetRadius()) {
    double plate_center_x = plate_.bottom_left.x + (plate_.length_ / 2);
    double direction_weight =
        (ball_.GetPos().x - plate_center_x) / (plate_.length_ / 2);
    ball_.SetVelocity(
        dvec2(direction_weight * kBallSpeed, -ball_.GetVelocity().y));
  }
}

void World::HandleGameEnd() {
  InitializeObjects();
  UserInterface::active_screen_id_ = "home_screen";
}
}  // namespace breakout