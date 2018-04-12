//
// Created by Mateus Pedroza on 12/04/18.
//

#include "WalkingLink.h"

WalkingLink::WalkingLink(long id, long node1_id, long node2_id) : Link(id, node1_id, node2_id) {}

LinkType WalkingLink::getType() const {
    return WALK;
}
