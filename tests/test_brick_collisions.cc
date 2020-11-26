#include <logic/brick_gen.h>

#include <catch2/catch.hpp>

#include "objects/ball.h"
#include "sections/world.h"

using breakout::Ball;
using breakout::Brick;
using breakout::BrickGen;
using breakout::World;
using glm::dvec2;
typedef std::vector<breakout::Brick> bricks_vec;

TEST_CASE("Ball collides with brick wall") {
  std::vector<Brick> bricks;
  bricks.push_back(
      Brick(dvec2(1200, 650), dvec2(900, 600), 1, ci::Color("white")));
  SECTION("Ball colliding with top wall of brick") {
    dvec2 position(1000, 680.0);
    dvec2 velocity(2.0, -0.5);
    dvec2 expected_velocity(2.0, 0.5);
    dvec2 expected_position = position + expected_velocity;

    Ball ball(position, velocity);
    World world(dvec2(0, 1200), dvec2(2400, 0), ball, bricks);
    world.Update();

    REQUIRE(expected_velocity == world.GetBall().GetVelocity());
    REQUIRE(expected_position == world.GetBall().GetPos());
  }
  SECTION("Ball colliding with bottom wall of brick") {
    dvec2 position(1000, 570.0);
    dvec2 velocity(2.0, 0.5);
    dvec2 expected_velocity(2.0, -0.5);
    dvec2 expected_position = position + expected_velocity;

    Ball ball(position, velocity);
    World world(dvec2(0, 1200), dvec2(2400, 0), ball, bricks);
    world.Update();

    REQUIRE(expected_velocity == world.GetBall().GetVelocity());
    REQUIRE(expected_position == world.GetBall().GetPos());
  }
  SECTION("Ball colliding with left wall of brick") {
    dvec2 position(870, 625.0);
    dvec2 velocity(1.0, 2.0);
    dvec2 expected_velocity(-1.0, 2.0);
    dvec2 expected_position = position + expected_velocity;

    Ball ball(position, velocity);
    World world(dvec2(0, 1200), dvec2(2400, 0), ball, bricks);
    world.Update();

    REQUIRE(expected_velocity == world.GetBall().GetVelocity());
    REQUIRE(expected_position == world.GetBall().GetPos());
  }
  SECTION("Ball colliding with right wall of brick") {
    dvec2 position(1230, 625.0);
    dvec2 velocity(-2.0, 0.5);
    dvec2 expected_velocity(2.0, 0.5);
    dvec2 expected_position = position + expected_velocity;

    Ball ball(position, velocity);
    World world(dvec2(0, 1200), dvec2(2400, 0), ball, bricks);
    world.Update();

    REQUIRE(expected_velocity == world.GetBall().GetVelocity());
    REQUIRE(expected_position == world.GetBall().GetPos());
  }
}

TEST_CASE("Ball collides with brick corner") {
}