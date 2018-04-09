//
// Created by Mateus Pedroza on 09/04/18.
//

#ifndef PARKINGSPOTSSEARCHER_MAP_H
#define PARKINGSPOTSSEARCHER_MAP_H


#include "Node.h"
#include "Road.h"
#include "Link.h"
#include <map>
#include <vector>
#include <string>

class Map {

private:
    double max_latitude;
    double min_latitude;
    double min_longitude;
    double max_longitude;
    int mapSize;

    std::map<int, Node> nodes;
    std::map<int, Road> roads;
    std::vector<Link> links;

public:
    Map(int mapSize, double min_latitude, double max_latitude, double min_longitude, double max_longitude);


};


#endif //PARKINGSPOTSSEARCHER_MAP_H
