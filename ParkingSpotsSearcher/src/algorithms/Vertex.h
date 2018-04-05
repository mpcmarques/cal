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
#include "utils/MutablePriorityQueue.h"

enum class VertexType {
	NONE, PARKING_SPOT, GAS_STATION
};

template <class T> class Graph;
template <class T> class Dijkstra;

template<class T> class Vertex {
	std::vector<Edge<T> *> edges;
	int id;
	T info;
	VertexType type;
	int queueIndex = 0;        // required by MutablePriorityQueue
	double dist = 0;
	Vertex<T> *path = nullptr;

public:

	Vertex<T>(int id, VertexType type, T info) :
			id { id }, type { type }, info { info } {
	}

	Vertex<T>(Vertex<T> *vertex) :
			id { vertex->id }, type { vertex->type }, info { vertex->info } {
	}

	void addEdge(Vertex<T> *destination, double weight, double cost) {
		edges.push_back(new Edge<T> { destination, weight, cost });
	}

	bool operator<(Vertex<T> & vertex) const {
		return this->dist < vertex.dist;
	}

	Vertex<T> *getPath() const {
		return path;
	}

	int getId() const {
		return id;
	}

	T getInfo() const {
		return info;
	}

	VertexType getType() const {
		return type;
	}

	std::vector<Edge<T> *> getEdges() const {
		return edges;
	}

	friend class Dijkstra<T>;
	friend class Graph<T>;
	friend class MutablePriorityQueue<Vertex<T>> ;

};

#endif /* SRC_VERTEX_H_ */
