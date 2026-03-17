//
// Created by gaagaagi on 2026-03-17.
//

#ifndef GRAVITY_BASINS_WORLD_CAMERA_H
#define GRAVITY_BASINS_WORLD_CAMERA_H

#include "raylib.h"

class WorldCamera {
public:
    WorldCamera();

    Vector2 world_to_screen(Vector2 worldPos);

    Vector2 screen_to_world(Vector2 screenPos);

    void move(Vector2 delta) { cameraPosition.x += delta.x; cameraPosition.y += delta.y; }

    void zoom(float factor) { zoomLevel *= factor; }

    void rotate(float angle) { rotationAngle += angle; }

    Vector2 get_position() { return cameraPosition; }
    void set_position(Vector2 pos) { cameraPosition = pos; }

    float get_zoom() { return zoomLevel; }
    void set_zoom(float zoom) { zoomLevel = zoom; }

    float get_rotation() { return rotationAngle; }
    void set_rotation(float angle) { rotationAngle = angle; }

private:
    Vector2 cameraPosition;
    float zoomLevel;
    float rotationAngle;
};


#endif //GRAVITY_BASINS_WORLD_CAMERA_H