//
// Created by mateus on 05/04/18.
//

#include "Node.h"

Node::Node(long id, float latitude_degrees, float longitude_degrees) {
    this->id = id;
    this->latitude = latitude_degrees;
    this->longitute = longitude_degrees;
}

long Node::getId() const {
    return id;
}

float Node::getLatitude() const {
    return latitude;
}

float Node::getLongitute() const {
    return longitute;
}
