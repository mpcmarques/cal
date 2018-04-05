/*
 * ParkingSpotSearcher.h
 *
 *  Created on: 04.04.2018
 *      Author: Adam
 */

#ifndef SRC_PARKINGSPOTSEARCHER_H_
#define SRC_PARKINGSPOTSEARCHER_H_

#include "Graph.h"
#include "Dijkstra.h"

class ParkingSpotSearcher {
	Graph<int> graph { };

public:
	bool addVertex(int id, VertexType type);
	bool addEdge(int sourceId, int destId, double weight, double cost = 0);
	std::string printShortestPath(int sourceId, int destId);
};

#endif /* SRC_PARKINGSPOTSEARCHER_H_ */
