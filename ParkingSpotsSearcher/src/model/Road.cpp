//
// Created by mateus on 05/04/18.
//

#include "Road.h"

Road::Road(long id, std::string road_name, bool is_two_way) {
    this->id = id;
    this->name = road_name;
    this->is_two_way = is_two_way;
}

const std::string &Road::getName() const {
    return name;
}

long Road::getId() const {
    return id;
}

bool Road::isIs_two_way() const {
    return is_two_way;
}
