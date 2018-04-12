//
// Created by mateus on 05/04/18.
//

#include "Node.h"

Node::Node(long id, double latitude_degrees, double longitude_degrees) {
    this->id = id;
    this->latitude = latitude_degrees;
    this->longitute = longitude_degrees;
}

long Node::getId() const {
    return id;
}

double Node::getLatitude() const {
    return latitude;
}

double Node::getLongitute() const {
    return longitute;
}

