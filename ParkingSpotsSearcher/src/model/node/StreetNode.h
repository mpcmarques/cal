//
// Created by Mateus Pedroza on 10/04/18.
//

#ifndef PARKINGSPOTSSEARCHER_STREETNODE_H
#define PARKINGSPOTSSEARCHER_STREETNODE_H


#include "node/Node.h"

class StreetNode : public Node {
public:
    StreetNode(long id, double latitude_degrees, double longitude_degrees);

    NodeType getType() const;
};


#endif //PARKINGSPOTSSEARCHER_STREETNODE_H
