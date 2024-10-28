#pragma once
#ifndef RIGIDBODY_H
#define RIGIDBODY_H

#include "Geometry/Geometry.h"
#include <memory>
#include "Contact.h"
#include <Dense>
#include <vector>
#include "polyscope/surface_mesh.h"




class RigidBody {

public:
    RigidBody(float _mass, Geometry* _geometry, const std::string& meshFilename = "");

    static int counter;

    void updateInertiaMatrix();
    void addForceAtPos(const Eigen::Vector3f& pos, const Eigen::Vector3f& force);
    void getVelocityAtPos(const Eigen::Vector3f& pos, Eigen::Vector3f& vel);

    bool fixed;
    float mass;

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

    surface_mesh* mesh;                         // Used for rendering







};

#endif  //!RIGIDBODY_H