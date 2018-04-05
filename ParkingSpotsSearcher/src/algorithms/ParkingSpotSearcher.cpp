/*
 * ParkingSpotSearcher.cpp
 *
 *  Created on: 04.04.2018
 *      Author: Adam
 */

#include "ParkingSpotSearcher.h"
#include <iostream>
#include <sstream>

bool ParkingSpotSearcher::addVertex(int id, VertexType type) {
	return graph.addVertex(id, type, id);
}

bool ParkingSpotSearcher::addEdge(int sourceId, int destId, double weight,
		double cost) {
	return graph.addEdge(sourceId, destId, weight);
}

std::string ParkingSpotSearcher::printShortestPath(int sourceId, int destId) {
	Dijkstra<int> dijkstra { graph.getTwoLayeredVertexSet() };
	dijkstra.compute(sourceId);

	std::vector<int> path = dijkstra.getPath(sourceId, graph.calculateSecondLayerId(destId));

	std::stringstream ss;
	for (unsigned int i = 0; i < path.size(); i++)
		ss << path[i] << " ";

	return ss.str();
}
//int main() {
//    return 0;
//}

