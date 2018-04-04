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
#include "MutablePriorityQueue.h"

enum class VertexType {
	NONE, PARKING_SPOT, GASS_STATION
};
class Vertex {
	std::vector<Edge *> edges;
	int id;
	VertexType type;
	int queueIndex = 0; 		// required by MutablePriorityQueue
	double dist = 0;
	Vertex *path = nullptr;



public:
	Vertex(int id, VertexType type) : id { id }, type { type } {}
	bool operator<(Vertex & vertex) const; // // required by MutablePriorityQueue


	void addEdge(Vertex *destination, double weight, double cost);

	Vertex *getPath() const {return path;};
	int getId() const { return id; };
	VertexType getType() const { return type; };
	std::vector<Edge *> getEdges() const {return edges;};

	friend class Dijkstra;
	friend class MutablePriorityQueue<Vertex>;


};
#endif /* SRC_VERTEX_H_ */
