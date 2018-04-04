/*
 * Edge.h
 *
 *  Created on: 03.04.2018
 *      Author: Adam
 */

#ifndef SRC_EDGE_H_
#define SRC_EDGE_H_

class Vertex;

class Edge {
	double weight;
	double cost;
	Vertex *dest;
public:
	Edge(Vertex *dest, double weight, double cost): dest{dest}, weight{weight}, cost{cost} {}
	friend class Vertex;
	friend class Dijkstra;
};

#endif /* SRC_EDGE_H_ */
