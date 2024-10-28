#pragma once

#ifndef GEOMETRY_H
#define GEOMETRY_H

#include <iostream>
#include <cmath>
#include <vector>
#include <string> //Include for std::string

class Geometry {

public: 

	virtual ~Geometry() = default;

	//Calculate the area of the shape
	virtual float area() const = 0;

	//Calculate the perimeter of the shape
	virtual float perimeter() const = 0;

	//Get the name of the shape
	virtual std::string name()const = 0;

	//Checks if a point is within the shape
	bool contains(float x, float y) const;

	//Moves the shape
	void translate(float dx, float dy);
};

#endif // !GEOMETRY_H

