//
// Created by gaagaagi on 2026-03-17.
//

#include "shape.h"

// Circle

Circle::Circle(Vector2 position, float radius, Color color)
    : Shape(position, color), radius(radius) {}

void Circle::draw() {
    DrawCircleV(position, radius, color);
}

// Polygon

Polygon::Polygon(Vector2 position, std::vector<Vector2> vertices, Color color)
    : Shape(position, color), vertices(std::move(vertices)) {}

void Polygon::draw() {
    std::vector<Vector2> worldVertices(vertices.size());
    for (size_t i = 0; i < vertices.size(); i++) {
        worldVertices[i] = { position.x + vertices[i].x, position.y + vertices[i].y };
    }
    DrawTriangleFan(worldVertices.data(), static_cast<int>(worldVertices.size()), color);
}

