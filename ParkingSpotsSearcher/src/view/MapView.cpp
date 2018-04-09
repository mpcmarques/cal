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

void MapView::updateView() {

    if (gv != nullptr) {
        /* map image position fix */
        double drift = -0.00258;
        double MAX_LATITUDE = 41.1805 + 0.0062;
        double MIN_LATITUDE = 41.1696 + 0.0062;
        double MIN_LONGITUDE = -8.5832 + drift;
        double MAX_LONGITUDE = -8.5983 + drift;

        /* show nodes */
        for (auto pair: this->map->getNodes()) {
            Node node = pair.second;
            double x = LatLongConverter::convert(node.getLongitute_degrees(), MAX_LONGITUDE, MIN_LONGITUDE, 800);
            double y = LatLongConverter::convert(node.getLatitude_degrees(), MAX_LATITUDE, MIN_LATITUDE, 800);

            gv->addNode((int) node.getId(), (int) (x * 0.89), (int) (y * 0.85));
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

        this->gv->rearrange();
    }
}

void MapView::close() {
    free(this->map);
    this->gv->closeWindow();
    free(this->gv);
}
