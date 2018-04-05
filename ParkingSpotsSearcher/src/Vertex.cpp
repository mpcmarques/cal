/*
 * Vertex.cpp
 *
 *  Created on: 03.04.2018
 *      Author: Adam
 */

#include "Vertex.h"

void Vertex::addEdge(Vertex *destination, double weight, double cost) {
    edges.push_back(new Edge{destination, weight, cost});
}

bool Vertex::operator<(Vertex &vertex) const {
    return this->dist < vertex.dist;
}
