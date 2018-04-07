//
// Created by mateus on 06/04/18.
//

#include "Application.h"
#include <iostream>
#include <graphviewer.h>
#include <ApiParser.h>
#include <vector>
#include <Edge.h>

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
    auto *gv = new GraphViewer(1000, 1000, false);
    gv->createWindow(1000, 1000);
    gv->defineVertexColor("blue");
    gv->defineEdgeColor("black");
    gv->defineVertexSize(1);
   // gv->setBackground("../maps/map.png");

    /* load osm */
    vector<Node> nodes = ApiParser::readNodes("../maps/A.txt");
    vector<Link> links = ApiParser::readNodeLinks("../maps/C.txt");

    /* show nodes */
    for (Node node: nodes) {
        gv->addNode((int) node.getId(), (int) node.getLatitude_degrees() * 1000000000,
                    (int) node.getLongitute_degrees() * 1000000000);
    }

    /* show roads */
    for(Link link: links){
        gv->addEdge((int)link.getId(), (int)link.getNode1_id(), (int)link.getNode2_id(), EdgeType::DIRECTED);
    }

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