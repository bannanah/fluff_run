//
// Created by banna on 4/26/2021.
//

#ifndef FLUFF_RUN_INCLUDE_WEATHER_H_
#define FLUFF_RUN_INCLUDE_WEATHER_H_

#include "cinder/gl/gl.h"
#include "cinder/app/App.h"
#include "weather_elements.h"

namespace fluffrun {

/**
 * Class that handles the weather of the game. 
 */
class Weather {
 public:
  /**
   * Default constructor.
   */
  Weather() {};
  
  /**
   * Constructor that sets the weather type.
   * 
   * @param weather the weather type
   */
  Weather(std::string weather);
  
  std::vector<WeatherElement> GetElements() const;
  
  /**
   * Displays the weather elements (snow, clouds, sun, etc).
   */
  void DisplayWeather() const;
  
  /**
   * Updates the position of the weather elements and generates more as needed. 
   */
  void UpdateWeather();
  
  /**
   * Clears the weather element vector.
   */
  void Clear();
  
 private:
  std::string sunny_ = "sunny";
  std::string snowy_ = "snowy";
  std::string cloud_ = "cloud";
  std::string snow_ = "snow";
  std::string weather_;
  
  std::string sun_path_ = "weather/sun.png";
  
  ci::Rectf sun_position_ = ci::Rectf(glm::vec2(900, 50), glm::vec2(1000, 150));
  vec2 cloud_start_ = vec2(1010, 100);
  
  vec2 snow_velocity_ = vec2(0, 3);
  vec2 cloud_velocity_ = vec2(-1, 0);
  vec2 velocity_ = vec2(0,0);
  
  std::vector<WeatherElement> elements_;
  size_t element_gap_ = 0;

  /**
   * Generates more clouds.
   */
  void GenerateClouds();
  
  /**
   * Generates more snow.
   */
  void GenerateSnow();
};

}

#endif //FLUFF_RUN_INCLUDE_WEATHER_H_