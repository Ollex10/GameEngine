#pragma once

#ifndef ENTITY_H
#define ENTITY_H

#include "RigidBody.h"
#include "Geometry/Geometry.h"
#include <memory>
#include <math.h>

struct b2FixtureDef;
typedef float float32;

enum BodyType {
	staticBody = 0,
	kinematicBody,
	dynamicBody

	
};

struct BodyDefine {

	BodyDefine() {
		userData = nullptr;
		position = Eigen::Vector2f(0.0f, 0.0f);
		angle = 0.0f;
		linearVelocity = Eigen::Vector2f(0.0f, 0.0f);
		angularVelocity = 0.0f;
		linearDamping = 0.0f;
		allowSleep = true;
		fixedRotation = false;
		bullet = false;
		type = BodyType::staticBody;
		isActive = true;
		gravityScale = 1.0f;
	}

	BodyType type;
	Eigen::Vector2f position;
	float32 angle;
	Eigen::Vector2f linearVelocity;
	float32 angularVelocity;
	float32 linearDamping;
	float32 angularDamping;

	bool allowSleep;
	bool awake;
	bool fixedRotation;
	bool bullet;
	bool isActive;
	void* userData;
	float32 gravityScale;




};




#endif //!ENITYT_H

