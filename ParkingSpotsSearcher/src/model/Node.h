//
// Created by mateus on 05/04/18.
//

#ifndef PARKINGSPOTSSEARCHER_NODE_H
#define PARKINGSPOTSSEARCHER_NODE_H

/* abstract class */

enum NodeType {
    PARKING_GARAGE, STREET, GAS_STATION, PARKING_LANE, MALL, UNIVERSITY
};

class Node {

private:
    long id;
    double latitude;
    double longitute;

public:
    Node(long id, double latitude_degrees, double longitude_degrees);

    long getId() const;

    double getLatitude() const;

    double getLongitute() const;

    virtual NodeType getType() const = 0;
};

#endif //PARKINGSPOTSSEARCHER_NODE_H
