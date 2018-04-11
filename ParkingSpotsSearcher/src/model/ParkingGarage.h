//
// Created by Mateus Pedroza on 10/04/18.
//

#ifndef PARKINGSPOTSSEARCHER_PARKINGGARAGE_H
#define PARKINGSPOTSSEARCHER_PARKINGGARAGE_H

#include "Node.h"

class ParkingGarage : public Node {

public:
    ParkingGarage(long id, double latitude_degrees, double longitude_degrees);

    NodeType getType() const;

};


#endif //PARKINGSPOTSSEARCHER_PARKINGGARAGE_H
