//
// Created by Mateus Pedroza on 09/04/18.
//

#ifndef PARKINGSPOTSSEARCHER_MAPVIEW_H
#define PARKINGSPOTSSEARCHER_MAPVIEW_H


#include <graphviewer.h>
#include "Map.h"
#include <node/ParkingGarage.h>
#include <node/StreetNode.h>
#include <node/GasStation.h>
#include <unordered_set>

class MapView {

private:
    GraphViewer *gv;
    Map *map;

    /* map image position fix */
    double MAX_LATITUDE = 41.1805 + 0.0062;
    double MIN_LATITUDE = 41.1696 + 0.0062;
    double MIN_LONGITUDE = -8.5832 -0.00258;
    double MAX_LONGITUDE = -8.5983 -0.00258;

    void addNodeIntoView(const Node *node);

    void showNode(const Node *node);

    void showLink(const Link *link);

    int edges;

    std::unordered_set<std::string> nameCache;

public:
    MapView(Map *map);

    void initialize();

    void close();

    void updateView();

    void showPath(std::vector<Node *> vector);
};


#endif //PARKINGSPOTSSEARCHER_MAPVIEW_H
