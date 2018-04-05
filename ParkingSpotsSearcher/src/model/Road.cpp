//
// Created by mateus on 05/04/18.
//

#include "Road.h"

Road::Road(int id, std::string road_name, bool is_two_way) {
    this->id = id;
    this->name = road_name;
    this->is_two_way = is_two_way;
}
