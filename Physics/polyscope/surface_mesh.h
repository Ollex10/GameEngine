#pragma once

#ifndef SURFACE_MESH_H
#define SURFACE_MESH_H

#include "Dense"
#include "vector"

class surface_mesh {

public:


	surface_mesh() = default;

	//Adds a vertext to the mesh
	void addVertex(const Eigen::Vector3f& vertex);

	//Adds a face to the mesh (defined by indices of vertices)
	void addFace(const std::vector<int>& faceIndices);

	//Render the mesh
	void render() const;

	//Calculate bounding box or sphere
	void calculateBoundingVolume();

private: 

private:
	std::vector<Eigen::Vector2f> vertices; // List of vertices
	std::vector<std::vector<int>> faces;    // List of faces, each face defined by vertex indices
	Eigen::Vector2f boundingBoxMin;         // Minimum corner of the bounding box
	Eigen::Vector2f boundingBoxMax;         // Maximum corner of the bounding box

};





#endif // !SURFACE_MESH_H

