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

void MapView::addNodeIntoView(Node &node){
    /* fix window position */
    double x = LatLongConverter::convert(node.getLongitute(), MAX_LONGITUDE, MIN_LONGITUDE,
                                         this->map->getMapSize());
    double y = LatLongConverter::convert(node.getLatitude(), MAX_LATITUDE, MIN_LATITUDE,
                                         this->map->getMapSize());

    /* add node do graph viewer */
    gv->addNode((int) node.getId(), (int) (x * 0.89), (int) (y * 0.85));
}

void MapView::add(Node *node){

    switch (node->getType()) {
        case GAS_STATION:
            gv->setVertexIcon((int) node->getId(), "../images/gas_station.png");
            gv->setVertexLabel((int) node->getId(), "Gas Station");
            gv->setVertexSize((int) node->getId(), 30);

            break;
        case PARKING_GARAGE:
            gv->setVertexIcon((int) node->getId(), "../images/parking.png");
            gv->setVertexLabel((int) node->getId(), "Parking Garage");
            gv->setVertexSize((int) node->getId(), 30);

            break;
        case PARKING_LANE:
            gv->setVertexIcon((int) node->getId(), "../images/parking_meter.png");
            gv->setVertexSize((int) node->getId(), 30);
            break;
        case MALL:
            gv->setVertexIcon((int) node->getId(), "../images/mall.png");
            gv->setVertexSize((int) node->getId(), 30);
            gv->setVertexLabel((int) node->getId(), "Shopping mall");

            break;
        case UNIVERSITY:
            gv->setVertexIcon((int) node->getId(), "../images/university.png");
            gv->setVertexSize((int) node->getId(), 30);
            gv->setVertexLabel((int) node->getId(), "University");

            break;
        case STREET:
            break;
        case HOME:
            gv->setVertexIcon((int) node->getId(), "../images/home.png");
            gv->setVertexSize((int) node->getId(), 30);
            gv->setVertexLabel((int) node->getId(), "Home");
            break;
        default:
            break;
    }

    this->addNodeIntoView(*node);
}

void MapView::updateView() {

    if (gv != nullptr) {

        /* show nodes */
        for (pair<int, Node *> pair: this->map->getNodes()) {
            this->add(pair.second);
        }

        /* show edges */
        for (int i = 0; i < this->map->getLinks().size(); i++) {

            Link link = this->map->getLinks()[i];

            Road road = this->map->getRoads().at((int) link.getId());

            if (road.isIs_two_way())
                gv->addEdge(i, (int) link.getNode1_id(), (int) link.getNode2_id(), EdgeType::UNDIRECTED);
            else
                gv->addEdge(i, (int) link.getNode1_id(), (int) link.getNode2_id(), EdgeType::DIRECTED);

            //gv->setEdgeThickness(i, 1);
            gv->setEdgeColor(i, GRAY);

        }

        this->gv->rearrange();
    }
}

void MapView::close() {
    // TODO: free all nodes memory in map model
    free(this->map);
    this->gv->closeWindow();
    free(this->gv);
}
