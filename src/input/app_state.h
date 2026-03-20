//
// Created by gaagaagi on 2026-03-17.
//

#ifndef GRAVITY_BASINS_APPSTATE_H
#define GRAVITY_BASINS_APPSTATE_H

#include <vector>

#include "raylib.h"
#include "../core/shape.h"

enum class StateId {
    SIMULATION,
    DRAW,
    NONE
};

class AppState {
public:
    virtual void handle_input() = 0; // reacts to input
    virtual void update() = 0; // per frame logic
    virtual void draw() = 0; // draw
    virtual void onEnter() = 0; // called when state is entered, for setup
    virtual void onExit() = 0; // called when state is exited, for cleanup

    StateId nextStateId = StateId::NONE; // indicates which state to transition to if any

protected:
    Camera2D* camera;
    std::vector<Shape>* shapes;

    // constructor contains references to shared data like camera and shape list so states can modify them
    AppState(Camera2D* camera, std::vector<Shape>* shapes)
        : camera(camera), shapes(shapes) {}

    // virtual destructor for proper cleanup of derived classes
    virtual ~AppState() = default;

};


#endif //GRAVITY_BASINS_APPSTATE_H