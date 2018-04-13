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
    bool addVertex(long id, VertexType type, V info, double cost = 0);
    bool addEdge(long sourceId, long destId, double weight, E info);
    std::vector<V> findShortestPath(long sourceId, long destId, long maxDistance,
			bool visitGasStation = false);
    std::vector<V> findCheapestPath(long sourceId, long destId, long maxDistance,
				bool visitGasStation = false);
};


template<class V, class E>
bool ParkingSpotSearcher<V,E>::addVertex(long id, VertexType type, V info, double cost) {
	return graph.addVertex(id, type, info, cost);
}

template<class V, class E>
bool ParkingSpotSearcher<V,E>::addEdge(long sourceId, long destId, double weight, E info) {
	return graph.addEdge(sourceId, destId, weight, info);
}

template<class V, class E>
std::vector<V> ParkingSpotSearcher<V,E>::findShortestPath(long sourceId,
        long destId, long maxDistance, bool visitGasStation) {
	std::vector<Vertex<V, E>*> set = visitGasStation?graph.getThreeLayeredVertexSet(destId,
			maxDistance, false):graph.getTwoLayeredVertexSet(destId,
			maxDistance, false);

	Dijkstra<V,E> dijkstra { set };
	dijkstra.compute(sourceId);
	return dijkstra.getPath(sourceId, destId);

}

template<class V, class E>
std::vector<V> ParkingSpotSearcher<V,E>::findCheapestPath(long sourceId,
        long destId, long maxDistance, bool visitGasStation) {
	std::vector<Vertex<V, E>*> set = visitGasStation?graph.getThreeLayeredVertexSet(destId,
			maxDistance, true):graph.getTwoLayeredVertexSet(destId,
			maxDistance, true);

	Dijkstra<V,E> dijkstra { set };
	dijkstra.compute(sourceId);
	return dijkstra.getPath(sourceId, destId);

}

#endif /* SRC_PARKINGSPOTSEARCHER_H_ */
