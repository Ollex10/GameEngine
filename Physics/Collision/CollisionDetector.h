#pragma once

#ifndef COLLISIONDETECTOR_H
#define COLLISIONDETECTOR_H


#include <Dense>
class Entity;

struct CollisionInfo {
	Eigen::Vector2f contactPoint;
	Eigen::Vector2f normal;
	float penetrationDepth;
	bool hasCollision = false; //Indicate if a collsion has occurred

};




class CollisionDetector {
public:
	//Checks if two entities are colliding and returning collsion data
	CollisionInfo checkCollision(const Entity& entityA, const Entity& entityB);

	//Resloves the collision bsaed on collision data
	void resolveCollsion(Entity& entityA, Entity& entityB);


private:

	//Helper function to calculate contact point
	Eigen::Vector2f calculateContactPoint(const Entity& entityA, Entity& entityB);

	//Helper funciton to calculate collision normal
	Eigen::Vector2f calculateNormal(const Entity& entityA, const Entity& entityB);

	//Helper function to calculate penetration depth
	float calculatePenetrationDepth(const Entity& entityA, const Entity& entityB);
};



#endif // !COLLISIONDETECTOR_H

