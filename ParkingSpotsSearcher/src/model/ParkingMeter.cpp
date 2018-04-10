//
// Created by Mateus Pedroza on 10/04/18.
//

#include "ParkingMeter.h"

ParkingMeter::ParkingMeter(long id, float latitude_degrees, float longitude_degrees) : Node(id, latitude_degrees,
                                                                                            longitude_degrees) {

}

NodeType ParkingMeter::getType() const {
    return PARKING_LANE;
}
