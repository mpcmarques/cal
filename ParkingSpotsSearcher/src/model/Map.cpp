//
// Created by Mateus Pedroza on 09/04/18.
//

#include "Map.h"
#include "node/ParkingGarage.h"
#include "node/ParkingMeter.h"
#include <math.h>


Map::Map(int mapSize, std::map<int, Node *> nodes, std::map<int, Road> roads, std::vector<Link *> links) {
    this->nodes = nodes;
    this->roads = roads;
    this->links = links;
    this->mapSize = mapSize;

    for (auto node : nodes) {
        NodeType type = node.second->getType();
        if (type == NodeType::PARKING_GARAGE || type == NodeType::PARKING_LANE) {
            double cost = type == NodeType::PARKING_GARAGE ? ((ParkingGarage *) node.second)->getCost()
                                                           : ((ParkingMeter *) node.second)->getCost();
            this->parkingSpotSearcher.addVertex(node.first, VertexType::PARKING_SPOT, 0);
        }

        if (type == NodeType::GAS_STATION) {
            this->parkingSpotSearcher.addVertex(node.first, VertexType::GAS_STATION, node.second);
        } else
            this->parkingSpotSearcher.addVertex(node.first, VertexType::NONE, node.second);
    }

    for (auto link : links) {
        Road r = this->roads.at(link->getId());
        Node *n1 = this->nodes.at(link->getNode1_id());
        Node *n2 = this->nodes.at(link->getNode2_id());

        double distance = sqrt(
                pow(n1->getLatitude() - n2->getLatitude(), 2) + pow(n2->getLongitute() - n2->getLongitute(), 2));

        this->parkingSpotSearcher.addEdge(link->getNode1_id(), link->getNode2_id(), distance, link->getId());
        if (r.isIs_two_way())
            this->parkingSpotSearcher.addEdge(link->getNode2_id(), link->getNode1_id(), distance, link->getId());
    }
    //std::vector<Node *> path = parkingSpotSearcher.findShortestPath(432578849, 26122724, 20000, false);
    //std::cout << path.size() << std::endl;
}

std::vector<Node *> Map::findShortestPath(int sourceId, int destId, int maxDistance, bool visitGasStation) {
    return this->parkingSpotSearcher.findShortestPath(sourceId, destId, maxDistance, visitGasStation);
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
