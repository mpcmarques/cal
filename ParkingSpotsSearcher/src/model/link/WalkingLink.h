//
// Created by Mateus Pedroza on 12/04/18.
//

#ifndef PARKINGSPOTSSEARCHER_WALKINGLINK_H
#define PARKINGSPOTSSEARCHER_WALKINGLINK_H

#include "Link.h"

class WalkingLink : public Link {
public:
    WalkingLink(long id, long node1_id, long node2_id);

    LinkType getType() const;
};


#endif //PARKINGSPOTSSEARCHER_WALKINGLINK_H
