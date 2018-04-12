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
    int mapSize;
    std::map<int, Node *> nodes;
    std::map<int, Road> roads;
    std::vector<Link *> links;
    ParkingSpotSearcher<Node *, int> * parkingSpotSearcher;
public:
    const std::vector<Link *, std::allocator<Link *>> &getLinks() const;

    Map(int mapSize, std::map<int, Node *> nodes, std::map<int, Road> roads, std::vector<Link *> links);

    std::vector<Node *> findShortestPath(int sourceId, int destId, int maxDistance, bool visitGasStation);
    std::vector<Node *> findCheapestPath(int sourceId, int destId, int maxDistance, bool visitGasStation);

    const std::map<int, Node *> &getNodes() const;

    const std::map<int, Road> &getRoads() const;

    int getMapSize() const;

    void addRoad(long fromNodeId, long toNodeId);

    void destroy();

    void addNode(Node *node);

    void addWalkingPath(long fromNodeId, long toNodeId);
};


#endif //PARKINGSPOTSSEARCHER_MAP_H
