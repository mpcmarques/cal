//
// Created by Mateus Pedroza on 12/04/18.
//

#ifndef PARKINGSPOTSSEARCHER_STREETLINK_H
#define PARKINGSPOTSSEARCHER_STREETLINK_H

#include "Link.h"

class StreetLink : public Link {
public:
    StreetLink(long id, long node1_id, long node2_id);
    LinkType  getType() const;
};


#endif //PARKINGSPOTSSEARCHER_STREETLINK_H
