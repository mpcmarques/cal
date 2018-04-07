//
// Created by mateus on 07/04/18.
//

#ifndef PARKINGSPOTSSEARCHER_LATLONGCONVERTER_H
#define PARKINGSPOTSSEARCHER_LATLONGCONVERTER_H


class LatLongConverter {
public:
    static double convert(double coord, double minCoord, double maxCoord, int mapSize);
};


#endif //PARKINGSPOTSSEARCHER_LATLONGCONVERTER_H
