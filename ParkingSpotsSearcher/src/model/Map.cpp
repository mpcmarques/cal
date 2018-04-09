//
// Created by Mateus Pedroza on 09/04/18.
//

#include "Map.h"

Map::Map(int mapSize, double min_latitude, double max_latitude, double min_longitude, double max_longitude) {
    this->nodes = std::map<int, Node>();
    this->roads = std::map<int, Road>();
    this->links = std::vector<Link>();
    this->mapSize = mapSize;
    this->min_latitude = min_latitude;
    this->max_latitude = max_latitude;
    this->min_longitude = min_longitude;
    this->max_longitude = max_longitude;
}