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

#include <iostream>
#include <sstream>

template<class V, class E>
class ParkingSpotSearcher {
	Graph<V, E> graph { };

public:
	bool addVertex(int id, VertexType type, V info);
	bool addEdge(int sourceId, int destId, double weight, E info);
	std::vector<V> findShortestPath(int sourceId, int destId, int maxDistance,
			bool visitGasStation = false);
	std::string printShortestPath(int sourceId, int destId);
	std::string printShortestPathWithGasStation(int sourceId, int destId);
};


template<class V, class E>
bool ParkingSpotSearcher<V,E>::addVertex(int id, VertexType type, V info) {
	return graph.addVertex(id, type, info);
}

template<class V, class E>
bool ParkingSpotSearcher<V,E>::addEdge(int sourceId, int destId, double weight, E info) {
	return graph.addEdge(sourceId, destId, weight, info);
}

template<class V, class E>
std::string ParkingSpotSearcher<V,E>::printShortestPath(int sourceId,
		int destId) {
	std::vector<V> path = findShortestPath(sourceId, destId, 100, false);

	std::stringstream ss;
	for (unsigned int i = 0; i < path.size(); i++)
		ss << path[i] << " ";

	return ss.str();
}

template<class V, class E>
std::vector<V> ParkingSpotSearcher<V,E>::findShortestPath(int sourceId,
		int destId, int maxDistance, bool visitGasStation) {
	std::vector<Vertex<V, E>*> set = visitGasStation?graph.getThreeLayeredVertexSet(destId,
			maxDistance):graph.getTwoLayeredVertexSet(destId,
			maxDistance);

	Dijkstra<V,E> dijkstra { set };
	dijkstra.compute(sourceId);
	return dijkstra.getPath(sourceId, destId);

}

template<class V, class E>
std::string ParkingSpotSearcher<V,E>::printShortestPathWithGasStation(
		int sourceId, int destId) {

	std::vector<V> path = findShortestPath(sourceId, destId, 100, true);

	std::stringstream ss;
	for (unsigned int i = 0; i < path.size(); i++)
		ss << path[i] << " ";
	return ss.str();
}

#endif /* SRC_PARKINGSPOTSEARCHER_H_ */
