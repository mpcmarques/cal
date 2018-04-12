//
// Created by Mateus Pedroza on 11/04/18.
//

#ifndef PARKINGSPOTSSEARCHER_SHOPPINGMALL_H
#define PARKINGSPOTSSEARCHER_SHOPPINGMALL_H

#include "node/Node.h"

class ShoppingMall : public Node{

public:
    ShoppingMall(long id, double latitude_degrees, double longitude_degrees);

    NodeType getType() const;
};


#endif //PARKINGSPOTSSEARCHER_SHOPPINGMALL_H
