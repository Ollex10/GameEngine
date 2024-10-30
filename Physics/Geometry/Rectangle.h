#pragma once
#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Geometry.h"
#include <Dense>
#include <iostream>

class Rectangle : public Geometry {
public:
    Rectangle(float width, float height)
        : width(width), height(height) {}

    float computeArea() const override {
        return width * height;
    }

    float perimeter() const override {
        return 2 * (width + height);
    }

    std::string name() const override {
        return "Rectangle";
    }

    bool contains(float x, float y) const override {
        // Implement logic to check if a point is within the rectangle
        // Assuming (0, 0) is the bottom-left corner
        return (x >= 0 && x <= width) && (y >= 0 && y <= height);
    }

    void transform(const Eigen::Matrix2f& matrix) override {
        // Implement transformation logic using the provided matrix
    }

    void draw() const override {
        // Implement draw logic (could integrate with your graphics engine)
        std::cout << "Drawing Rectangle\n";
    }

    Eigen::Vector2f getBoundingBoxMin() const override {
        return Eigen::Vector2f(0, 0); // Bottom-left corner
    }

    Eigen::Vector2f getBoundingBoxMax() const override {
        return Eigen::Vector2f(width, height); // Top-right corner
    }

private:
    float width;
    float height;
};

#endif // RECTANGLE_H
