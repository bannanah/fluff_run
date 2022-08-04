//
// Created by banna on 5/2/2021.
//

#include "weather_elements.h"

namespace fluffrun {

WeatherElement::WeatherElement(const std::string& element_type, const vec2& position, size_t height, size_t width) {
  position_ = position;
  height_ = height;
  width_ = width;
  
  if (element_type == cloud_) {
    image_path_ = cloud_path_;
  } else if (element_type == snow_) {
    image_path_ = snow_path_;
  }
}

vec2 WeatherElement::GetPosition() const {
  return position_;
}

void WeatherElement::SetPosition(const vec2& position) {
  position_ = position;
}

void WeatherElement::DisplayElement() const {
  ci::gl::draw(ci::gl::Texture2d::create(ci::loadImage(ci::app::loadAsset(image_path_))),
               ci::Rectf(vec2(position_.x+width_,position_.y-height_),
                                vec2(position_.x-width_,position_.y+height_)));
}

} // namespace fluffrun