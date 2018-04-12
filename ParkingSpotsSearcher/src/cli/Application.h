//
// Created by Mateus Pedroza on 12/04/18.
//

#ifndef PARKINGSPOTSSEARCHER_APPLICATION_H_H
#define PARKINGSPOTSSEARCHER_APPLICATION_H_H

class Application {
private:
    const int UNIVERSITY_NODE_ID = 11;
    const int MALL_NODE_ID = 10;
    const int HOME_NODE_ID = 12;

    int chooseGasStation();

    int chooseNearestOrCheapest();

    int chooseStartingPoint();

    int chooseEndingPoint();

    void addGasStations(Map *map);

    void addParkingSpots(Map *map);

    void addParkingMeters(Map *map);

    Node *getNodeFromLocation(int opt, map<int, Node *> nodes);

    void addOtherPoints(Map *map);

public:
    Application();

    void start();

    int chooseMaxDistance();
};

#endif //PARKINGSPOTSSEARCHER_APPLICATION_H_H
