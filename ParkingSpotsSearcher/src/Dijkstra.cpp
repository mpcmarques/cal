/*
 * Dijkstra.cpp
 *
 *  Created on: 04.04.2018
 *      Author: Adam
 */

#include "Dijkstra.h"
#include <limits>
#include <algorithm>

#define INF std::numeric_limits<double>::max()

Vertex* Dijkstra::initSingleSource(int origin) {
	for (auto v : vertexSet) {
		v->dist = INF;
		v->path = nullptr;
	}
	auto s = findVertex(origin);
	s->dist = 0;
	return s;
}

bool Dijkstra::relax(Vertex* v, Vertex* w, double weight) {
	if (v->dist + weight < w->dist) {
		w->dist = v->dist + weight;
		w->path = v;
		return true;
	} else
		return false;
}

void Dijkstra::compute(int origin) {
	auto s = initSingleSource(origin);
	MutablePriorityQueue<Vertex> q { };
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

Vertex * Dijkstra::findVertex(int in) const {
	for (auto v : vertexSet)
		if (v->id == in)
			return v;
	return nullptr;
}

std::vector<int> Dijkstra::getPath(int origin, int dest) {
	std::vector<int> res;
	auto v = findVertex(dest);
	if (v == nullptr || v->dist == INF) // missing or disconnected
	return res;
	for (; v != nullptr; v = v->path)
		res.push_back(v->id);
	std::reverse(res.begin(), res.end());
	return res;
}
