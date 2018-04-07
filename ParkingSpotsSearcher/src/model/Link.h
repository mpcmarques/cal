//
// Created by mateus on 05/04/18.
//

#ifndef PARKINGSPOTSSEARCHER_LINK_H
#define PARKINGSPOTSSEARCHER_LINK_H


class Link {

private:
    long id;
    long node1_id;
    long node2_id;

public:
    Link(long id, long node1_id, long node2_id);

    long getId() const;

    long getNode1_id() const;

    long getNode2_id() const;
};


#endif //PARKINGSPOTSSEARCHER_LINK_H
