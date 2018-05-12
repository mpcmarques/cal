//
// Created by Mateus Pedroza on 09/04/18.
//

#include "Map.h"
#include "ParkingSpotSearcherBuilder.h"
#include <link/StreetLink.h>
#include <link/WalkingLink.h>
#include <KmpMatcher.h>
#include <EditDistance.h>


Map::Map(long mapSize, std::map<long, Node *> nodes, std::map<long, Road> roads, std::vector<Link *> links) {
    this->nodes = nodes;
    this->roads = roads;
    this->links = links;
    this->mapSize = mapSize;

}

std::vector<Node *> Map::findShortestPath(long sourceId, long destId, long maxDistance, bool visitGasStation) {
    this->parkingSpotSearcher = (new ParkingSpotSearcherBuilder(this))->build();
    return this->parkingSpotSearcher->findShortestPath(sourceId, destId, maxDistance, visitGasStation);
}

std::vector<Node *> Map::findCheapestPath(long sourceId, long destId, long maxDistance, bool visitGasStation) {
    this->parkingSpotSearcher = (new ParkingSpotSearcherBuilder(this))->build();
    return this->parkingSpotSearcher->findShortestPath(sourceId, destId, maxDistance, visitGasStation);
}

long Map::getMapSize() const {
    return mapSize;
}


const std::map<long, Road> &Map::getRoads() const {
    return roads;
}

const std::map<long, Node *> &Map::getNodes() const {
    return nodes;
}

const std::vector<Link *, std::allocator<Link *>> &Map::getLinks() const {
    return links;
}

void Map::destroy() {
    // free all links
    for (auto link : this->getLinks()) {
        free(link);
    }
    // free all nodes
    for (auto node: this->getNodes()) {
        free(node.second);
    }
}

void Map::addRoad(long fromNodeId, long toNodeId) {
    long roadId = this->roads.size();
    this->roads.insert(std::pair<long, Road>(roadId, Road(roadId, "", true)));
    this->links.push_back(new StreetLink(roadId, fromNodeId, toNodeId));
}

void Map::addWalkingPath(long fromNodeId, long toNodeId) {
    long roadId = this->roads.size();
    this->roads.insert(std::pair<long, Road>(roadId, Road(roadId, "", true)));
    this->links.push_back(new WalkingLink(roadId, fromNodeId, toNodeId));
}

void Map::addNode(Node *node) {
    this->nodes.insert(std::pair<long, Node *>(node->getId(), node));
}

const Node* Map::getNodeByRoad(const Road &road){
    Link* link = this->links[road.getId()];

    Node *node = this->nodes[link->getNode1_id()];

    return node;
}

std::vector<Road> Map::findStreetName(const int mode, const std::string &text) {
    std::vector<Road> roads;

    for (auto pair: this->getRoads()) {
        // kmp-matcher -> exact
        if (mode == 1 && KmpMatcher::matches(pair.second.getName(), text)) {
            roads.push_back(pair.second);
        } else if (
                mode == 2
                && // TODO: edit distance should be dynamic?
                EditDistance::calculate(pair.second.getName(), text) < 3) {
            // approximate
            roads.push_back(pair.second);
        }
    }

    return roads;
}
