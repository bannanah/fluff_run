//
// Created by banna on 4/18/2021.
//
#include "fluff_run_app.h"

namespace fluffrun {

FluffRun::FluffRun() {
    ci::app::setWindowSize(kWindowSizeX, kWindowSizeY);
}

void FluffRun::draw() {
  ci::gl::clear(kBackgroundColor);
  
  if (on_menu_) {
    DrawMenu();
  } else {
    game_.Display();
  }
}

void FluffRun::update() { 
  if (!on_menu_) { 
    game_.AdvanceOneFrame();
  }
}

void FluffRun::keyDown(cinder::app::KeyEvent event) {
  bool is_over = game_.IsOver();
  
  if (event.getCode() == cinder::app::KeyEvent::KEY_q) {
    quit();
  }
  
  if (!on_menu_) {
    if (!is_over) {
      if (event.getCode() == cinder::app::KeyEvent::KEY_SPACE) {
        game_.Jump();
      }
    } else {
      if (event.getCode() == cinder::app::KeyEvent::KEY_SPACE) {
        game_.Restart();
      }
    }
  } else {
    if (event.getChar() == cinder::app::KeyEvent::KEY_1) {
      game_.SetAnimal(kCat);
      cursor1_position_ = kCatCursor;
    } else if (event.getCode() == cinder::app::KeyEvent::KEY_2) {
      game_.SetAnimal(kRabbit);
      cursor1_position_ = kRabbitCursor;
    } else if (event.getChar() == cinder::app::KeyEvent::KEY_a) {
      game_.SetWeather(kSunny);
      cursor2_position_ = kSunnyCursor;
    } else if (event.getChar() == cinder::app::KeyEvent::KEY_s) {
      game_.SetWeather(kSnowy);
      cursor2_position_ = kSnowyCursor;
    } else if (event.getCode() == cinder::app::KeyEvent::KEY_SPACE) {
      on_menu_ = false;
    }
  }
}

void FluffRun::DrawMenu() {
  ci::gl::drawStringCentered(kWelcome, kWelcomePosition,kMainColor,kFont);
  ci::gl::drawStringCentered(kAnimals, kAnimalPosition,kMainColor,kFont);
  ci::gl::drawStringCentered(kWeather, kWeatherPosition,kMainColor,kFont);
  ci::gl::drawStringCentered(kFinishSelection, kFinishPosition,kMainColor,kFont);

  ci::gl::draw(ci::gl::Texture2d::create(ci::loadImage
                                             (ci::app::loadAsset(kCursorPath))),cursor1_position_);
  ci::gl::draw(ci::gl::Texture2d::create(ci::loadImage
                                             (ci::app::loadAsset(kCursorPath))),cursor2_position_);
}

}  // namespace fluffrun