//
// Created by gaagaagi on 2026-03-17.
//

#include "draw_state.h"

DrawState::DrawState(AppContext context) : AppState(context, StateId::DRAW) {}

void DrawState::handle_input() {

    if (IsKeyPressed(KEY_K)) {
        // go back to simulation state
        nextStateId = StateId::SIMULATION; 
    }

}

void DrawState::update() {

}

void DrawState::draw() {
    for (Shape& shape : *context.shapes) {
        shape.draw_shape();
    }
}

void DrawState::onEnter() {
    // Any setup needed when entering draw state
}

void DrawState::onExit() {
    // Any cleanup needed when exiting draw state
}