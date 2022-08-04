//
// Created by banna on 4/18/2021.
//

#include "runner.h"
#include "config.h"

namespace fluffrun {

Runner::Runner(const vec2& position, const vec2& velocity, std::string animal, float radius) {
  position_ = position;
  animal_ = animal;
  radius_ = radius;
  velocity_ = velocity;
}

vec2 Runner::GetPosition() const {
  return position_;
}

vec2 Runner::GetVelocity() const {
  return velocity_;
}

void Runner::SetPosition(const vec2& position) {
  position_ = position;
}

void Runner::SetVelocity(const vec2& velocity) {
  velocity_ = velocity;
}

void Runner::DrawRunner() const {
  if (animal_ == cat_string_) {
    ci::gl::draw(ci::gl::Texture2d::create(ci::loadImage
                                                  (ci::app::loadAsset(cat_path_))), 
                 ci::Rectf((position_ + vec2(-radius_, -kImageScale*radius_)),
                                  (position_ + vec2(radius_, -kLineGap))));
  } else if (animal_ == rabbit_string_) {
    ci::gl::draw(ci::gl::Texture2d::create(ci::loadImage
                                                  (ci::app::loadAsset(rabbit_path_))), 
                 ci::Rectf((position_ + vec2(-radius_, -kImageScale*radius_)),
                                  (position_ + vec2(radius_, -kLineGap)))); 
  }
}

}  // namespace fluffrun