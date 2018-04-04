/*
 * Dijkstra.h
 *
 *  Created on: 04.04.2018
 *      Author: Adam
 */

#ifndef SRC_DIJKSTRA_H_
#define SRC_DIJKSTRA_H_

#include "Vertex.h"
#include <vector>
//#include "MutablePriorityQueue.h"

class Dijkstra {

	std::vector<Vertex *> vertexSet;

public:
	Dijkstra(std::vector<Vertex *> vertexSet) : vertexSet { vertexSet }{};
	Vertex * initSingleSource(int origin);
	bool relax(Vertex *v, Vertex *w, double weight);
	void compute(int origin);
	Vertex * findVertex(int in) const;
	std::vector<Vertex *> getPath(int origin, int dest);
	std::vector<Vertex *> getVertexSet() const {return vertexSet;};
};

#endif /* SRC_DIJKSTRA_H_ */
