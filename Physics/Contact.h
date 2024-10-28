#pragma once

#ifndef CONTACT_H
#define CONTACT_H

#include  "Geometry/Geometry.h"
#include "Dense"

class RigidBody;

class Contact {

public: 

	Contact(RigidBody* bodyA, RigidBody* bodyB);

	//Calculate normal, penetration, etc.
	void calculateContactProperties();

	//Resolve the collsion response
	void resolveCollision();


	//Getters for contact information
	const Eigen::Vector3f& getContactPoint() const;
	const Eigen::Vector3f& getNormal() const;
	float getPenetrationDepth() const;

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