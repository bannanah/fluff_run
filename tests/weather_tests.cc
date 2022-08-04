//
// Created by banna on 5/3/2021.
//
#include <catch2/catch.hpp>

#include "weather.h"

namespace catrunner {

TEST_CASE("Update position") {
  SECTION("Clouds") {
    Weather weather = Weather("sunny");
    weather.UpdateWeather();
    REQUIRE(weather.GetElements().at(0).GetPosition() == vec2(1009, 100));
  }
  
  SECTION("Snow") {
    Weather weather = Weather("snowy");
    weather.UpdateWeather();
    REQUIRE(weather.GetElements().at(0).GetPosition() == vec2(950, 3)); 
  }
}

TEST_CASE("Generating elements") {
  SECTION("Clouds") {
    Weather weather = Weather("sunny");
    for (size_t x = 0; x < 901; x++) {
      weather.UpdateWeather();
    }
    
    REQUIRE(weather.GetElements().size() == 2);
  }
  
  SECTION("Snow") {
    Weather weather = Weather("snowy");
    for (size_t x = 0; x < 51; x++) {
      weather.UpdateWeather();
    }
    
    REQUIRE(weather.GetElements().size() == 2);
  }
}

TEST_CASE("Clear") {
  Weather weather = Weather("sunny");
  weather.Clear();
  REQUIRE(weather.GetElements().empty());
}

} // namespace catrunner