//
// Created by Mateus Pedroza on 12/04/18.
//

#ifndef PARKINGSPOTSSEARCHER_APPLICATION_H_H
#define PARKINGSPOTSSEARCHER_APPLICATION_H_H

#include <../view/MapView.h>
#include <Map.h>

class Application {

private:
    MapView *view;
    Map *model;

    const long UNIVERSITY_NODE_ID = 11;
    const long MALL_NODE_ID = 10;
    const long HOME_NODE_ID = 12;

    int chooseGasStation();

    int chooseNearestOrCheapest();

    Road searchStreetByName();

    Road selectRoadFound(vector<Road> roads);

    int choosePreselectedPoint();

    void addGasStations(Map *map);

    void addParkingSpots(Map *map);

    void addParkingMeters(Map *map);

    Node *getNodeFromLocation(int opt, const Map *map);

    void addOtherPoints(Map *map);

    vector<Node *>
    calculatePath(Map *map, const Node *startingNode, const Node *endingNode, int near_or_cheap, int gas, int maxDistance);

    void handleLocationSearch();

    int chooseTextSearchMode();

    void handleStreetNameSearch();

public:
    Application();

    void run();

    int chooseMaxDistance();

};

#endif //PARKINGSPOTSSEARCHER_APPLICATION_H_H
