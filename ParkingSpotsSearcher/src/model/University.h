//
// Created by Mateus Pedroza on 11/04/18.
//

#ifndef PARKINGSPOTSSEARCHER_UNIVERSITY_H
#define PARKINGSPOTSSEARCHER_UNIVERSITY_H


#include "Node.h"

class University : public Node {
public:
    University(long id, float latitude_degrees, float longitude_degrees);
    NodeType  getType() const;
};


#endif //PARKINGSPOTSSEARCHER_UNIVERSITY_H
