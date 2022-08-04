//
// Created by banna on 4/18/2021.
//
#include "runner.h"

//
// Created by banna on 4/18/2021.
//

#include "obstacle.h"

namespace fluffrun {

Obstacle::Obstacle(vec2 position, size_t height, size_t width) {
  height_ = height;
  width_ = width;
  position_ = position;
}

size_t Obstacle::GetHeight() const {
  return height_;
}

size_t Obstacle::GetWidth() const {
  return width_;
}

vec2 Obstacle::GetPosition() const {
  return position_;
}

void Obstacle::SetPosition(vec2 position) {
  position_ = position;
}

void Obstacle::DrawObstacle() const {
  ci::gl::drawStrokedRect(ci::Rectf(vec2(position_.x+width_,position_.y-height_),
                                        vec2(position_.x-width_,position_.y)));
}

}  // namespace fluffrun