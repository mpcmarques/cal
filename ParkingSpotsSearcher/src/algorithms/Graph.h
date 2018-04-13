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
#include <algorithm>
#include <cfloat>

#define COST_C 0.09 //1.5 EUR * 6 l/100km * 1/100 km

template<class V, class E> class Vertex;
template<class V, class E> class Dijkstra;

template<class V, class E> class Graph {
    std::map<long, Vertex<V, E> *> vertices; //do not change to unordered_map
public:
    Vertex<V, E> *getVertex(long id);

    bool addVertex(long id, VertexType type, V info, double cost);

    bool addEdge(long sourceId, long destId, double weight, E info, double cost =
			0);

    bool vertexExists(long id);

	std::vector<Vertex<V, E> *> getVertexSet() const;
	std::vector<Vertex<V, E> *> getAsUndirectedSet() const;

    Graph<V, E> copyGraphWithOffset(long offset) const;
	std::vector<Vertex<V, E> *> copyVertexSet() const;

    std::vector<Vertex<V, E> *> getTwoLayeredVertexSet(long dist, long range,
			bool weightAsCost) const;

    std::vector<Vertex<V, E> *> getThreeLayeredVertexSet(long dist, long range,
			bool weightAsCost) const;
};

template<class V, class E>
Vertex<V, E> *Graph<V, E>::getVertex(long id) {
	if (!vertexExists(id))
		return nullptr;
	return vertices[id];
}

template<class V, class E>
bool Graph<V, E>::addVertex(long id, VertexType type, V info, double cost) {
	if (vertexExists(id))
		return false;

	vertices[id] = new Vertex<V, E> { id, type, info, cost };
	return true;
}

template<class V, class E>
bool Graph<V, E>::addEdge(long sourceId, long destId, double weight, E info,
		double cost) {
	if (!vertexExists(sourceId) || !vertexExists(destId))
		return false;
	vertices[sourceId]->addEdge(vertices[destId], weight, info, cost);
	return true;
}

template<class V, class E>
bool Graph<V, E>::vertexExists(long id) {
	return vertices.find(id) != vertices.end();
}

template<class V, class E>
std::vector<Vertex<V, E> *> Graph<V, E>::getVertexSet() const {
	std::vector<Vertex<V, E> *> vertexSet;
	for (auto it = vertices.begin(); it != vertices.end(); ++it) {
		vertexSet.push_back(it->second);
	}

	return vertexSet;
}

template<class V, class E>
std::vector<Vertex<V, E> *> Graph<V, E>::getTwoLayeredVertexSet(long dist,
        long range, bool weightAsCost) const {
    long size = vertices.size();

	std::vector<Vertex<V, E> *> setA = copyVertexSet();
	std::vector<Vertex<V, E> *> setB = getAsUndirectedSet();

	Dijkstra<V, E> d { getAsUndirectedSet() };
    std::vector<long> parkingSpotsInRange = d.findInRageWithType(dist, range,
			VertexType::PARKING_SPOT);

	if (weightAsCost) {
		for (auto v : setA)
			for (auto e : v->edges)
				e->weight = e->weight * COST_C;
		for (auto v : setB)
			for (auto e : v->edges)
				e->weight = 0.0001; //if weight is 0 result can be unexpected. Parking spot can be not the closest one. DBL_MIN doesnt work
	}

	std::vector<Vertex<V, E> *> setC;

    for (long i = 0; i < size; ++i) {
		setB[i]->highest = true;
		bool is_in = std::find(parkingSpotsInRange.begin(),
				parkingSpotsInRange.end(), setB[i]->id)
				!= parkingSpotsInRange.end();
		if (is_in) {
			double cost = weightAsCost ? setA[i]->cost : 0;
			setA[i]->addEdge(setB[i], cost, NULL, 0);
		}
		setC.push_back(setA[i]);
		setC.push_back(setB[i]);
	}

	return setC;
}

template<class V, class E>
std::vector<Vertex<V, E> *> Graph<V, E>::getThreeLayeredVertexSet(long dist,
        long range, bool weightAsCost) const {
    long size = vertices.size();

	std::vector<Vertex<V, E> *> setA = copyVertexSet();
	std::vector<Vertex<V, E> *> setB = copyVertexSet();
	std::vector<Vertex<V, E> *> setC = getAsUndirectedSet();

	Dijkstra<V, E> d { getAsUndirectedSet() };
    std::vector<long> parkingSpotsInRange = d.findInRageWithType(dist, range,
			VertexType::PARKING_SPOT);

	if (weightAsCost) {
		for (auto v : setA)
			for (auto e : v->edges)
				e->weight = e->weight * COST_C;
		for (auto v : setB)
			for (auto e : v->edges)
				e->weight = e->weight * COST_C;
		for (auto v : setC)
			for (auto e : v->edges)
				e->weight = 0.0001;
	}

	std::vector<Vertex<V, E> *> setD;

    for (long i = 0; i < size; ++i) {
		setC[i]->highest = true;
		if (setB[i]->type == VertexType::GAS_STATION)
			setA[i]->addEdge(setB[i], 0, NULL, 0);

		bool is_in = std::find(parkingSpotsInRange.begin(),
				parkingSpotsInRange.end(), setA[i]->id)
				!= parkingSpotsInRange.end();
		if (is_in) {
			double cost = weightAsCost ? setA[i]->cost : 0;
			setB[i]->addEdge(setC[i], cost, NULL, 0);

		}
		setD.push_back(setA[i]);
		setD.push_back(setB[i]);
		setD.push_back(setC[i]);
	}

	return setD;
}

template<class V, class E>
std::vector<Vertex<V, E> *> Graph<V, E>::copyVertexSet() const {
	Graph<V, E> newGraph { };
	for (auto it = vertices.begin(); it != vertices.end(); ++it)
		newGraph.addVertex(it->second->getId(), it->second->getType(),
				it->second->info, it->second->cost);

	for (auto it = vertices.begin(); it != vertices.end(); ++it) {
        long newId { it->second->getId() };
		for (auto edge : it->second->edges)
			newGraph.addEdge(newId, edge->dest->id, edge->weight, edge->info,
					edge->cost);
	}
	return newGraph.getVertexSet();
}

template<class V, class E>
std::vector<Vertex<V, E> *> Graph<V, E>::getAsUndirectedSet() const {
	Graph<V, E> newGraph { };
	for (auto it = vertices.begin(); it != vertices.end(); ++it)
		newGraph.addVertex(it->second->getId(), it->second->getType(),
				it->second->info, it->second->cost);

	for (auto it = vertices.begin(); it != vertices.end(); ++it) {
        long newId { it->second->getId() };
		for (auto edge : it->second->edges) {
			newGraph.addEdge(newId, edge->dest->id, edge->weight, edge->info,
					edge->cost);
			newGraph.addEdge(edge->dest->id, newId, edge->weight, edge->info,
					edge->cost); //opposite direction
		}
	}
	return newGraph.copyVertexSet();
}

#endif /* SRC_GRAPH_H_ */

