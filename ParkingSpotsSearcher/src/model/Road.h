//
// Created by mateus on 05/04/18.
//

#ifndef PARKINGSPOTSSEARCHER_ROAD_H
#define PARKINGSPOTSSEARCHER_ROAD_H

#include <string>

class Road {
private:
    std::string name;
    int id;
    bool is_two_way;

public:
    Road(int id, std::string road_name, bool is_two_way);

    const std::string &getName() const;

    int getId() const;

    bool isIs_two_way() const;
};


#endif //PARKINGSPOTSSEARCHER_ROAD_H
