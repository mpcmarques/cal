//
// Created by Mateus Pedroza on 09/04/18.
//

#include "Map.h"
#include "ParkingSpotSearcherBuilder.h"
#include "node/ParkingGarage.h"
#include "node/ParkingMeter.h"
#include <math.h>
#include <link/StreetLink.h>
#include <link/WalkingLink.h>


Map::Map(int mapSize, std::map<int, Node *> nodes, std::map<int, Road> roads, std::vector<Link *> links) {
    this->nodes = nodes;
    this->roads = roads;
    this->links = links;
    this->mapSize = mapSize;
    this->parkingSpotSearcher = (new ParkingSpotSearcherBuilder(this))->build();
}

std::vector<Node *> Map::findShortestPath(int sourceId, int destId, int maxDistance, bool visitGasStation) {
    return this->parkingSpotSearcher->findShortestPath(sourceId, destId, maxDistance, visitGasStation);
}

int Map::getMapSize() const {
    return mapSize;
}


const std::map<int, Road> &Map::getRoads() const {
    return roads;
}

const std::map<int, Node *> &Map::getNodes() const {
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
    for(auto node: this->getNodes()){
        free(node.second);
    }
}

void Map::addRoad(long fromNodeId, long toNodeId) {
    long roadId = this->roads.size();
    this->roads.insert(std::pair<int, Road>(roadId, Road(roadId, "", true)));
    this->links.push_back(new StreetLink(roadId, fromNodeId, toNodeId));
}

void Map::addWalkingPath(long fromNodeId, long toNodeId){
    long roadId = this->roads.size();
    this->roads.insert(std::pair<int, Road>(roadId, Road(roadId, "", true)));
    this->links.push_back(new WalkingLink(roadId, fromNodeId, toNodeId));
}

void Map::addNode(Node *node){
    this->nodes.insert(std::pair<int, Node *>(node->getId(), node));
}
