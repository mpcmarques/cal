//
// Created by Mateus Pedroza on 12/04/18.
//

#ifndef PARKINGSPOTSSEARCHER_APPLICATION_H_H
#define PARKINGSPOTSSEARCHER_APPLICATION_H_H

class Application {
private:
    const long UNIVERSITY_NODE_ID = 11;
    const long MALL_NODE_ID = 10;
    const long HOME_NODE_ID = 12;

    int chooseGasStation();

    int chooseNearestOrCheapest();

    int chooseStartingPoint();

    int chooseEndingPoint();

    void addGasStations(Map *map);

    void addParkingSpots(Map *map);

    void addParkingMeters(Map *map);

    Node *getNodeFromLocation(int opt, const Map *map);

    void addOtherPoints(Map *map);

    vector<Node *> calculatePath(Map *map, Node * startingNode, Node * endingNode, int near_or_cheap, int gas, int maxDistance);


public:
    Application();

    void start();

    int chooseMaxDistance();
};

#endif //PARKINGSPOTSSEARCHER_APPLICATION_H_H
