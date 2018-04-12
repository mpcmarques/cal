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

    void addGasStations(map<int, Node *> &nodes);

    void addParkingSpots(map<int, Node *> &nodes);

    void addParkingMeters(map<int, Node *> &nodes);

public:
    Application();

    void start();

    void addOtherPoints(map<int, Node *> &nodes);

    Node *getNodeFromLocation(int opt, map<int, Node *> nodes);
};

#endif //PARKINGSPOTSSEARCHER_APPLICATION_H_H
