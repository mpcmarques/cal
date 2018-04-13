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
    this->edges = 0;

    gv->createWindow(map->getMapSize(), map->getMapSize());

    this->updateView();
}

MapView::MapView(Map *map) {
    this->map = map;
}

void MapView::addNodeIntoView(const Node *node) {
    /* fix window position */
    double x = LatLongConverter::convert(node->getLongitute(), MAX_LONGITUDE, MIN_LONGITUDE,
                                         this->map->getMapSize());
    double y = LatLongConverter::convert(node->getLatitude(), MAX_LATITUDE, MIN_LATITUDE,
                                         this->map->getMapSize());

    /* add node do graph viewer */
    gv->addNode((int) node->getId(), (int) (x * 0.89), (int) (y * 0.85));
}

void MapView::showNode(const Node *node) {

    switch (node->getType()) {
        case NodeType::GAS_STATION:
            gv->setVertexIcon((int) node->getId(), "../images/gas_station.png");
            gv->setVertexLabel((int) node->getId(), "Gas Station");
            //gv->setVertexLabel((int) node->getId(), to_string(node->getId()));
            gv->setVertexSize((int) node->getId(), 30);

            break;
        case NodeType::PARKING_GARAGE:
            gv->setVertexIcon((int) node->getId(), "../images/parking.png");
            gv->setVertexLabel((int) node->getId(), "Parking Garage");
            //gv->setVertexLabel((int) node->getId(), to_string(node->getId()));
            gv->setVertexSize((int) node->getId(), 30);

            break;
        case NodeType::PARKING_LANE:
            gv->setVertexIcon((int) node->getId(), "../images/parking_meter.png");
            //gv->setVertexLabel((int) node->getId(), to_string(node->getId()));
            gv->setVertexSize((int) node->getId(), 30);
            break;
        case NodeType::MALL:
            gv->setVertexIcon((int) node->getId(), "../images/mall.png");
            gv->setVertexSize((int) node->getId(), 30);
            gv->setVertexLabel((int) node->getId(), "Shopping mall ");

            break;
        case NodeType::UNIVERSITY:
            gv->setVertexIcon((int) node->getId(), "../images/university.png");
            gv->setVertexSize((int) node->getId(), 30);
            gv->setVertexLabel((int) node->getId(), "University ");

            break;
        case NodeType::STREET:
            //gv->setVertexLabel((int) node->getId(), to_string(node->getId()));
            break;
        case NodeType::HOME:
            gv->setVertexIcon((int) node->getId(), "../images/home.png");
            gv->setVertexSize((int) node->getId(), 30);
            gv->setVertexLabel((int) node->getId(), "Home");
            break;
        default:
            break;
    }

    this->addNodeIntoView(node);
}

void MapView::showLink(const Link *link) {

    Road road = this->map->getRoads().at((int) link->getId());

    if (road.isIs_two_way())
        gv->addEdge(this->edges, (int) link->getNode1_id(), (int) link->getNode2_id(), EdgeType::UNDIRECTED);
    else
        gv->addEdge(this->edges, (int) link->getNode1_id(), (int) link->getNode2_id(), EdgeType::DIRECTED);

    switch (link->getType()) {
        case LinkType::WALK:
            gv->setEdgeDashed(this->edges, true);
            gv->setEdgeColor(this->edges, RED);
            break;
        case LinkType::STREET_LINK:
            gv->setEdgeColor(this->edges, GRAY);
            break;
        default:
            break;
    }

}

void MapView::updateView() {

    if (gv != nullptr) {

        /* show nodes */
        for (pair<int, Node *> pair: this->map->getNodes()) {
            this->showNode(pair.second);
        }

        /* show edges */
        this->edges = 0;
        for (auto *link: this->map->getLinks()) {
            this->showLink(link);
            this->edges++;
        }

        this->gv->rearrange();
    }
}

void MapView::close() {
    // close window
    this->gv->closeWindow();

    // destroy map object
    this->map->destroy();

    // free objects
    free(this->map);
    free(this->gv);
}

void MapView::paintSelectedVertex(int vertexId, int nextVertexId, int number) {
    gv->setVertexColor(vertexId, BLUE);
    gv->setVertexSize((vertexId), 10);
    gv->setVertexLabel(vertexId, to_string(number));

    int count = 0;
    for (auto link: this->map->getLinks()) {

        if (link->getNode1_id() == vertexId && link->getNode2_id() == nextVertexId
                ||
                link->getNode2_id() == vertexId && link->getNode1_id() == nextVertexId) {
            gv->setEdgeColor(count, BLUE);
            gv->setEdgeThickness(count, 5);
        }

        count++;
    }

    gv->rearrange();
}

void MapView::paintWalkVertex(int vertexId, int nextVertexId, int number) {
    gv->setVertexColor(vertexId, RED);
    gv->setVertexSize((vertexId), 8);
    gv->setVertexLabel(vertexId, to_string(number));

    /*
    int count = number;
    for (auto link: this->map->getLinks()) {

        if (link->getNode1_id() == vertexId && link->getNode2_id() == nextVertexId
            ||
            link->getNode2_id() == vertexId && link->getNode1_id() == nextVertexId) {
            gv->setEdgeColor(count, RED);
            gv->setEdgeThickness(count, 5);
        }

        count++;
    }*/

    gv->rearrange();
}

void MapView::showPath(vector<Node *> vector) {
    int count = 0;
    bool parkedCar = false;

    for (int i = 0; i < vector.size() - 1; i++) {
        Node *pathNode = vector[i];
        Node *nextNode = vector[i + 1];

        if (pathNode->getType() == NodeType::PARKING_LANE || pathNode->getType() == NodeType::PARKING_GARAGE)
            parkedCar = true;

        if (!parkedCar)
            this->paintSelectedVertex((int) pathNode->getId(), (int)nextNode->getId(), count++);
        else
            this->paintWalkVertex((int) pathNode->getId(), (int) nextNode->getId(), count++);

    }

}
