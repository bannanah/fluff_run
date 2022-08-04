//
// Created by banna on 4/18/2021.
//

#ifndef FLUFF_RUN_INCLUDE_OBSTACLE_H_
#define FLUFF_RUN_INCLUDE_OBSTACLE_H_

#include "cinder/gl/gl.h"

namespace fluffrun {

using glm::vec2;

/**
 * Obstacle class.
 */
class Obstacle {
 public:
  /**
   * Default obstacle constructor.
   */
  Obstacle() {};

  /**
   * Obstacle constructor that takes in position, height, and width.
   * 
   * @param position the position of the obstacle
   * @param height the height of the obstacle
   * @param width the width of the obstacle
   */
  Obstacle(vec2 position, size_t height, size_t width);

  size_t GetHeight() const;

  size_t GetWidth() const;

  vec2 GetPosition() const;

  void SetPosition(vec2 position);
  
  /**
   * Draws the obstacle. 
   */
  void DrawObstacle() const; 

 private:
  size_t height_;
  size_t width_;
  vec2 position_;
};

}  // namespace fluffrun

#endif //FLUFF_RUN_INCLUDE_OBSTACLE_H_
