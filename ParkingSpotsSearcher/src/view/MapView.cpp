//
// Created by Mateus Pedroza on 09/04/18.
//

#include <LatLongConverter.h>
#include "MapView.h"

void MapView::initialize() {

    this->gv = new GraphViewer(map->getMapSize(), map->getMapSize(), false);

    // map definitions
    this->gv->defineVertexSize(5);
    this->gv->setBackground("../maps/map.png");
    this->gv->defineEdgeCurved(false);
    this->gv->defineEdgeColor(BLACK);
    this->gv->defineVertexColor(YELLOW);

    gv->createWindow(map->getMapSize(), map->getMapSize());

    this->updateView();
}

MapView::MapView(Map *map) {
    this->map = map;
}

void MapView::add(Node node){
    /* fix window position */
    double x = LatLongConverter::convert(node.getLongitute(), MAX_LONGITUDE, MIN_LONGITUDE,
                                         this->map->getMapSize());
    double y = LatLongConverter::convert(node.getLatitude(), MAX_LATITUDE, MIN_LATITUDE,
                                         this->map->getMapSize());

    /* add node do graph viewer */
    gv->addNode((int) node.getId(), (int) (x * 0.89), (int) (y * 0.85));
}

void MapView::updateView() {

    if (gv != nullptr) {

        /* show nodes */
        for (auto pair: this->map->getNodes()) {
            Node node = pair.second;
            this->add(node);
        }

        /* show edges */
        for (int i = 0; i < this->map->getLinks().size(); i++) {

            Link link = this->map->getLinks()[i];

            Road road = this->map->getRoads().at((int) link.getId());

            if (road.isIs_two_way())
                gv->addEdge(i, (int) link.getNode1_id(), (int) link.getNode2_id(), EdgeType::UNDIRECTED);
            else
                gv->addEdge(i, (int) link.getNode1_id(), (int) link.getNode2_id(), EdgeType::DIRECTED);

            gv->setEdgeThickness(i, 1);

        }

        /* show gas stations */
        for (auto pair: this->map->getGasStations()) {
            auto gasStation = pair.second;
            this->add(gasStation);

            gv->setVertexIcon((int) gasStation.getId(), "../images/gas_station.png");
            gv->setVertexLabel((int) gasStation.getId(), "Gas Station");
            gv->setVertexSize((int) gasStation.getId(), 30);
        }

        this->gv->rearrange();
    }
}

void MapView::close() {
    free(this->map);
    this->gv->closeWindow();
    free(this->gv);
}
