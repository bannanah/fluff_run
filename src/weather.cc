//
// Created by banna on 4/26/2021.
//

#include "weather.h"
#include "config.h"
#include "cinder/Rand.h"

namespace fluffrun {

Weather::Weather(std::string weather) {
  weather_ = weather;
  if (weather == sunny_) {
    velocity_ = cloud_velocity_;
    elements_.push_back(WeatherElement(cloud_, cloud_start_, kCloudHeight, kCloudWidth));
  } else if (weather == snowy_) {
    velocity_ = snow_velocity_;
    elements_.push_back(WeatherElement(snow_, vec2(kSnowXMax, 0), kSnowWidth, kSnowWidth));
  }
}

std::vector<WeatherElement> Weather::GetElements() const {
  return elements_;
}

void Weather::DisplayWeather() const {
  if (weather_ == sunny_) {
    ci::gl::draw(ci::gl::Texture2d::create(ci::loadImage
                                               (ci::app::loadAsset(sun_path_))), sun_position_);
    for (WeatherElement element : elements_) {
      element.DisplayElement();
    }
    
  } else if (weather_ == snowy_) {
    for (WeatherElement element : elements_) {
      element.DisplayElement();
    }
  }
}

void Weather::UpdateWeather() {
  for (WeatherElement &element : elements_) {
    vec2 position = element.GetPosition();
    element.SetPosition(position + velocity_);
  }
  
  if (weather_ == sunny_) {
    GenerateClouds();
  } else if (weather_ == snowy_) {
    GenerateSnow();
  }
  
  element_gap_++;
}

void Weather::GenerateClouds() {
  if (element_gap_ == kCloudGap) {
    elements_.push_back(WeatherElement(cloud_, cloud_start_, kCloudHeight, kCloudWidth));
    element_gap_ = 0;
  }
}

void Weather::GenerateSnow() {
  if (element_gap_ == kSnowGap) {
    size_t x_position = cinder::randInt(kSnowXMin, kSnowXMax);
    elements_.push_back(WeatherElement(snow_, vec2(x_position, 0), kSnowWidth, kSnowWidth));
    element_gap_ = 0;
  }

  // Deletes snow once it hits the line
  for (size_t x = 0; x < elements_.size(); x++) {
    if (elements_.at(x).GetPosition().y + kSnowWidth > kLinePosition) {
      elements_.erase(elements_.begin());
    }
  }
}

void Weather::Clear() {
  elements_.clear();
}

} // namespace fluffrun