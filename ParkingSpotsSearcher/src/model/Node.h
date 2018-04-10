//
// Created by mateus on 05/04/18.
//

#ifndef PARKINGSPOTSSEARCHER_NODE_H
#define PARKINGSPOTSSEARCHER_NODE_H

/* abstract class */

enum NodeType {
    PARKING_GARAGE, STREET, GAS_STATION, PARKING_LANE
};

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

    virtual NodeType getType() const = 0;
};

#endif //PARKINGSPOTSSEARCHER_NODE_H
