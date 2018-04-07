//
// Created by mateus on 07/04/18.
//

#include <cstdlib>
#include "LatLongConverter.h"

double LatLongConverter::convert(double coord, double maxCoord, int mapSize){
    return (mapSize * coord) / maxCoord;
}