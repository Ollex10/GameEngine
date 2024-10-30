#pragma once

#ifndef GEOMETRY_H
#define GEOMETRY_H

#include <iostream>
#include <cmath>
#include <vector>
#include<dense>
#include <string> //Include for std::string

class Geometry {

public: 

	virtual ~Geometry() = default;

	//Calculate the area of the shape
	virtual float computeArea() const = 0;

	//Calculate the perimeter of the shape
	virtual float perimeter() const = 0;

	//Get the name of the shape
	virtual std::string name()const = 0;

	//Checks if a point is within the shape
	virtual bool contains(float x, float y) const;

	//Transfrom the geotmetry using a matrix
	virtual void transform(const Eigen::Matrix2f& matrix)=0;

	virtual void draw() const = 0;
	virtual Eigen::Vector2f getBoundingBoxMin() const = 0;
	virtual Eigen::Vector2f getBoundingBoxMax() const = 0;
};

#endif // !GEOMETRY_H

