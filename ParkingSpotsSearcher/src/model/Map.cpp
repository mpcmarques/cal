//
// Created by Mateus Pedroza on 09/04/18.
//

#include "Map.h"

Map::Map(int mapSize, std::map<int, Node> nodes, std::map<int, Road> roads, std::vector<Link> links) {
    this->nodes = nodes;
    this->roads = roads;
    this->links = links;
    this->mapSize = mapSize;
    this->gasStations = std::map<int, GasStation>();
}

int Map::getMapSize() const {
    return mapSize;
}

void Map::setNodes(const std::map<int, Node> &nodes) {
    Map::nodes = nodes;
}

void Map::setRoads(const std::map<int, Road> &roads) {
    Map::roads = roads;
}

void Map::setLinks(const std::vector<Link, std::allocator<Link>> &links) {
    Map::links = links;
}

const std::map<int, Road> &Map::getRoads() const {
    return roads;
}

const std::vector<Link, std::allocator<Link>> &Map::getLinks() const {
    return links;
}

const std::map<int, Node> &Map::getNodes() const {
    return nodes;
}

void Map::addGasStation(const GasStation station) {
    this->gasStations.insert(std::pair<int,GasStation>(station.getId(), station));
}

const std::map<int, GasStation> &Map::getGasStations() const {
    return gasStations;
}
