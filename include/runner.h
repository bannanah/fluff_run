//
// Created by banna on 4/18/2021.
//

#ifndef FLUFF_RUN_INCLUDE_RUNNER_H_
#define FLUFF_RUN_INCLUDE_RUNNER_H_

#include "cinder/gl/gl.h"
#include "cinder/app/App.h"

namespace fluffrun {

using glm::vec2;

/**
 * Runner class.
 */
class Runner {
 public:
  /**
   * Default runner constructor.
   */
  Runner() {};
  
  /**
   * Runner constructor that takes in a position, animal, and runner radius. 
   * 
   * @param position the position of the runner
   * @param animal the animal type of the runner
   * @param radius the radius of the runner
   */
  Runner(const vec2& position, const vec2& velocity, std::string animal, float radius);

  vec2 GetPosition() const;

  vec2 GetVelocity() const;

  void SetPosition(const vec2& position);

  void SetVelocity(const vec2& velocity);

  /**
   * Draws the runner (cat or rabbit).
   */
  void DrawRunner() const;
  
 private:
  float radius_;
  std::string animal_;
  
  std::string cat_string_ = "cat";
  std::string cat_path_ = "animals/cat.png";
  
  std::string rabbit_string_ = "rabbit";
  std::string rabbit_path_ = "animals/rabbit.png";
  
  vec2 position_;
  vec2 velocity_;
};

}  // namespace fluffrun

#endif //FLUFF_RUN_INCLUDE_RUNNER_H_