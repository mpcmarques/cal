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
            gv->setVertexColor((int) node->getId(), YELLOW);
            gv->setVertexSize((int) node->getId(), 1);
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
        gv->addEdge(this->edges, (int) link->getNode1_id(), (int) link->getNode2_id(), EdgeType::UNDIRECTED);

    switch (link->getType()) {
        case LinkType::WALK:
            gv->setEdgeDashed(this->edges, true);
            gv->setEdgeColor(this->edges, RED);
            gv->setEdgeThickness(this->edges, 1);

            break;
        case LinkType::STREET_LINK:
            gv->setEdgeColor(this->edges, GRAY);
            gv->setEdgeThickness(this->edges, 1);
            if(nameCache.find(road.getName()) == nameCache.end()) {
                gv->setEdgeLabel(this->edges, road.getName());
                nameCache.insert(road.getName());
            }

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

        /* show edges and streets */
        this->edges = 0;
        this->nameCache.erase(this->nameCache.begin(), this->nameCache.end());
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

void MapView::showPath(vector<Node *> nodeVector) {
    bool parkedCar = false;

    for (int i = 0; i < nodeVector.size() - 1; i++) {
        Node *pathNode = nodeVector[i];

        if (pathNode->getType() == NodeType::PARKING_LANE || pathNode->getType() == NodeType::PARKING_GARAGE)
            parkedCar = true;

        if (!parkedCar) {
            gv->setVertexColor(pathNode->getId(), BLUE);
            gv->setVertexSize((pathNode->getId()), 1);
            gv->setVertexLabel(pathNode->getId(), to_string(i));

            for (int j = 0; j < this->map->getLinks().size(); j++) {
                Link *link = this->map->getLinks()[j];

                // check connection between nodes
                if (link->getNode1_id() == pathNode->getId()) {
                    for (int k = 0; k < nodeVector.size(); k++) {
                        if (nodeVector[k]->getId() == link->getNode2_id()) {
                            gv->setEdgeColor(j, BLUE);
                            gv->setEdgeThickness(j, 5);
                        }
                    }
                }
            }
        } else {
            gv->setVertexColor(pathNode->getId(), RED);
            gv->setVertexSize((pathNode->getId()), 1);
            gv->setVertexLabel(pathNode->getId(), to_string(i));

            for (int j = 0; j < this->map->getLinks().size(); j++) {
                Link *link = this->map->getLinks()[j];

                // check connection between nodes
                if (link->getNode1_id() == pathNode->getId()) {
                    for (int k = 0; k < nodeVector.size(); k++) {
                        if (nodeVector[k]->getId() == link->getNode2_id()) {
                            gv->setEdgeColor(j, RED);
                            gv->setEdgeThickness(j, 5);
                        }
                    }
                }
            }
        }

    }


    gv->rearrange();
}
