//
// Created by banna on 4/18/2021.
//

#ifndef FINAL_PROJECT_BANNANAH_RUNNER_H
#define FINAL_PROJECT_BANNANAH_RUNNER_H

#include "cinder/gl/gl.h"
#include "runner.h"
#include "obstacle.h"
#include "weather.h"
#include "config.h"

namespace fluffrun {

/**
 * GameEngine class that updates the game.
 */
class GameEngine {
 public:
  /**
   * Default GameEngine constructor. 
   */
  GameEngine();
  
  /**
   * GameEngine constructor that takes in a runner and obstacles.
   * 
   * @param runner the runner
   * @param obstacles the obstacles
   */
  GameEngine(Runner runner, std::vector<Obstacle> obstacles);
  
  /**
   * Returns the bool of the game's state (over or not).
   * 
   * @return bool of the game's state
   */
  bool IsOver() const;
  
  Runner GetRunner() const;

  std::vector<Obstacle> GetObstacles() const;
  
  /**
   * Sets the animal for this game.
   * 
   * @param animal the runner animal
   */
  void SetAnimal(std::string animal);
  
  /**
   * Sets the weather for this game.
   * 
   * @param weather the weather
   */
  void SetWeather(std::string weather);

  /**
   * Displays the contents game (runner, obstacles, weather, score).
   */
  void Display() const;

  /**
   * Updates the position and velocity of the runner and obstacles.
   */
  void AdvanceOneFrame();

  /**
   * Makes the runner jump.
   */
  void Jump();
  
  /**
   * Restarts the game (resets variables).
   */
  void Restart();

  /**
   * Checks whether a collision occurs between the runner and an obstacle.
   */
  void CheckForCollision();
  
 private:
  const ci::Color kColor = ci::Color("white");
  const std::string kEmptyString = "";

  // Line variables
  const vec2 kLineStart = vec2(0, 350);
  const vec2 kLineEnd = vec2(1000, 350);

  // Obstacle const variables
  const vec2 kObstacleLoadPoint = vec2(1010,350);
  const vec2 kObstacleStartVelocity = vec2(-3, 0);

  // Runner const variables
  const std::string kDefaultAnimal = "cat";
  const vec2 kStartPosition = vec2(50, 350);
  const vec2 kStartVelocity = vec2(0, 0);
  const vec2 kJumpVelocity = vec2(0, -5);
  const vec2 kLandVelocity = vec2(0, 7);
  
  // Game over message variables
  const vec2 kGameOverPosition = vec2(500, 100);
  const vec2 kScoreMessagePosition = vec2(500, 250);
  const vec2 kPlayAgainPosition = vec2(500, 300);
  const std::string kGameOver = "Game Over!";
  const std::string kScoreIs = "Your score: ";
  const std::string kPlayAgain = "Press Space to play again.";
  
  // Score variables
  const std::string kHigh = "HIGH: ";
  const vec2 kHighScorePosition = vec2(0, 10);
  const std::string kCurrent = "CURRENT: ";
  const vec2 kScorePosition = vec2(800, 10);

  Runner runner_ = Runner(kStartPosition, kStartVelocity, kDefaultAnimal, kRadius);
  
  Weather weather_ = Weather();
  
  std::vector<Obstacle> obstacles_;
  vec2 obstacle_velocity_ = vec2(-3, 0);
  size_t interval_max_ = 120;
  
  size_t interval_gap_ = 0;
  size_t level_tracker_ = 0;
  size_t score_ = 0;
  size_t high_score_ = 0;
  
  bool can_jump_ = true;
  bool game_over_ = false;
  
  /**
   * Creates an Obstacle.
   * 
   * @return the new obstacle
   */
  Obstacle CreateObstacle();
  
  /**
   * Updates the position of the runner.
   */
  void UpdateRunner();
  
  /**
   * Updates the position of every obstacle.
   */
  void UpdateObstacles();

  /**
   * Levels up the game (increases speed of obstacles).
   */
  void LevelUp();
   
  /**
   * Displays the current and high scores.
   */
  void DisplayScores() const;
  
  /**
   * Displays the game over message.
   */
  void DisplayGameOver() const;
};

}  // namespace fluffrun

#endif //FINAL_PROJECT_BANNANAH_RUNNER_H