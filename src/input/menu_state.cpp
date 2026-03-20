//
// Created by gaagaagi on 2026-03-20.
//

#include "menu_state.h"

MenuState::MenuState(AppContext context) : AppState(context, StateId::MENU) {}

void MenuState::handle_input() {

    if (IsKeyPressed(KEY_SPACE)) {
        // start the simulation when space is pressed
        nextStateId = StateId::SIMULATION;
    }

}

void MenuState::update() {

}

void MenuState::draw() {
    // Draw menu in screen space, not world space
    EndMode2D();

    Vector2 center = { GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f };

    // Draw the title
    const char* title = "Orbital Mechanics Simulator";
    Vector2 titleSize = MeasureTextEx(*context.font, title, 40, 2);
    DrawTextEx(*context.font, title, { center.x - titleSize.x / 2, center.y - 50 }, 40, 2, WHITE);

    // Draw instructions
    const char* instructions = "Press SPACE to Start Simulation";
    Vector2 instrSize = MeasureTextEx(*context.font, instructions, 20, 1);
    DrawTextEx(*context.font, instructions, { center.x - instrSize.x / 2, center.y + 20 }, 20, 1, LIGHTGRAY);

    BeginMode2D(*context.camera);
}

void MenuState::onEnter() {
    // Any setup needed when entering draw state
}

void MenuState::onExit() {
    // Any cleanup needed when exiting draw state
}