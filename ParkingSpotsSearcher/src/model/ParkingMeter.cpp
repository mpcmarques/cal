//
// Created by Mateus Pedroza on 10/04/18.
//

#include "ParkingMeter.h"

ParkingMeter::ParkingMeter(long id, double latitude_degrees, double longitude_degrees, int cost) : Node(id, latitude_degrees,
                                                                                            longitude_degrees) {
    this->cost = cost;
}

NodeType ParkingMeter::getType() const {
    return PARKING_LANE;
}

int ParkingMeter::getCost() const {
    return this->cost;
}
