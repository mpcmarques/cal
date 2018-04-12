//
// Created by Mateus Pedroza on 09/04/18.
//

#include "GasStation.h"

GasStation::GasStation(long id, double latitude_degrees, double longitude_degrees) : Node(id, latitude_degrees, longitude_degrees) {

}

NodeType GasStation::getType() const {
    return GAS_STATION;
}
