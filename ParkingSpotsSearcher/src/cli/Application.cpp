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
#include <ParkingMeter.h>

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

void start() {
    cout << "Loading data from .txt files... " << endl;

    /* load osm */
    map<int, Node *> nodes = ApiParser::readNodes("../maps/A.txt");
    vector<Link> links = ApiParser::readNodeLinks("../maps/C.txt");
    map<int, Road> roads = ApiParser::readRoads("../maps/B.txt");

    /* add gas stations to the nodes */
    cout << "Adding gas stations..." << endl;
    nodes.insert(pair<int, Node *>(0, new GasStation(0, 41.17832, (float) -8.58288)));
    nodes.insert(pair<int, Node *>(1, new GasStation(1, 41.17693, (float) -8.59989)));

    /* add parking spots to the nodes */
    cout << "Adding parking spots..." << endl;
    nodes.insert(pair<int, Node *>(2, new ParkingGarage(2, 41.17823, (float) -8.59394)));
    nodes.insert(pair<int, Node *>(3, new ParkingGarage(3, 41.1749, (float) -8.5883)));
    nodes.insert(pair<int, Node *>(4, new ParkingGarage(4, 41.17602, (float) -8.59958)));
    nodes.insert(pair<int, Node *>(5, new ParkingGarage(5, 41.1763, (float) -8.59586)));

    /* add parking lanes to the nodes */
    cout << "Adding parking lanes..." << endl;
    nodes.insert(pair<int, Node *>(6, new ParkingMeter(6, 41.1763, (float) -8.59586)));
    nodes.insert(pair<int, Node *>(7, new ParkingMeter(7, 41.17899, (float) -8.6006)));
    nodes.insert(pair<int, Node *>(8, new ParkingMeter(8, 41.17707, (float) -8.59228)));
    nodes.insert(pair<int, Node *>(9, new ParkingMeter(9, 41.17655, (float) -8.58992)));

    /* create map model */
    Map *map = new Map(800, nodes, roads, links);

    /* create map view */
    MapView *mapView = new MapView(map);

    /* show map */
    cout << "Opening Map View..." << endl;

    mapView->initialize();

    /* update cycle based on actions */
    int running = true;

    while(running){

        int opt;
        cout << "\nWhat do you want to do? " << endl;
        cout << "-> 1 - search a parking spot" << endl;
        cout << "-> 0 - exit program" << endl;
        cin >> opt;

        if (opt == 0){
            running = false;
        }

        else if (opt == 1){
            int near_or_cheap, gas;
            near_or_cheap = chooseNearestOrCheapest();
            gas = chooseGasStation();
        }

        // change stuff in the map

       // update map model
       //mapView->setMap(map)

       // update map view
       //mapView->update();
    }

    mapView->close();
    free(mapView);
    cout << "Application ended" << endl;
}


int main() {

    /* title */
    cout << "Welcome to the Parking Spot Searcher!" << endl;

    cout << "Opening graph viewer..." << endl;
    start();

    return 0;
}
