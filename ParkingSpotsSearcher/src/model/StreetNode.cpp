//
// Created by Mateus Pedroza on 10/04/18.
//

#include "StreetNode.h"

StreetNode::StreetNode(long id, float latitude_degrees, float longitude_degrees) : Node(id, latitude_degrees,
                                                                                        longitude_degrees) {

}

NodeType StreetNode::getType() const {
    return STREET;
}

