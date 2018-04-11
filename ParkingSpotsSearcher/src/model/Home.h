//
// Created by Mateus Pedroza on 11/04/18.
//

#ifndef PARKINGSPOTSSEARCHER_HOME_H
#define PARKINGSPOTSSEARCHER_HOME_H


#include "Node.h"

class Home : public Node {
public:
    Home(long id, double latitude_degrees, double longitude_degrees);
    NodeType  getType() const;
};


#endif //PARKINGSPOTSSEARCHER_HOME_H
