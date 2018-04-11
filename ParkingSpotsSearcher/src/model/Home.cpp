//
// Created by Mateus Pedroza on 11/04/18.
//

#include "Home.h"

Home::Home(long id, double latitude_degrees, double longitude_degrees) : Node(id, latitude_degrees,
                                                                              longitude_degrees) {}

NodeType Home::getType() const {
    return HOME;
}
