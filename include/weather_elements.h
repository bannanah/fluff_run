//
// Created by banna on 5/2/2021.
//

#ifndef FLUFF_RUN_INCLUDE_WEATHER_ELEMENTS_H_
#define FLUFF_RUN_INCLUDE_WEATHER_ELEMENTS_H_

#include "cinder/gl/gl.h"
#include "cinder/app/App.h"

namespace fluffrun {

using glm::vec2;

/**
 * WeatherElement class.
 */
class WeatherElement {
 public:
  /**
   * WeatherElement constructor that takes in element type, position, height, and width.
   * 
   * @param element_type the element type
   * @param position the position of the element
   * @param height the height of the element
   * @param width the width of the element
   */
  WeatherElement(const std::string& element_type, const vec2& position, size_t height, size_t width);

  vec2 GetPosition() const;

  void SetPosition(const vec2& position);
  
  /**
   * Displays the element (draws clouds or snowflakes). 
   */
  void DisplayElement() const;
  
 private:
  vec2 position_;
  size_t width_;
  size_t height_;
  
  std::string image_path_;
  std::string cloud_path_ = "weather/cloud.png";
  std::string snow_path_ = "weather/snowflake.png";

  std::string cloud_ = "cloud";
  std::string snow_ = "snow";
};

}  // namespace fluffrun

#endif //FLUFF_RUN_INCLUDE_WEATHER_ELEMENTS_H_