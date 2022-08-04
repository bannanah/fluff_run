//
// Created by banna on 4/18/2021.
//
#include "cinder/Rand.h"
#include "game_engine.h"
#include "config.h"

namespace fluffrun {

using glm::vec2;

GameEngine::GameEngine() {
  obstacles_.push_back(CreateObstacle());
}

GameEngine::GameEngine(Runner runner, std::vector<Obstacle> obstacles) {
  runner_ = runner;
  obstacles_ = obstacles;
}

bool GameEngine::IsOver() const {
  return game_over_;
}

Runner GameEngine::GetRunner() const {
  return runner_;
}

std::vector<Obstacle> GameEngine::GetObstacles() const {
  return obstacles_;
}

void GameEngine::SetAnimal(std::string animal) {
  runner_ = Runner(kStartPosition, kStartVelocity, animal, kRadius);
}

void GameEngine::SetWeather(std::string weather) {
  weather_ = Weather(weather);
}

void GameEngine::Display() const {
  if (!game_over_) {
    ci::gl::color(kColor);
    ci::gl::drawLine(kLineStart, kLineEnd);
    
    ci::gl::color(kColor);

    weather_.DisplayWeather();
    
    runner_.DrawRunner();
    
    for (const Obstacle& obstacle : obstacles_) {
      obstacle.DrawObstacle();
    }
    
    DisplayScores();
    
  } else {
    DisplayGameOver();
  }
}

void GameEngine::AdvanceOneFrame() {
  if (!game_over_) {
    size_t interval = cinder::randInt(kIntervalMin, interval_max_);
    if (interval_gap_ == interval || interval_gap_ == interval_max_) {
      obstacles_.push_back(CreateObstacle());
      interval_gap_ = 0;
    }

    UpdateRunner();
    UpdateObstacles();
    weather_.UpdateWeather();

    CheckForCollision();

    interval_gap_++; 
    score_++;
    level_tracker_++;

    if (score_ > high_score_) {
      high_score_ = score_;
    }
    LevelUp();
  }
}

void GameEngine::Jump() {
  if (can_jump_) {
    vec2 velocity = runner_.GetVelocity();
    runner_.SetVelocity(kJumpVelocity); 
    can_jump_ = false;
  }
}

void GameEngine::Restart() {
  game_over_ = false;
  obstacles_.clear();
  obstacle_velocity_ = kObstacleStartVelocity;
  score_ = 0;
  level_tracker_ = 0;
  interval_gap_ = 0;
  weather_.Clear();
}

void GameEngine::CheckForCollision() {
  vec2 runner_position = runner_.GetPosition();

  for (Obstacle& obstacle : obstacles_) {
    float runner_x = runner_position.x;
    float runner_y = runner_position.y;
    float obstacle_x = obstacle.GetPosition().x;

    // code for checking whether the number is in a range derived from
    // https://www.geeksforgeeks.org/how-to-check-whether-a-number-is-in-the-rangea-b-using-one-comparison/
    if ((obstacle_x - (kRadius+obstacle.GetWidth()) <= runner_x
        && runner_x <= obstacle_x + (kRadius+obstacle.GetWidth()))
        && (kLinePosition+kRadius-(obstacle.GetHeight()) <= runner_y
            && runner_y <= kLinePosition+kRadius))  {
      game_over_ = true;
    }
  }
}

Obstacle GameEngine::CreateObstacle() {
  size_t height = cinder::randInt(kHeightMin, kHeightMax);
  size_t width = cinder::randInt(kWidthMin, kWidthMax);
  Obstacle obstacle = Obstacle(kObstacleLoadPoint, height, width);
  
  return obstacle;
}

void GameEngine::UpdateRunner() {
  vec2 position = runner_.GetPosition();
  runner_.SetPosition(position + runner_.GetVelocity());

  if (runner_.GetPosition().y < kMaxJumpHeight) {
    runner_.SetVelocity(kLandVelocity);
  }

  if (runner_.GetPosition().y + runner_.GetVelocity().y > kLinePosition) {
    runner_.SetVelocity(kStartVelocity);
    can_jump_ = true;
  }
}

void GameEngine::UpdateObstacles() {
  for (Obstacle& obstacle : obstacles_) {
    vec2 position = obstacle.GetPosition();
    obstacle.SetPosition(position + obstacle_velocity_);
  }
}

void GameEngine::LevelUp() {
  if (level_tracker_ == kLevelUp) {
    obstacle_velocity_ += vec2(kSpeedFactor*obstacle_velocity_.x, 0);
    
    if (interval_max_ - kIntervalAdj >= kIntervalMin) {
      interval_max_ -= kIntervalAdj;
    } 
    
    level_tracker_ = 0;

    std::cout << obstacle_velocity_ << std::endl;
    std::cout << interval_max_ << std::endl;
  }
}

void GameEngine::DisplayScores() const {
  ci::gl::drawString(kCurrent + std::to_string(score_), kScorePosition,
                     kColor, ci::Font(kEmptyString, kSmallFont));
  ci::gl::drawString(kHigh + std::to_string(high_score_), kHighScorePosition,
                     kColor, ci::Font(kEmptyString, kSmallFont));
}

void GameEngine::DisplayGameOver() const {
  ci::gl::drawStringCentered(kGameOver, kGameOverPosition,
                             kColor, ci::Font(kEmptyString, kBigFont));
  ci::gl::drawStringCentered(kScoreIs + std::to_string(score_), kScoreMessagePosition,
                             kColor, ci::Font(kEmptyString, kSmallFont));
  ci::gl::drawStringCentered(kPlayAgain, kPlayAgainPosition,
                             kColor, ci::Font(kEmptyString, kSmallFont));
}

}  // namespace fluffrun