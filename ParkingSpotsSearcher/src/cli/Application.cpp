//
// Created by mateus on 06/04/18.
//

#include "../view/MapView.h"
#include <iostream>
#include <graphviewer.h>
#include <ApiParser.h>
#include <vector>
#include <Edge.h>
#include <LatLongConverter.h>
#include <Map.h>

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
        return chooseGasStation();
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
        return chooseNearestOrCheapest();
    }
}

void showGraphViewer(int opt, int gas) {

    /* load osm */
    map<int, Node> nodes = ApiParser::readNodes("../maps/A.txt");
    vector<Link> links = ApiParser::readNodeLinks("../maps/C.txt");
    map<int, Road> roads = ApiParser::readRoads("../maps/B.txt");

    Map *map = new Map(800, nodes, roads, links);

    /* add gas stations to the map*/
    map->addGasStation(GasStation(0, 41.17832, (float) -8.58288));
    map->addGasStation(GasStation(1, 41.17693, (float) -8.59989));

    MapView *mapView = new MapView(map);

    /* show map */
    mapView->initialize();

    /* update cycle based on actions ?

    while(listening){
        // change stuff in the map

       // update map model
       mapView->setMap(map)

       // update map view
       mapView->update();
    }

    mapView->close();

    free(mapView);
    */

}


int main() {
    int opt, gas;

    /* title */
    cout << "Welcome to the Parking Spot Searcher!" << endl;

    /* ask user of options */
    opt = chooseNearestOrCheapest();
    gas = chooseGasStation();

    /* load graph */
    cout << "Showing map" << endl;
    showGraphViewer(opt, gas);

    return 0;
}
