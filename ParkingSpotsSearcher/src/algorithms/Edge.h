/*
 * Edge.h
 *
 *  Created on: 03.04.2018
 *      Author: Adam
 */

#ifndef SRC_EDGE_H_
#define SRC_EDGE_H_

template <class V, class E> class Vertex;
template <class V, class E> class Graph;
template <class V, class E> class Dijkstra;

template <class V, class E> class Edge {
    double weight;
    double cost;
    E info;
    Vertex<V, E> *dest;
public:
    Edge(Vertex<V, E> *dest, double weight, E info, double cost) : dest{dest}, weight{weight}, info{info}, cost{cost} {}

    Vertex<V, E> *getDest() const { return dest; }

    //friend class Vertex;

    friend class Graph<V, E>;
    friend class Dijkstra<V, E>;
};

#endif /* SRC_EDGE_H_ */
