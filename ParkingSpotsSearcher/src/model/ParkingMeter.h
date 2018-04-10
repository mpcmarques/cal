//
// Created by Mateus Pedroza on 10/04/18.
//

#ifndef PARKINGSPOTSSEARCHER_PARKINGMETER_H
#define PARKINGSPOTSSEARCHER_PARKINGMETER_H


#include "Node.h"

class ParkingMeter : public Node{
public:
    ParkingMeter(long id, float latitude_degrees, float longitude_degrees);

    NodeType  getType() const;
};


#endif //PARKINGSPOTSSEARCHER_PARKINGMETER_H
