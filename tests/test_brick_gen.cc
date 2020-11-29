#include <logic/brick_gen.h>
#include <logic/gamemodes/classic_mode.h>

#include <catch2/catch.hpp>

using breakout::Brick;
using breakout::BrickGen;
using glm::dvec2;
typedef std::vector<breakout::Brick> bricks_vec;

TEST_CASE("Brick generator generates correct number of rows") {
  breakout::ClassicMode game_mode;
  SECTION("Single row") {
    dvec2 top_right(100, 10);
    dvec2 bottom_left(10, 100);
    bricks_vec bricks =
        BrickGen::GenerateBricks(1, top_right, bottom_left, game_mode);

    for (Brick brick : bricks) {
      REQUIRE(brick.bottom_left_.y == bottom_left.y);
      REQUIRE(brick.top_right_.y == top_right.y);
    }
  }
  SECTION("Two rows") {
    dvec2 top_right(100, 10);
    dvec2 bottom_left(10, 100);
    bricks_vec bricks =
        BrickGen::GenerateBricks(2, top_right, bottom_left, game_mode);

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
        BrickGen::GenerateBricks(3, top_right, bottom_left, game_mode);

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
}

TEST_CASE("All bricks have the correct strength") {
  breakout::ClassicMode game_mode;
  dvec2 top_right(100, 0);
  dvec2 bottom_left(0, 100);
  bricks_vec bricks =
      BrickGen::GenerateBricks(3, top_right, bottom_left, game_mode);

  for (Brick brick : bricks) {
    REQUIRE(brick.strength == 3);
  }
}
