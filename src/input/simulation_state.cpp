//
// Created by gaagaagi on 2026-03-17.
//

#include "simulation_state.h"
#include "raymath.h"

SimulationState::SimulationState(AppContext context) : AppState(context, StateId::SIMULATION) {}

void SimulationState::handle_input() {
    // Handle input specific to the simulation state

    // Panning via click-drag
    if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
        Vector2 mouseDelta = GetMouseDelta();
        // Scale the mouse delta by the inverse of the zoom to ensure consistent panning speed regardless of zoom level
        mouseDelta = Vector2Scale(mouseDelta, -1.0f / context.camera->zoom);
        // Rotate delta by camera rotation so dragging direction is consistent with camera orientation
        mouseDelta = Vector2Rotate(mouseDelta, -context.camera->rotation * DEG2RAD);
        context.camera->target = Vector2Add(context.camera->target, mouseDelta);
    }

    // Zoom +-0.1 via I and O keys
    if (IsKeyPressed(KEY_I)){
        context.camera->zoom += 0.1f;
    }

    if (IsKeyPressed(KEY_O)){
        context.camera->zoom -= 0.1f;
        if (context.camera->zoom < 0.1f) {
            context.camera->zoom = 0.1f; // Prevent zooming out too much
        }
    }

    // Rotate +-5 degrees via J and L keys
    if (IsKeyPressed(KEY_J)) {
        context.camera->rotation -= 5.0f;
    }

    if (IsKeyPressed(KEY_L)) {
        context.camera->rotation += 5.0f;
    }

    if (IsKeyPressed(KEY_K)) {
        nextStateId = StateId::DRAW;
    }

}

void SimulationState::update() {
    // Update the simulation state (e.g., update positions of shapes based on physics)
}

void SimulationState::draw() {
    /* THIS STUFF SHOULD NOT BE HERE
     * BECAUSE THIS IS BEING CALLED IN A LOOP.
     * THIS IS ONLY HERE FOR TESTING
     */

    Vector2 worldPos1 = { 100.0f, 100.0f };
    Vector2 worldPos2 = { 130.0f, 130.0f };
    // Try drawing a polygon
    std::vector<Vector2> vertices;
    // Make a diamond shape
    vertices.push_back({0.0f, -100.0f});
    vertices.push_back({-25.0f, -75.0f});
    vertices.push_back({0.0f, -50.0f});
    vertices.push_back({25.0f, -75.0f});

    /* This is okay to be here! Just remove the above somewhere they are not within a loop. */
    DrawCircleV(worldPos1, 10.0f, RED);
    DrawRectangleV(worldPos2, { 30.0f, 20.0f }, BLUE);

    DrawTriangleFan(vertices.data(), static_cast<int>(vertices.size()), GREEN);


}

void SimulationState::onEnter() {
    // Initialize any necessary variables or state when entering the simulation state
}

void SimulationState::onExit() {
    // Clean up any resources or reset variables when exiting the simulation state
}
