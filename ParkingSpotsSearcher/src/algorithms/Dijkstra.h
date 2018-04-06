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

template <class T> class Dijkstra {

    std::vector<Vertex<T> *> vertexSet;

public:
    Dijkstra<T>(std::vector<Vertex<T> *> vertexSet) : vertexSet{vertexSet} {};

    Vertex<T> *initSingleSource(int origin);

    bool relax(Vertex<T> *v, Vertex<T> *w, double weight);

    void compute(int origin);

    Vertex<T> *findVertex(int id) const;
    Vertex<T> *findHighestVertex(int id) const;

    std::vector<T> getPath(int origin, int dest);
    std::vector<Vertex<T> *> getVertexSet() const { return vertexSet; };
};

template <class T>
Vertex<T> *Dijkstra<T>::initSingleSource(int origin) {
    for (auto v : vertexSet) {
        v->dist = INF;
        v->path = nullptr;
    }
    auto s = findVertex(origin);
    s->dist = 0;
    return s;
}

template <class T>
bool Dijkstra<T>::relax(Vertex<T> *v, Vertex<T> *w, double weight) {
    if (v->dist + weight < w->dist) {
        w->dist = v->dist + weight;
        w->path = v;
        return true;
    } else
        return false;
}

template <class T>
void Dijkstra<T>::compute(int origin) {
    auto s = initSingleSource(origin);
    MutablePriorityQueue<Vertex<T>> q{};
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

//possible improvement
template <class T>
Vertex<T> *Dijkstra<T>::findVertex(int id) const {
    for (auto v : vertexSet)
        if (v->id == id)
            return v;
    return nullptr;
}

//possible improvement
template <class T>
Vertex<T> *Dijkstra<T>::findHighestVertex(int id) const {
    for (auto v : vertexSet)
        if (v->id == id and v->highest == true)
            return v;
    return nullptr;
}

template <class T>
std::vector<T> Dijkstra<T>::getPath(int origin, int dest) {
    std::vector<T> res;
    auto v = findHighestVertex(dest);
    if (v == nullptr || v->dist == INF) // missing or disconnected
        return res;
    for (; v != nullptr; v = v->path)
        res.push_back(v->info);
    std::reverse(res.begin(), res.end());
    return res;
}


#endif /* SRC_DIJKSTRA_H_ */
