//
// Created by banna on 4/26/2021.
//

#ifndef FLUFF_RUN_INCLUDE_CONFIG_H_
#define FLUFF_RUN_INCLUDE_CONFIG_H_

#include "cinder/gl/gl.h"

namespace fluffrun {

// File that stores all constant numbers (float, size_t, double)

// Obstacle const numbers
const static size_t kIntervalMin = 70;
const static size_t kIntervalAdj = 5;

const static size_t kWidthMin = 10;
const static size_t kWidthMax = 30;
const static size_t kHeightMin = 20;
const static size_t kHeightMax = 60;

const static double kSpeedFactor = 0.2;


// Runner const numbers
const static float kRadius = 20;
const static float kImageScale = 2;

const static float kLineGap = 1;
const static size_t kLinePosition = 350;
const static size_t kMaxJumpHeight = 200;


// Weather const numbers
const static size_t kCloudGap = 900;
const static size_t kCloudWidth = 70;
const static size_t kCloudHeight = 25; 

const static size_t kSnowGap = 50;
const static size_t kSnowXMin = 50;
const static size_t kSnowXMax = 950;
const static size_t kSnowWidth = 10;


// Other misc constants
const static size_t kLevelUp = 500;
const static float kSmallFont = 30;
const static float kBigFont = 100;
}

#endif //FLUFF_RUN_INCLUDE_CONFIG_H_