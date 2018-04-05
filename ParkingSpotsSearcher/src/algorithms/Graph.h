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

template <class T> class Vertex;
template <class T> class Dijkstra;


template <class T> class Graph {
    std::unordered_map<int, Vertex<T> *> vertices;

public:
    Vertex<T> *getVertex(int id);

    bool addVertex(int id, VertexType type, int info = 0);

    bool addEdge(int sourceId, int destId, double weight, double cost = 0);

    bool vertexExists(int id);

    std::vector<Vertex<T> *> getVertexSet() const;

    std::vector<Vertex<T> *> getTwoLayeredVertexSet() const;

    int calculateSecondLayerId(int id);

    int calculateFirstLayerId(int id);

    std::vector<Vertex<T> *> getThreeLayeredVertexSet() const;
};

template <class T>
Vertex<T> *Graph<T>::getVertex(int id) {
    if (!vertexExists(id))
        return nullptr;
    return vertices[id];
}

template <class T>
bool Graph<T>::addVertex(int id, VertexType type, int info) {
    if (vertexExists(id))
        return false;

    if (info == 0)
        info = id;
    vertices[id] = new Vertex<T>{id, type, info};
    return true;
}

template <class T>
bool Graph<T>::addEdge(int sourceId, int destId, double weight, double cost) {
    if (!vertexExists(sourceId) || !vertexExists(destId))
        return false;
    vertices[sourceId]->addEdge(vertices[destId], weight, cost);
    return true;
}

template <class T>
bool Graph<T>::vertexExists(int id) {
    return vertices.find(id) != vertices.end();
}

template <class T>
std::vector<Vertex<T> *> Graph<T>::getVertexSet() const {
    std::vector<Vertex<T> *> vertexSet;
    for (auto it = vertices.begin(); it != vertices.end(); ++it) {
        vertexSet.push_back(it->second);
    }

    return vertexSet;
}

template <class T>
std::vector<Vertex<T> *> Graph<T>::getTwoLayeredVertexSet() const {
    Graph newGraph{};

    int vertexNum = vertices.size();

    for (auto it = vertices.begin(); it != vertices.end(); ++it) {
        int newId{it->second->getId() + vertexNum};
        VertexType type = it->second->getType();
        newGraph.addVertex(newId, type, it->second->info);
    }
    for (auto it = vertices.begin(); it != vertices.end(); ++it) {
        VertexType type = it->second->getType();
        int newId{it->second->getId() + vertexNum};
        if (type == VertexType::PARKING_SPOT) {
            it->second->addEdge(newGraph.getVertex(newId), 0, 0);
        }

        for (auto edge : it->second->edges) {
            int newDestId{edge->dest->id + vertexNum};
            newGraph.addEdge(newId, newDestId, edge->weight, edge->cost);
        }
    }
    std::vector<Vertex<T> *> vertexSet = newGraph.getVertexSet();
    for (auto it = vertices.begin(); it != vertices.end(); ++it) {
        vertexSet.push_back(it->second);
    }
    return vertexSet;
}

template <class T>
int Graph<T>::calculateSecondLayerId(int id) {
    return id + vertices.size();
}

template <class T>
int Graph<T>::calculateFirstLayerId(int id) {
    return id % vertices.size();
}

//template <class T>
//std::vector<Vertex<int> *> Graph<T>::getThreeLayeredVertexSet() const {

//}

#endif /* SRC_GRAPH_H_ */


