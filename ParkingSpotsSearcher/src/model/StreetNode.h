//
// Created by Mateus Pedroza on 10/04/18.
//

#ifndef PARKINGSPOTSSEARCHER_STREETNODE_H
#define PARKINGSPOTSSEARCHER_STREETNODE_H


#include "Node.h"

class StreetNode : public Node {
public:
    StreetNode(long id, float latitude_degrees, float longitude_degrees);

    NodeType getType() const;
};


#endif //PARKINGSPOTSSEARCHER_STREETNODE_H
