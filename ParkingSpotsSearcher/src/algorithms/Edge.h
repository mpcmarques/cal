/*
 * Edge.h
 *
 *  Created on: 03.04.2018
 *      Author: Adam
 */

#ifndef SRC_EDGE_H_
#define SRC_EDGE_H_

template <class T> class Vertex;
template <class T> class Graph;
template <class T> class Dijkstra;

template <class T> class Edge {
    double weight;
    double cost;
    Vertex<T> *dest;
public:
    Edge(Vertex<T> *dest, double weight, double cost) : dest{dest}, weight{weight}, cost{cost} {}

    Vertex<T> *getDest() const { return dest; }

    //friend class Vertex;

    friend class Graph<T>;
    friend class Dijkstra<T>;
};

#endif /* SRC_EDGE_H_ */
