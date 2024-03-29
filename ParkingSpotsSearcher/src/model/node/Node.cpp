//
// Created by mateus on 05/04/18.
//

#include "Node.h"

Node::Node(long id, double latitude_degrees, double longitude_degrees) {
    this->id = id;
    this->latitude = latitude_degrees;
    this->longitute = longitude_degrees;
    this->district = parseDistrict(latitude_degrees, longitude_degrees);
}

std::string Node::parseDistrict(double latitude, double longitude) {
    if (latitude < 41.17505 && longitude < -8.59065) {
        return "south west";
    } else if (latitude < 41.17505 && longitude > -8.59065) {
        return "south east";
    } else if (latitude > 41.17505 && longitude < -8.59065) {
        return "north west";
    } else {
        return "north east";
    }
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

std::string Node::getDistrict() const {
    return district;
}

