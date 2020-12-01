#include <logic/brick_gen.h>
#include <logic/gamemodes/classic_mode.h>
#include <logic/gamemodes/easy_mode.h>

#include <catch2/catch.hpp>

using breakout::Brick;
using breakout::WallGen;
using glm::dvec2;
typedef std::vector<breakout::Brick> bricks_vec;

TEST_CASE("Brick generator generates correct number of rows") {
  breakout::GameMode* game_mode = new breakout::ClassicMode();
  SECTION("Single row") {
    dvec2 top_right(100, 10);
    dvec2 bottom_left(10, 100);
    bricks_vec bricks =
        WallGen::GenerateWall(1, top_right, bottom_left, game_mode);

    for (Brick brick : bricks) {
      REQUIRE(brick.bottom_left_.y == bottom_left.y);
      REQUIRE(brick.top_right_.y == top_right.y);
    }
  }
  SECTION("Two rows") {
    dvec2 top_right(100, 10);
    dvec2 bottom_left(10, 100);
    bricks_vec bricks =
        WallGen::GenerateWall(2, top_right, bottom_left, game_mode);

    bool top_row_exists = false;
    bool bottom_row_exists = false;
    for (Brick brick : bricks) {
      if (brick.bottom_left_.y == bottom_left.y) {
        bottom_row_exists = true;
      }
      if (brick.top_right_.y == top_right.y) {
        top_row_exists = true;
      }
    }
    REQUIRE(top_row_exists);
    REQUIRE(bottom_row_exists);
  }
  SECTION("Multiple rows") {
    dvec2 top_right(100, 0);
    dvec2 bottom_left(0, 100);
    bricks_vec bricks =
        WallGen::GenerateWall(3, top_right, bottom_left, game_mode);

    bool top_row_exists = false;
    bool bottom_row_exists = false;
    bool middle_row_exists = false;
    for (Brick brick : bricks) {
      if (brick.bottom_left_.y == bottom_left.y) {
        bottom_row_exists = true;
      }
      if (brick.top_right_.y == top_right.y) {
        top_row_exists = true;
      }
      if (brick.top_right_.y == Approx(40)) {
        middle_row_exists = true;
      }
    }
    REQUIRE(top_row_exists);
    REQUIRE(bottom_row_exists);
    REQUIRE(middle_row_exists);
  }
  delete game_mode;
}

TEST_CASE("All bricks have the correct strength") {
  breakout::GameMode* game_mode = new breakout::EasyMode();
  dvec2 top_right(100, 0);
  dvec2 bottom_left(0, 100);
  bricks_vec bricks =
      WallGen::GenerateWall(3, top_right, bottom_left, game_mode);

  for (Brick brick : bricks) {
    REQUIRE(brick.strength == 1);
  }
  delete game_mode;
}
