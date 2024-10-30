#pragma once
#ifndef CIRCLE_H
#define CIRCLE_H

#include "Geometry.h"
#include <Dense>
#include <iostream>
#include <cmath>

class Circle : public Geometry {
public:
    Circle(float radius)
        : radius(radius) {}
   
    const double PI = 3.14159265358979323846;


    float computeArea() const override {
        return PI * radius * radius;
    }

    float perimeter() const override {
        return 2 * PI * radius;
    }

    std::string name() const override {
        return "Circle";
    }

    bool contains(float x, float y) const override {
        // Implement logic to check if a point is within the circle
        return (std::sqrt(x * x + y * y) <= radius);
    }

    void transform(const Eigen::Matrix2f& matrix) override {
        // Implement transformation logic using the provided matrix
    }

    void draw() const override {
        // Implement draw logic (could integrate with your graphics engine)
        std::cout << "Drawing Circle\n";
    }

    Eigen::Vector2f getBoundingBoxMin() const override {
        return Eigen::Vector2f(-radius, -radius); // Bottom-left corner of bounding box
    }

    Eigen::Vector2f getBoundingBoxMax() const override {
        return Eigen::Vector2f(radius, radius); // Top-right corner of bounding box
    }

private:
    float radius;
};

#endif // CIRCLE_H
