//
// Created by Mateus Pedroza on 10/04/18.
//

#include "ParkingGarage.h"

ParkingGarage::ParkingGarage(long id, double latitude_degrees, double longitude_degrees, int cost) : Node(id, latitude_degrees,
                                                                                              longitude_degrees) {
    this->cost = cost;
}

NodeType ParkingGarage::getType() const {
    return PARKING_GARAGE;
}

int ParkingGarage::getCost() const {
    return cost;
}
