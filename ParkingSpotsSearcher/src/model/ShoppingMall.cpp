//
// Created by Mateus Pedroza on 11/04/18.
//

#include "ShoppingMall.h"

ShoppingMall::ShoppingMall(long id, double latitude_degrees, double longitude_degrees) : Node(id, latitude_degrees,
                                                                                            longitude_degrees) {}

NodeType ShoppingMall::getType() const {
    return MALL;
}
