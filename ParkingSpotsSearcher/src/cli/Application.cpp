//
// Created by mateus on 06/04/18.
//

#include "Application.h"
#include <iostream>
#include <graphviewer.h>
#include <ApiParser.h>
#include <vector>
#include <Edge.h>
#include <LatLongConverter.h>

using namespace std;

int chooseGasStation() {
    int opt;
    cout << "Do you need to visit a gas station on your way?" << endl;
    cout << "1 -> Yes." << endl;
    cout << "2 -> No." << endl;
    cin >> opt;

    if (opt == 1 || opt == 2) return opt;
    else {
        cout << "Invalid option, choose again" << endl;
        chooseGasStation();
    }
}

int chooseNearestOrCheapest() {
    int opt;
    cout << "Do you want the nearest or the cheapest way?" << endl;
    cout << "1 -> Nearest." << endl;
    cout << "2 -> Cheapest." << endl;
    cin >> opt;
    if (opt == 1 || opt == 2) return opt;
    else {
        cout << "Invalid option, choose again." << endl;
        chooseNearestOrCheapest();
    }
}

void showGraphViewer(int opt, int gas) {

    /* show graph */
    auto *gv = new GraphViewer(800, 800, false);

    gv->createWindow(800, 800);

    gv->defineEdgeColor("blue");
    gv->defineVertexColor("yellow");
    gv->setBackground("../maps/map.png");

    /* load osm */
    vector<Node> nodes = ApiParser::readNodes("../maps/A.txt");
    vector<Link> links = ApiParser::readNodeLinks("../maps/C.txt");

    /* show nodes */
    double MIN_LATITUDE = 41.1715;
    double MAX_LATITUDE = 41.1801;
    double MAX_LONGITUDE = -8.6030;
    double MIN_LONGITUDE = -8.5830;

    // TODO: You have to see how much the map changes in latitude and longitude and make a simple rule of three (regra de tres)
    for (auto node : nodes) {
        double x = LatLongConverter::convert(node.getLongitute_degrees(), MIN_LONGITUDE, MAX_LONGITUDE, 800);
        double y = LatLongConverter::convert(node.getLatitude_degrees(),MIN_LATITUDE, MAX_LATITUDE, 800);
        cout << x << " " << y << endl;
        gv->addNode((int) node.getId(), (int) x, (int) y);
    }

    /* show edges
    for (auto link: links){
        gv->addEdge((int) link.getId(), (int) link.getNode1_id(), (int) link.getNode2_id(), EdgeType::UNDIRECTED);
    }*/

    gv->rearrange();
}

int main() {
    int opt, gas;

    /* title */
    cout << "Welcome to the Parking Spot Searcher!" << endl;

    /* ask user of options */
    opt = chooseNearestOrCheapest();
    gas = chooseGasStation();

    /* load graph */
    cout << "Showing map..." << endl;
    showGraphViewer(opt, gas);

}