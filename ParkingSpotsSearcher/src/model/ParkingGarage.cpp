//
// Created by Mateus Pedroza on 10/04/18.
//

#include "ParkingGarage.h"

ParkingGarage::ParkingGarage(long id, double latitude_degrees, double longitude_degrees) : Node(id, latitude_degrees,
                                                                                              longitude_degrees) {

}

NodeType ParkingGarage::getType() const {
    return PARKING_GARAGE;
}
