//
// Created by Mateus Pedroza on 10/04/18.
//

#ifndef PARKINGSPOTSSEARCHER_PARKINGMETER_H
#define PARKINGSPOTSSEARCHER_PARKINGMETER_H


#include "Node.h"

class ParkingMeter : public Node{
private:
    int cost;
public:
    ParkingMeter(long id, double latitude_degrees, double longitude_degrees, int cost);

    NodeType  getType() const;

    int getCost() const;
};


#endif //PARKINGSPOTSSEARCHER_PARKINGMETER_H
