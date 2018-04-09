//
// Created by Mateus Pedroza on 09/04/18.
//

#ifndef PARKINGSPOTSSEARCHER_MAPVIEW_H
#define PARKINGSPOTSSEARCHER_MAPVIEW_H


#include <graphviewer.h>
#include "Map.h"

class MapView {

private:
    GraphViewer *gv;
    Map *map;

public:
    MapView(Map *map);

    void initialize();

    void close();

    void updateView();
};


#endif //PARKINGSPOTSSEARCHER_MAPVIEW_H
