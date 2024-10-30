#pragma once

#ifndef COLLISIONSOLVER_H
#define COLLISIONSOLVER_H

#include <dense>
#include "CollisionDetector.h"
#include "../Entity.h"
#include "../Contact.h"
#include <algorithm>





class CollisionSolver {

    // Resolves a collision based on a Contact instance
    void ResolveCollision(Contact& contact) {
        contact.calculateContactProperties(); // Ensure contact details are up-to-date

        RigidBody* bodyA = contact.getBodyA();
        RigidBody* bodyB = contact.getBodyB();

        // Exit if either body is null or if both bodies are static
        if (!bodyA || !bodyB || (bodyA->getBodyType() == staticBody && bodyB->getBodyType() == staticBody))
            return;

        Eigen::Vector2f relativeVelocity = bodyB->getVelocity() - bodyA->getVelocity();
        float velocityAlongNormal = relativeVelocity.dot(contact.getNormal());

        // Ignore resolving if moving apart
        if (velocityAlongNormal > 0) return;

        // Apply restitution (bounciness)
        float restitution = std::min(contact.getRestitution(), 1.0f);
        float j = -(1 + restitution) * velocityAlongNormal;
        j /= (1 / bodyA->getMass()) + (1 / bodyB->getMass());

        Eigen::Vector2f impulse = j * contact.getNormal();
        if (bodyA->getBodyType() != staticBody) bodyA->applyImpulse(-impulse);
        if (bodyB->getBodyType() != staticBody) bodyB->applyImpulse(impulse);

        // Apply positional correction
        PositionalCorrection(contact);
    }

private:
    void PositionalCorrection(Contact& contact) {
        RigidBody* bodyA = contact.getBodyA();
        RigidBody* bodyB = contact.getBodyB();

        const float percent = 0.2f; // Usually a small percentage
        const float slop = 0.01f;   // Allowable penetration depth

        float correctionMagnitude = std::max(contact.getPenetrationDepth() - slop, 0.0f) /
            ((1 / bodyA->getMass()) + (1 / bodyB->getMass())) * percent;

        Eigen::Vector2f correction = correctionMagnitude * contact.getNormal();
        if (bodyA->getBodyType() != staticBody) bodyA->adjustPosition(-correction);
        if (bodyB->getBodyType() != staticBody) bodyB->adjustPosition(correction);
    }







};




#endif // !COLLISIONSOLVER_H

