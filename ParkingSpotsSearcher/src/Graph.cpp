/*
 * Graph.cpp
 *
 *  Created on: 03.04.2018
 *      Author: Adam
 */

#include "Graph.h"

Vertex* Graph::getVertex(int id) {
	if(!vertexExists(id))
		return nullptr;
	return vertices[id];
}

bool Graph::addVertex(int id, VertexType type) {
	if(vertexExists(id))
		return false;

	vertices[id] = new Vertex { id, type };
	return true;
}

bool Graph::addEdge(int sourceId, int destId, double weight, double cost) {
	if(!vertexExists(sourceId) || !vertexExists(destId))
		return false;
	vertices[sourceId] -> addEdge(vertices[destId], weight, cost);
	return true;
}

bool Graph::vertexExists(int id) {
	return vertices.find(id) != vertices.end();
}

std::vector<Vertex*> Graph::getVertexSet() const {
	std::vector<Vertex *> vertexSet;
	for(auto it = vertices.begin(); it != vertices.end(); ++it)
		vertexSet.push_back(it->second);

	return vertexSet;
}
