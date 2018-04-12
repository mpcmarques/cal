//
// Created by mateus on 05/04/18.
//

#include "Link.h"

Link::Link(long id, long node1_id, long node2_id) {
    this->id = id;
    this->node1_id = node1_id;
    this->node2_id = node2_id;
}

long Link::getId() const {
    return id;
}

long Link::getNode1_id() const {
    return node1_id;
}

long Link::getNode2_id() const {
    return node2_id;
}


