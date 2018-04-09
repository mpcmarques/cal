/*
 * Vertex.h
 *
 *  Created on: 03.04.2018
 *      Author: Adam
 */

#ifndef SRC_VERTEX_H_
#define SRC_VERTEX_H_

#include "Edge.h"
#include <vector>
#include "../utils/MutablePriorityQueue.h"

enum class VertexType {
	NONE, PARKING_SPOT, GAS_STATION
};

template <class V, class E> class Graph;
template <class V, class E> class Dijkstra;

template<class V, class E> class Vertex {
	bool highest = false;
	std::vector<Edge<V, E> *> edges;
	int id;
	V info;
	VertexType type;
	int queueIndex = 0;        // required by MutablePriorityQueue
	double dist = 0;
	double cost = 0;
	Vertex<V, E> *path = nullptr;

public:

	Vertex<V, E>(int id, VertexType type, V info, double cost) :
			id { id }, type { type }, info { info }, cost{cost} {
	}

	Vertex<V, E>(Vertex<V, E> *vertex) :
			id { vertex->id }, type { vertex->type }, info { vertex->info } {
	}

	void addEdge(Vertex<V, E> *destination, double weight, E info, double cost = 0) {
		edges.push_back(new Edge<V, E> { destination, weight, info, cost });
	}

	bool operator<(Vertex<V, E> & vertex) const {
		return this->dist < vertex.dist;
	}

	Vertex<V, E> *getPath() const {
		return path;
	}

	int getId() const {
		return id;
	}

	V getInfo() const {
		return info;
	}

	VertexType getType() const {
		return type;
	}

	std::vector<Edge<V, E> *> getEdges() const {
		return edges;
	}

	friend class Dijkstra<V, E>;
	friend class Graph<V, E>;
	friend class MutablePriorityQueue<Vertex<V, E>> ;

};

#endif /* SRC_VERTEX_H_ */
