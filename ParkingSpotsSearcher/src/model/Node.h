//
// Created by mateus on 05/04/18.
//

#ifndef PARKINGSPOTSSEARCHER_NODE_H
#define PARKINGSPOTSSEARCHER_NODE_H


class Node {

    long id;
    float latitude_degrees;
    float longitute_degrees;
    float latitude_radians;
    float longitude_radians;


public:
    Node(long id, float latitude_degrees, float longitude_degrees, float latitude_radians, float longitude_radians);
};


#endif //PARKINGSPOTSSEARCHER_NODE_H
