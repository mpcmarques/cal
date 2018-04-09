//
// Created by mateus on 05/04/18.
//

#ifndef PARKINGSPOTSSEARCHER_NODE_H
#define PARKINGSPOTSSEARCHER_NODE_H


class Node {

private:
    long id;
    float latitude;
    float longitute;

public:
    Node(long id, float latitude_degrees, float longitude_degrees);

    long getId() const;

    float getLatitude() const;

    float getLongitute() const;
};


#endif //PARKINGSPOTSSEARCHER_NODE_H
