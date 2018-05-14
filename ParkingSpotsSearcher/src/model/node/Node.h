//
// Created by mateus on 05/04/18.
//

#ifndef PARKINGSPOTSSEARCHER_NODE_H
#define PARKINGSPOTSSEARCHER_NODE_H

#include <string>

/* abstract class */

enum NodeType {
    PARKING_GARAGE, STREET, GAS_STATION, PARKING_LANE, MALL, UNIVERSITY, HOME
};

class Node {

private:
    long id;
    double latitude;
    double longitute;
    std::string district;

    std::string parseDistrict(double latitude, double longitude);
public:
    Node(long id, double latitude_degrees, double longitude_degrees);

    long getId() const;

    std::string getDistrict() const;

    double getLatitude() const;

    double getLongitute() const;

    virtual NodeType getType() const = 0;
};

#endif //PARKINGSPOTSSEARCHER_NODE_H
