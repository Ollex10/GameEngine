#pragma once

#ifndef CONTACT_H
#define CONTACT_H

#include  "Geometry/Geometry.h"
#include "Dense"
#include "RigidBody.h"

class Contact {

public: 

	Contact(RigidBody* bodyA, RigidBody* bodyB);

	//Calculate normal, penetration, etc.
	void calculateContactProperties();

	//Resolve the collsion response
	void resolveCollision();


	//Getters for contact information
	const Eigen::Vector2f& getContactPoint() const;
	const Eigen::Vector2f& getNormal() const;
	RigidBody* getBodyA() const;
	RigidBody* getBodyB() const;
	float getPenetrationDepth() const;
	float getRestitution() const;

private: 

	//Pointer to the first rigid body
	RigidBody* bodyA;

	//Pointer to the second rigid body
	RigidBody* bodyB;

	//The contact point
	Eigen::Vector2f contactPoint;

	//Normal vector at the contact point
	Eigen::Vector2f normal;

	//Penetration depth
	float penetrationDepth;

	//Friction Coefficient
	float friction;

	//Restitution coefficient
	float restitution;


};







#endif