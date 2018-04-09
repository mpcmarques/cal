//
// Created by Mateus Pedroza on 09/04/18.
//

#ifndef PARKINGSPOTSSEARCHER_MAPVIEW_H
#define PARKINGSPOTSSEARCHER_MAPVIEW_H


#include <graphviewer.h>

class MapView {

private:
    GraphViewer *gv;
    int mapSize;

public:
    MapView(int mapSize);
    void initialize();

    void showMap(Map map);
};


#endif //PARKINGSPOTSSEARCHER_MAPVIEW_H
