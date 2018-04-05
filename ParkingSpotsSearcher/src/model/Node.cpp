//
// Created by mateus on 05/04/18.
//

#include "Node.h"

Node::Node(int id, int latitude_degrees, int longitude_degrees, int latitude_radians, int longitude_radians) {
    this->id = id;
    this->latitude_degrees = latitude_degrees;
    this->latitude_radians = latitude_radians;
    this->longitude_radians = longitude_radians;
    this->longitute_degrees = longitude_degrees;
}
