//
// Created by mateus on 05/04/18.
//

#include "Node.h"

Node::Node(long id, float latitude_degrees, float longitude_degrees, float latitude_radians, float longitude_radians) {
    this->id = id;
    this->latitude_degrees = latitude_degrees;
    this->latitude_radians = latitude_radians;
    this->longitude_radians = longitude_radians;
    this->longitute_degrees = longitude_degrees;
}

long Node::getId() const {
    return id;
}

float Node::getLatitude_degrees() const {
    return latitude_degrees;
}

float Node::getLongitute_degrees() const {
    return longitute_degrees;
}

float Node::getLatitude_radians() const {
    return latitude_radians;
}

float Node::getLongitude_radians() const {
    return longitude_radians;
}
