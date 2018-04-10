//
// Created by Mateus Pedroza on 10/04/18.
//

#include "ParkingGarage.h"

ParkingGarage::ParkingGarage(long id, float latitude_degrees, float longitude_degrees) : Node(id, latitude_degrees,
                                                                                              longitude_degrees) {

}

NodeType ParkingGarage::getType() const {
    return PARKING_GARAGE;
}
