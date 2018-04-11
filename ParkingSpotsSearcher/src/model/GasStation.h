//
// Created by Mateus Pedroza on 09/04/18.
//

#ifndef PARKINGSPOTSSEARCHER_GASSTATION_H
#define PARKINGSPOTSSEARCHER_GASSTATION_H


#include "Node.h"

class GasStation : public Node {
public:
    GasStation(long id, double latitude_degrees, double longitude_degrees);

    NodeType  getType() const;
};


#endif //PARKINGSPOTSSEARCHER_GASSTATION_H
