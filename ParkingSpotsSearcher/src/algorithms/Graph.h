/*
 * Graph.h
 *
 *  Created on: 03.04.2018
 *      Author: Adam
 */

#ifndef SRC_GRAPH_H_
#define SRC_GRAPH_H_

#include "Vertex.h"
#include <map>
#include <vector>
#include <stdlib.h>
#include <iostream>

template<class T> class Vertex;
template<class T> class Dijkstra;

template<class T> class Graph {
	std::map<int, Vertex<T> *> vertices; //do not change to unordered_map
public:
	Vertex<T> *getVertex(int id);

	bool addVertex(int id, VertexType type, int info = 0);

	bool addEdge(int sourceId, int destId, double weight, double cost = 0);

	bool vertexExists(int id);

	std::vector<Vertex<T> *> getVertexSet() const;

	Graph<T> copyGraphWithOffset(int offset) const;
	std::vector<Vertex<T> *> copyVertexSet() const;

	std::vector<Vertex<T> *> getTwoLayeredVertexSet() const;


	std::vector<Vertex<T> *> getThreeLayeredVertexSet() const;
};

template<class T>
Vertex<T> *Graph<T>::getVertex(int id) {
	if (!vertexExists(id))
		return nullptr;
	return vertices[id];
}

template<class T>
bool Graph<T>::addVertex(int id, VertexType type, int info) {
	if (vertexExists(id))
		return false;

	if (info == 0)
		info = id;
	vertices[id] = new Vertex<T> { id, type, info };
	return true;
}

template<class T>
bool Graph<T>::addEdge(int sourceId, int destId, double weight, double cost) {
	if (!vertexExists(sourceId) || !vertexExists(destId))
		return false;
	vertices[sourceId]->addEdge(vertices[destId], weight, cost);
	return true;
}

template<class T>
bool Graph<T>::vertexExists(int id) {
	return vertices.find(id) != vertices.end();
}

template<class T>
std::vector<Vertex<T> *> Graph<T>::getVertexSet() const {
	std::vector<Vertex<T> *> vertexSet;
	for (auto it = vertices.begin(); it != vertices.end(); ++it) {
		vertexSet.push_back(it->second);
	}

	return vertexSet;
}

template<class T>
std::vector<Vertex<T> *> Graph<T>::getTwoLayeredVertexSet() const {
	int size = vertices.size();

		std::vector<Vertex<T> *> setA = getVertexSet();
		std::vector<Vertex<T> *> setB = copyVertexSet();

		std::vector<Vertex<T> *> setC;

		for(int i = 0; i < size; ++i ){
			setB[i]->highest = true;
			if(setB[i]->type == VertexType::PARKING_SPOT)
				setA[i]->addEdge(setB[i], 0, 0);
			setC.push_back(setA[i]);
			setC.push_back(setB[i]);
		}

		return setC;
}



template<class T>
std::vector<Vertex<T> *> Graph<T>::copyVertexSet() const {
	Graph newGraph { };
	for (auto it = vertices.begin(); it != vertices.end(); ++it)
		newGraph.addVertex(it->second->getId(), it->second->getType(),
				it->second->info);

	for (auto it = vertices.begin(); it != vertices.end(); ++it) {
		int newId { it->second->getId() };
		for (auto edge : it->second->edges)
			newGraph.addEdge(newId, edge->dest->id, edge->weight,
					edge->cost);
	}
	return newGraph.getVertexSet();
}



template<class T>
std::vector<Vertex<T> *> Graph<T>::getThreeLayeredVertexSet() const {
	int size = vertices.size();

	std::vector<Vertex<T> *> setA = getVertexSet();
	std::vector<Vertex<T> *> setB = copyVertexSet();
	std::vector<Vertex<T> *> setC = copyVertexSet();

	std::vector<Vertex<T> *> setD;

	for(int i = 0; i < size; ++i ){
		setC[i]->highest = true;
		if(setB[i]->type == VertexType::GAS_STATION)
			setA[i]->addEdge(setB[i], 0, 0);
		if(setA[i]->type == VertexType::PARKING_SPOT)
			setB[i]->addEdge(setC[i], 0, 0);

		setD.push_back(setA[i]);
		setD.push_back(setB[i]);
		setD.push_back(setC[i]);
	}

	return setD;
}

#endif /* SRC_GRAPH_H_ */

