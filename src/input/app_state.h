//
// Created by gaagaagi on 2026-03-17.
//

#ifndef GRAVITY_BASINS_APPSTATE_H
#define GRAVITY_BASINS_APPSTATE_H

#include <vector>

#include "raylib.h"
#include "../core/shape.h"

enum class StateId {
    MENU,
    SIMULATION,
    DRAW,
    NONE
};

struct AppContext {
    Camera2D* camera;
    std::vector<Shape>* shapes;
    Font* font;
};

class AppState {
public:
    StateId nextStateId = StateId::NONE; // indicates which state to transition to if any
    StateId currentStateId = StateId::NONE; // indicates which state is currently active

    virtual void handle_input() = 0; // reacts to input
    virtual void update() = 0; // per frame logic
    virtual void draw() = 0; // draw
    virtual void onEnter() = 0; // called when state is entered, for setup
    virtual void onExit() = 0; // called when state is exited, for cleanup
    virtual const char* getStateId() {
        switch (currentStateId) {
            case StateId::MENU:
                return "MENU";
            case StateId::SIMULATION:
                return "SIMULATION";
            case StateId::DRAW:
                return "DRAW";
            default:
                return "NONE";
        }
    };

protected:
    AppContext context;

    AppState(AppContext context, StateId stateId) : currentStateId(stateId), context(context) {}

    virtual ~AppState() = default;

};


#endif //GRAVITY_BASINS_APPSTATE_H