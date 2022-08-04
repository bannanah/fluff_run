//
// Created by banna on 4/18/2021.
//

#ifndef FLUFF_RUN_APP_H
#define FLUFF_RUN_APP_H

#pragma once

#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "game_engine.h"

namespace fluffrun {

/**
 * An app for the fluff run game.
 */
class FluffRun : public ci::app::App {
public:
    /**
     * Default FluffRun constructor.
     */
    FluffRun();

    /**
     * Draws the contents of the app.
     */
    void draw() override;

    /**
     * Updates the contents of the app.
     */
    void update() override;

    /**
     * Responds to keyboard interactions.
     * 
     * @param event the keyboard interaction
     */
    void keyDown(cinder::app::KeyEvent event) override;

    const int kWindowSizeX = 1000;
    const int kWindowSizeY = 400;

 private:
  // Display variables
  const ci::Color kBackgroundColor = ci::Color("black");
  const ci::Color kMainColor = ci::Color("white");
  
  const ci::Font kFont = ci::Font("", 30);
  
  const std::string kWelcome = "Welcome to Fluff Run!";
  const vec2 kWelcomePosition = vec2(500, 50);
  
  const std::string kAnimals = "Press one of the numbers below to choose an animal: \n1. cat \n2. rabbit";
  const vec2 kAnimalPosition = vec2(500, 100);
  
  const std::string kWeather = "Press one of the letters below to choose the weather: \na. sunny\ns. snowy";
  const vec2 kWeatherPosition = vec2(500, 200);
  
  const std::string kFinishSelection = "Press Space to finish selection and begin.";
  const vec2 kFinishPosition = vec2(500, 300);
  
  const std::string kCat = "cat";
  const ci::Rectf kCatCursor = ci::Rectf(vec2(220, 145), vec2(230, 130));
  
  const std::string kRabbit = "rabbit";
  const ci::Rectf kRabbitCursor = ci::Rectf(vec2(220, 170), vec2(230, 155));
  
  const std::string kSunny = "sunny";
  const ci::Rectf kSunnyCursor = ci::Rectf(vec2(220, 245), vec2(230, 230));
  
  const std::string kSnowy = "snowy";
  const ci::Rectf kSnowyCursor = ci::Rectf(vec2(220, 270), vec2(230, 255));

  const std::string kCursorPath = "cursor.png";
  ci::Rectf cursor1_position_ = ci::Rectf(vec2(350, 50), vec2(360, 70));
  ci::Rectf cursor2_position_ = ci::Rectf(vec2(350, 50), vec2(360, 70));
  
  GameEngine game_;

  bool on_menu_ = true;
  
  /**
   * Displays the menu (welcome message, animal and weather options, start).
   */
  void DrawMenu();
};

}  // namespace fluffrunner


#endif //FLUFF_RUN_APP_H
