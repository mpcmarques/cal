//
// Created by mateus on 05/04/18.
//

#ifndef PARKINGSPOTSSEARCHER_NODE_H
#define PARKINGSPOTSSEARCHER_NODE_H


class Node {

private:
    long id;
    float latitude_degrees;
    float longitute_degrees;
    float latitude_radians;
    float longitude_radians;


public:
    Node(long id, float latitude_degrees, float longitude_degrees, float latitude_radians, float longitude_radians);

    long getId() const;

    float getLatitude_degrees() const;

    float getLongitute_degrees() const;

    float getLatitude_radians() const;

    float getLongitude_radians() const;
};


#endif //PARKINGSPOTSSEARCHER_NODE_H
