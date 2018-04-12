//
// Created by Mateus Pedroza on 12/04/18.
//

#include "StreetLink.h"

StreetLink::StreetLink(long id, long node1_id, long node2_id) : Link(id, node1_id, node2_id) {}

LinkType StreetLink::getType() const {
    return STREET_LINK;
}
