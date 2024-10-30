#pragma once
#ifndef RIGIDBODY_H
#define RIGIDBODY_H

#include <memory>
#include <Dense>
#include <vector>
#include "polyscope/surface_mesh.h"
#include "Geometry/Geometry.h" // Ensure this is included

class Contact;

enum BodyType {
    staticBody,
    kinematicBody,
    dynamicBody
};

class RigidBody {
public:
    RigidBody(float _mass, std::unique_ptr<Geometry> _geometry, BodyType _type = BodyType::dynamicBody, const std::string& meshFilename = "")
        : mass(_mass), geometry(std::move(_geometry)), type(_type), x(Eigen::Vector2f::Zero()), xdot(Eigen::Vector2f::Zero()) {
        if (type == BodyType::staticBody) mass = 0.0f; // Adjusting mass for static body
        updateInertiaMatrix();
    }

    static int counter;
    Geometry* getGeometry() const { return geometry.get(); }
    void updateInertiaMatrix();
    void addForceAtPos(const Eigen::Vector2f& pos, const Eigen::Vector2f& force);
    void getVelocityAtPos(const Eigen::Vector2f& pos, Eigen::Vector2f& vel);

    // Getters
    float getMass() const { return mass; }
    BodyType getBodyType() const { return type; }
    const Eigen::Vector2f& getVelocity() const { return xdot; }

    // Impulse Application for Collision Response
    void applyImpulse(const Eigen::Vector2f& impulse) {
        if (type != staticBody && mass > 0.0f) {
            xdot += impulse / mass;
        }
    }

private:
    bool fixed = false;
    float mass;
    BodyType type;

    Eigen::Matrix2f I, Iinv;            // Inertia and inverse inertia matrix (global)
    Eigen::Matrix2f Ibody, IbodyInv;    // Inertia and inverse inertia in the local body frame.
    Eigen::Vector2f x;                  // Position.
    Eigen::Quaternionf q;               // Orientation.

    Eigen::Vector2f xdot;               // Linear velocity.
    Eigen::Vector2f omega;              // Angular velocity.
    Eigen::Vector2f f;                  // Linear force.
    Eigen::Vector2f tau;                // Angular force (torque).

    Eigen::Vector2f fc;                 // Linear constraint force.
    Eigen::Vector2f tauc;               // Angular constraint force

    std::unique_ptr<Geometry> geometry; // The geometry of the rigid body.
    std::vector<Contact*> contacts;     // Pointer array of contact constraints involving this body.

    surface_mesh* mesh;                 // Used for rendering
};

#endif  //!RIGIDBODY_H
