/*
 * Dijkstra.h
 *
 *  Created on: 04.04.2018
 *      Author: Adam
 */

#ifndef SRC_DIJKSTRA_H_
#define SRC_DIJKSTRA_H_

#include "Vertex.h"
#include <vector>
#include <limits>
#include <algorithm>
//#include "MutablePriorityQueue.h"
#define INF std::numeric_limits<double>::max()

template <class V, class E> class Dijkstra {

    std::vector<Vertex<V,E> *> vertexSet;

public:
    Dijkstra<V,E>(std::vector<Vertex<V,E> *> vertexSet) : vertexSet{vertexSet} {};

    Vertex<V,E> *initSingleSource(long origin);

    bool relax(Vertex<V,E> *v, Vertex<V,E> *w, double weight);

    void compute(long origin);
    std::vector<long> findInRageWithType(long origin, long range, VertexType type);

    Vertex<V,E> *findVertex(long id) const;
    Vertex<V,E> *findHighestVertex(long id) const;

    std::vector<V> getPath(long origin, long dest);
    std::vector<Vertex<V,E> *> getVertexSet() const { return vertexSet; };
};

template <class V, class E>
Vertex<V,E> *Dijkstra<V,E>::initSingleSource(long origin) {
    for (auto v : vertexSet) {
        v->dist = INF;
        v->path = nullptr;
    }
    auto s = findVertex(origin);
    s->dist = 0;
    return s;
}

template <class V, class E>
bool Dijkstra<V,E>::relax(Vertex<V,E> *v, Vertex<V,E> *w, double weight) {
    if (v->dist + weight < w->dist) {
        w->dist = v->dist + weight;
        w->path = v;
        return true;
    } else
        return false;
}

template <class V, class E>
void Dijkstra<V,E>::compute(long origin) {
    auto s = initSingleSource(origin);
    MutablePriorityQueue<Vertex<V,E>> q{};
    q.insert(s);
    while (!q.empty()) {
        auto v = q.extractMin();
        for (auto e : v->edges) {
            auto oldDist = e->dest->dist;
            if (relax(v, e->dest, e->weight)) {
                if (oldDist == INF)
                    q.insert(e->dest);
                else
                    q.decreaseKey(e->dest);
            }
        }
    }
}

template <class V, class E>
std::vector<long> Dijkstra<V,E>::findInRageWithType(long origin, long range, VertexType type) {
    auto s = initSingleSource(origin);
    MutablePriorityQueue<Vertex<V,E>> q{};
    std::vector<long> closest{};
    q.insert(s);
    while (!q.empty()) {
        auto v = q.extractMin();
        for (auto e : v->edges) {
            auto oldDist = e->dest->dist;
            if(v->dist > range)
            	continue;
            if (relax(v, e->dest, e->weight)) {
                if (oldDist == INF){
                	q.insert(e->dest);
                	if(e->dest->type == type)
                		closest.push_back(e->dest->id);
                }
                else
                    q.decreaseKey(e->dest);
            }
        }
    }
    return closest;
}

//possible improvement
template <class V, class E>
Vertex<V,E> *Dijkstra<V,E>::findVertex(long id) const {
    for (auto v : vertexSet){
        if (v->id == id)
            return v;
    }
    return nullptr;
}

//possible improvement
template <class V, class E>
Vertex<V,E> *Dijkstra<V,E>::findHighestVertex(long id) const {
    for (auto v : vertexSet)
        if (v->id == id and v->highest == true)
            return v;
    return nullptr;
}

template <class V, class E>
std::vector<V> Dijkstra<V,E>::getPath(long origin, long dest) {
    std::vector<V> res;
    auto v = findHighestVertex(dest);
    if (v == nullptr || v->dist == INF) // missing or disconnected
        return res;
    for (; v != nullptr; v = v->path)
        res.push_back(v->info);
    std::reverse(res.begin(), res.end());
    return res;
}


#endif /* SRC_DIJKSTRA_H_ */
