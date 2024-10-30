#pragma once

#ifndef COLLISIONDETECTOR_H
#define COLLISIONDETECTOR_H


#include <Dense>
#include "../RigidBody.h"

struct CollisionInfo {
	Eigen::Vector2f contactPoint;
	Eigen::Vector2f normal;
	float penetrationDepth;
	bool hasCollision = false; //Indicate if a collsion has occurred

};




class CollisionDetector {
public:
	//Checks if two entities are colliding and returning collsion data
	CollisionInfo checkCollision(const RigidBody& bodyA, const RigidBody& bodyB);

	//Resloves the collision bsaed on collision data
	void resolveCollsion(RigidBody& bodyA, RigidBody& bodyB);


private:

	//Helper function to calculate contact point
	Eigen::Vector2f calculateContactPoint(const RigidBody& bodyA, RigidBody& bodyB);

	//Helper funciton to calculate collision normal
	Eigen::Vector2f calculateNormal(const RigidBody& bodyA, const RigidBody& bodyB);

	//Helper function to calculate penetration depth
	float calculatePenetrationDepth(const RigidBody& bodyA, const RigidBody& bodyB);
};



#endif // !COLLISIONDETECTOR_H

