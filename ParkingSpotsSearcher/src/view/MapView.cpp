//
// Created by Mateus Pedroza on 09/04/18.
//

#include "Map.h"
#include "MapView.h"


void MapView::initialize() {
    gv->createWindow(this->mapSize, this->mapSize);
}

MapView::MapView(int mapSize) {
    this->mapSize = mapSize;
    this->gv = new GraphViewer(this->mapSize, this->mapSize, false);

    // map definitions
    this->gv->defineVertexSize(5);
    this->gv->setBackground("../maps/map.png");
    this->gv->defineEdgeCurved(false);
    this->gv->defineEdgeColor(BLACK);
    this->gv->defineVertexColor(YELLOW);
}

void MapView::showMap(Map map){



    this->gv->rearrange();
}
