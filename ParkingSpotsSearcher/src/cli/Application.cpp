//
// Created by mateus on 06/04/18.
//

#include "Application.h"
#include <iostream>
#include <graphviewer.h>
#include <ApiParser.h>
#include <vector>

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
    auto *gv = new GraphViewer(1000, 1000, true);
    gv->createWindow(1000, 1000);
    gv->defineVertexColor("black");
    gv->defineEdgeColor("blue");


    /* load nodes */
    vector<Node> nodes = ApiParser::readNodes("../maps/A.txt");

    /* show nodes */
    for (Node node: nodes) {
        gv->addNode((int) node.getId(), (int) node.getLatitude_degrees() * 100000,
                    (int) node.getLongitute_degrees() * 100000);
    }

    /* link edges */


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