//
// Created by mateus on 05/04/18.
//

#ifndef PARKINGSPOTSSEARCHER_NODE_H
#define PARKINGSPOTSSEARCHER_NODE_H


class Node {
    int id;
    int latitude_degrees;
    int longitute_degrees;
    int latitude_radians;
    int longitude_radians;


public:
    Node(int id, int latitude_degrees, int longitude_degrees, int latitude_radians, int longitude_radians);
};


#endif //PARKINGSPOTSSEARCHER_NODE_H
