/*
 * Graph.cpp
 *
 *  Created on: 03.04.2018
 *      Author: Adam
 */

#include "Graph.h"

Vertex* Graph::getVertex(int id) {
	if (!vertexExists(id))
		return nullptr;
	return vertices[id];
}

bool Graph::addVertex(int id, VertexType type, int info) {
	if (vertexExists(id))
		return false;

	if(info == 0)
		info = id;
	vertices[id] = new Vertex { id, type, info };
	return true;
}

bool Graph::addEdge(int sourceId, int destId, double weight, double cost) {
	if (!vertexExists(sourceId) || !vertexExists(destId))
		return false;
	vertices[sourceId]->addEdge(vertices[destId], weight, cost);
	return true;
}

bool Graph::vertexExists(int id) {
	return vertices.find(id) != vertices.end();
}

std::vector<Vertex*> Graph::getVertexSet() const {
	std::vector<Vertex *> vertexSet;
	for (auto it = vertices.begin(); it != vertices.end(); ++it) {
		vertexSet.push_back(it->second);
	}

	return vertexSet;
}

std::vector<Vertex*> Graph::getTwoLayeredVertexSet() const {
	Graph newGraph { };

	int vertexNum = vertices.size();

	for (auto it = vertices.begin(); it != vertices.end(); ++it) {
		int newId { it->second->getId() + vertexNum };
		VertexType type = it->second->getType();
		newGraph.addVertex(newId, type, it->second->info);
	}
	for (auto it = vertices.begin(); it != vertices.end(); ++it) {
		VertexType type = it->second->getType();
		int newId { it->second->getId() + vertexNum };
		if (type == VertexType::PARKING_SPOT) {
			it->second->addEdge(newGraph.getVertex(newId), 0, 0);
		}

		for (auto edge : it->second->edges) {
			int newDestId { edge->dest->id + vertexNum };
			newGraph.addEdge(newId, newDestId, edge->weight, edge->cost);
		}
	}
	std::vector<Vertex *> vertexSet = newGraph.getVertexSet();
	for (auto it = vertices.begin(); it != vertices.end(); ++it) {
		vertexSet.push_back(it->second);
	}
	return vertexSet;
}

int Graph::calculateSecondLayerId(int id) {
	return id+vertices.size();
}

int Graph::calculateFirstLayerId(int id) {
	return id%vertices.size();
}

std::vector<Vertex*> Graph::getThreeLayeredVertexSet() const {

}
