//
// Created by banna on 4/18/2021.
//
#include "fluff_run_app.h"

using fluffrun::FluffRun;

void prepareSettings(FluffRun::Settings* settings) {
    settings->setResizable(false);
}

// This line is a macro that expands into an "int main()" function.
CINDER_APP(FluffRun, ci::app::RendererGl, prepareSettings);


