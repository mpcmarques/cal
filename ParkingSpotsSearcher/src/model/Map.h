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
    int mapSize;
    std::map<int, Node> nodes;
    std::map<int, Road> roads;
    std::vector<Link> links;

public:
    Map(int mapSize, std::map<int, Node> nodes, std::map<int,Road> roads, std::vector<Link> links);

    void setNodes(const std::map<int, Node> &nodes);

    void setRoads(const std::map<int, Road> &roads);

    void setLinks(const std::vector<Link, std::allocator<Link>> &links);

    const std::map<int, Node> &getNodes() const;

    const std::map<int, Road> &getRoads() const;

    const std::vector<Link, std::allocator<Link>> &getLinks() const;

    int getMapSize() const;
};


#endif //PARKINGSPOTSSEARCHER_MAP_H
