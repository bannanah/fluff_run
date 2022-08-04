//
// Created by banna on 4/18/2021.
//

#include <catch2/catch.hpp>

#include "game_engine.h"
#include "runner.h"
#include "obstacle.h"

namespace fluffrun {

TEST_CASE("Position updates") {
  SECTION("Runner (stationary)") {
    GameEngine game;
    game.AdvanceOneFrame();
    REQUIRE(game.GetRunner().GetPosition() == vec2(50, 350));
  }
  
  SECTION("Runner (post-jump)") {
    GameEngine game;
    game.Jump();
    game.AdvanceOneFrame();
    REQUIRE(game.GetRunner().GetPosition() == vec2(50, 345));
  }
  
  SECTION("Obstacle") {
    std::vector<Obstacle> obstacles = {Obstacle(vec2(910, 350), 30, 10)};
    Runner runner = Runner(vec2(50, 350), vec2(0,0), "cat", 20);
    GameEngine game = GameEngine(runner, obstacles);
    
    game.AdvanceOneFrame();
    
    REQUIRE(game.GetObstacles().at(0).GetPosition() == vec2(907, 350));
  }
}

TEST_CASE("Runner velocity") {
  SECTION("Jumping") {
    GameEngine game;
    game.Jump();
    REQUIRE(game.GetRunner().GetVelocity() == vec2(0, -5));
    
    game.AdvanceOneFrame();
    REQUIRE(game.GetRunner().GetPosition() == vec2(50, 345));
  }
  
  SECTION("Double jump") {
    GameEngine game;
    game.Jump();
    REQUIRE(game.GetRunner().GetVelocity() == vec2(0, -5));
    
    game.Jump();
    REQUIRE(game.GetRunner().GetVelocity() == vec2(0, -5));

    game.AdvanceOneFrame();
    REQUIRE(game.GetRunner().GetPosition() == vec2(50, 345));
  }
  
  SECTION("Falling") {
    std::vector<Obstacle> obstacles = {Obstacle(vec2(80, 350), 30, 10)};
    Runner runner = Runner(vec2(50, 200), vec2(0,-5), "cat", 20);
    GameEngine game = GameEngine(runner, obstacles);
    
    game.AdvanceOneFrame();
    REQUIRE(game.GetRunner().GetVelocity() == vec2(0, 7));

    game.AdvanceOneFrame();
    REQUIRE(game.GetRunner().GetPosition() == vec2(50, 202));
  }
}

TEST_CASE("Restart") {
  GameEngine game;
  game.Restart();
  
  REQUIRE(game.GetObstacles().empty());
  REQUIRE_FALSE(game.IsOver());
}

TEST_CASE("Obstacle collisions") {
  std::vector<Obstacle> obstacles;
  obstacles.push_back(Obstacle(vec2(60, 350), 30, 10));

  SECTION("From side") {
    Runner runner = Runner(vec2(50, 350), vec2(0,0), "cat", 20);
    GameEngine game = GameEngine(runner, obstacles);

    game.AdvanceOneFrame();

    REQUIRE(game.IsOver());
  }

  SECTION("From top") {
    Runner runner = Runner(vec2(50, 345), vec2(0,5), "cat", 20);
    GameEngine game = GameEngine(runner, obstacles);

    game.AdvanceOneFrame();

    REQUIRE(game.IsOver());
  }
}

TEST_CASE("Hitting bounds") {
  std::vector<Obstacle> obstacles;
  
  SECTION("Top bound") {
    Runner runner = Runner(vec2(50, 195), vec2(0,-5), "cat", 20);
    GameEngine game = GameEngine(runner, obstacles);

    game.AdvanceOneFrame();
    
    REQUIRE(game.GetRunner().GetVelocity() == vec2(0, 7));
  }

  SECTION("Bottom bound") {
    Runner runner = Runner(vec2(50, 345), vec2(0,5), "cat", 20);
    GameEngine game = GameEngine(runner, obstacles);

    game.AdvanceOneFrame();

    REQUIRE(game.GetRunner().GetVelocity() == vec2(0, 0));
  }
}

} // namespace fluffrun