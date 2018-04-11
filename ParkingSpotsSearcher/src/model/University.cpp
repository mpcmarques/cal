//
// Created by Mateus Pedroza on 11/04/18.
//

#include "University.h"

University::University(long id, double latitude_degrees, double longitude_degrees) : Node(id, latitude_degrees,
                                                                                        longitude_degrees) {}

NodeType University::getType() const {
    return UNIVERSITY;
}
