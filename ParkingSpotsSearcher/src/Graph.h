/*
 * Graph.h
 *
 *  Created on: 03.04.2018
 *      Author: Adam
 */

#ifndef SRC_GRAPH_H_
#define SRC_GRAPH_H_

#include "Vertex.h"
#include <unordered_map>
#include <vector>


class Graph {
    std::unordered_map<int, Vertex *> vertices;

public:
    Vertex *getVertex(int id);

    bool addVertex(int id, VertexType type, int info = 0);

    bool addEdge(int sourceId, int destId, double weight, double cost = 0);

    bool vertexExists(int id);

    std::vector<Vertex *> getVertexSet() const;

    std::vector<Vertex *> getTwoLayeredVertexSet() const;

    int calculateSecondLayerId(int id);

    int calculateFirstLayerId(int id);

    std::vector<Vertex *> getThreeLayeredVertexSet() const;
};

#endif /* SRC_GRAPH_H_ */
