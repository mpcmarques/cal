//
// Created by Mateus Pedroza on 09/04/18.
//

#include "Map.h"
#include "ParkingSpotSearcherBuilder.h"
#include <link/StreetLink.h>
#include <link/WalkingLink.h>
#include <KmpMatcher.h>
#include <EditDistance.h>

#include <utility>


Map::Map(long mapSize, std::map<long, Node *> nodes, std::map<long, Road> roads, std::vector<Link *> links) {
    this->nodes = std::move(nodes);
    this->roads = std::move(roads);
    this->links = std::move(links);
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

const Node *Map::getNodeByRoad(const Road &road) {

    std::vector<Link *> links = getLinksByRoad(road);

    Link *link = links.front();

    Node *node = this->nodes[link->getNode1_id()];

    return node;
}

std::vector<Link *> Map::getLinksByRoad(const Road &road) {
    std::vector<Link *> links;

    for (auto link: this->links) {
        if (link->getId() == road.getId()) {
            links.push_back(link);
        }
    }

    return links;
}


std::vector<Road> Map::findStreetName(const int mode, const std::string &text) {
    std::vector<Road> roads;

    for (auto pair: this->getRoads()) {
        // search mode
        switch (mode) {
            case 1: // kmp-matcher - exact search
                if (KmpMatcher::matches(pair.second.getName(), text))
                    roads.push_back(pair.second);
                else if (KmpMatcher::matches(getNodeByRoad(pair.second)->getDistrict(), text))
                    roads.push_back(pair.second);
                break;
            case 2: // approximate - TODO: edit distance should be dynamic?
                if (EditDistance::calculate(pair.second.getName(), text) < 3)
                    roads.push_back(pair.second);
                else if (EditDistance::calculate(getNodeByRoad(pair.second)->getDistrict(), text) < 3)
                    roads.push_back(pair.second);
                break;
            default:
                break;
        }
    }

    return roads;
}
