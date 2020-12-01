#include <catch2/catch.hpp>

#include "objects/ball.h"
#include "sections/world.h"

using breakout::Ball;
using breakout::World;
using glm::dvec2;

TEST_CASE("Ball collides with walls", "[walls]") {
  std::vector<breakout::Brick> empty_bricks;
  SECTION("Ball collides with top wall") {
    dvec2 position(500.0, 30.0);
    dvec2 velocity(0.7, -1.0);
    dvec2 expected_velocity(0.7, 1.0);
    dvec2 expected_position = position + expected_velocity;

    Ball ball(position, velocity);
    World world(dvec2(0, 1000), dvec2(1000, 0), ball, empty_bricks);

    world.Update();
    REQUIRE(world.GetBall().GetVelocity() == expected_velocity);
    REQUIRE(world.GetBall().GetPos() == expected_position);

    SECTION("Ball velocity is unchanged when moving away") {
      world.Update();
      REQUIRE(world.GetBall().GetVelocity() == expected_velocity);
      REQUIRE(world.GetBall().GetPos() ==
              expected_position + expected_velocity);
    }
  }
  SECTION("Ball collides with left wall") {
    dvec2 position(30.0, 50.0);
    dvec2 velocity(-0.7, -0.5);
    dvec2 expected_velocity(0.7, -0.5);
    dvec2 expected_position = position + expected_velocity;

    Ball ball(position, velocity);
    World world(dvec2(0, 100), dvec2(100, 0), ball, empty_bricks);

    world.Update();
    REQUIRE(world.GetBall().GetVelocity() == expected_velocity);
    REQUIRE(world.GetBall().GetPos() == expected_position);

    SECTION("Ball velocity is unchanged when moving away") {
      world.Update();
      REQUIRE(world.GetBall().GetVelocity() == expected_velocity);
      REQUIRE(world.GetBall().GetPos() ==
              expected_position + expected_velocity);
    }
  }
  SECTION("Ball collides with right wall") {
    dvec2 position(70.0, 50.0);
    dvec2 velocity(0.7, -0.5);
    dvec2 expected_velocity(-0.7, -0.5);
    dvec2 expected_position = position + expected_velocity;

    Ball ball(position, velocity);
    World world(dvec2(0, 100), dvec2(100, 0), ball, empty_bricks);

    world.Update();
    REQUIRE(world.GetBall().GetVelocity() == expected_velocity);
    REQUIRE(world.GetBall().GetPos() == expected_position);

    SECTION("Ball velocity is unchanged when moving away") {
      world.Update();
      REQUIRE(world.GetBall().GetVelocity() == expected_velocity);
      REQUIRE(world.GetBall().GetPos() ==
              expected_position + expected_velocity);
    }
  }

  SECTION("Ball collides into a corner") {
    dvec2 position(29.5, 29.9);
    dvec2 velocity(-0.7, -0.5);
    dvec2 expected_velocity(0.7, 0.5);
    dvec2 expected_position = position + expected_velocity;

    Ball ball(position, velocity);
    World world(dvec2(0, 1000), dvec2(1000, 0), ball, empty_bricks);

    world.Update();
    REQUIRE(world.GetBall().GetVelocity() == expected_velocity);
    REQUIRE(world.GetBall().GetPos() == expected_position);
  }
}

TEST_CASE("Ball not colliding") {
  std::vector<breakout::Brick> empty_bricks;
  dvec2 position(50.0, 50.0);
  dvec2 velocity(0.7, -0.5);

  Ball ball(position, velocity);
  World world(dvec2(0, 100), dvec2(100, 0), ball, empty_bricks);

  world.Update();
  REQUIRE(world.GetBall().GetVelocity() == velocity);
  REQUIRE(world.GetBall().GetPos() == position + velocity);
}