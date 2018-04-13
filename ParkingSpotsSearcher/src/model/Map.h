//
// Created by Mateus Pedroza on 09/04/18.
//

#ifndef PARKINGSPOTSSEARCHER_MAP_H
#define PARKINGSPOTSSEARCHER_MAP_H


#include "node/Node.h"
#include "Road.h"
#include "link/Link.h"
#include "node/GasStation.h"
#include <map>
#include <vector>
#include <string>
#include <ParkingSpotSearcher.h>


class Map {

private:
    long mapSize;
    std::map<long, Node *> nodes;
    std::map<long, Road> roads;
    std::vector<Link *> links;
    ParkingSpotSearcher<Node *, long> * parkingSpotSearcher;
public:
    const std::vector<Link *, std::allocator<Link *>> &getLinks() const;

    Map(long mapSize, std::map<long, Node *> nodes, std::map<long, Road> roads, std::vector<Link *> links);

    std::vector<Node *> findShortestPath(long sourceId, long destId, long maxDistance, bool visitGasStation);
    std::vector<Node *> findCheapestPath(long sourceId, long destId, long maxDistance, bool visitGasStation);

    const std::map<long, Node *> &getNodes() const;

    const std::map<long, Road> &getRoads() const;

    long getMapSize() const;

    void addRoad(long fromNodeId, long toNodeId);

    void destroy();

    void addNode(Node *node);

    void addWalkingPath(long fromNodeId, long toNodeId);
};


#endif //PARKINGSPOTSSEARCHER_MAP_H
