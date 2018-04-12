//
// Created by mateus on 06/04/18.
//

#include "../view/MapView.h"
#include <iostream>
#include <graphviewer.h>
#include <ApiParser.h>
#include <vector>
#include <Edge.h>
#include <Map.h>
#include <node/ParkingMeter.h>
#include <node/ShoppingMall.h>
#include <node/University.h>
#include <node/Home.h>
#include "Application.h"

using namespace std;

int Application::chooseGasStation() {
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

int Application::chooseNearestOrCheapest() {
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

int Application::chooseStartingPoint() {
    int opt;
    cout << "Where do you want to start?" << endl;
    cout << "1 -> Home." << endl;
    cout << "2 -> University." << endl;
    cout << "3 -> Shopping Mall." << endl;
    cin >> opt;

    if (opt > 0 && opt < 3) return opt;

    else {
        cout << "Invalid option, choose again." << endl;
        return chooseNearestOrCheapest();
    }
}

int Application::chooseEndingPoint() {
    int opt;
    cout << "Where do you want to go?" << endl;
    cout << "1 -> Home." << endl;
    cout << "2 -> University." << endl;
    cout << "3 -> Shopping Mall." << endl;
    cin >> opt;

    if (opt > 0 && opt < 3) return opt;

    else {
        cout << "Invalid option, choose again." << endl;
        return chooseNearestOrCheapest();
    }
}

void Application::addGasStations(map<int, Node *> &nodes) {
    nodes.insert(pair<int, Node *>(0, new GasStation(0, 41.17832, -8.58288)));
    nodes.insert(pair<int, Node *>(1, new GasStation(1, 41.17693, -8.59989)));
}

void Application::addParkingSpots(map<int, Node *> &nodes) {
    nodes.insert(pair<int, Node *>(2, new ParkingGarage(2, 41.17823, -8.59394, 5)));
    nodes.insert(pair<int, Node *>(3, new ParkingGarage(3, 41.1749, -8.5883, 5)));
    nodes.insert(pair<int, Node *>(4, new ParkingGarage(4, 41.17602, -8.59958, 5)));
    nodes.insert(pair<int, Node *>(5, new ParkingGarage(5, 41.1763, -8.59586, 5)));
}

void Application::addParkingMeters(map<int, Node*> &nodes){
    nodes.insert(pair<int, Node *>(6, new ParkingMeter(6, 41.1763, -8.59586, 1)));
    nodes.insert(pair<int, Node *>(7, new ParkingMeter(7, 41.17899, -8.6006, 1)));
    nodes.insert(pair<int, Node *>(8, new ParkingMeter(8, 41.17707, -8.59228, 1)));
    nodes.insert(pair<int, Node *>(9, new ParkingMeter(9, 41.17655, -8.58992, 1)));
}

void Application::addOtherPoints(map<int, Node*> &nodes){
    nodes.insert(pair<int, Node *>(MALL_NODE_ID, new ShoppingMall(MALL_NODE_ID, 41.1777, -8.5913)));
    nodes.insert(pair<int, Node *>(UNIVERSITY_NODE_ID, new University(UNIVERSITY_NODE_ID, 41.1781, -8.5962)));
    nodes.insert(pair<int, Node *>(HOME_NODE_ID, new Home(HOME_NODE_ID, 41.168, -8.593)));
}

void Application::start() {

    cout << "Welcome to the Parking Spot Searcher!" << endl;

    cout << "Loading data from .txt files... " << endl;

    /* load osm */
    map<int, Node *> nodes = ApiParser::readNodes("../maps/A.txt");
    vector<Link *> links = ApiParser::readNodeLinks("../maps/C.txt");
    map<int, Road> roads = ApiParser::readRoads("../maps/B.txt");

    cout << "Adding nodes of places of interest..." << endl;

    /* add gas stations to the nodes */
    addGasStations(nodes);

    /* add parking spots to the nodes */
    addParkingSpots(nodes);

    /* add parking lanes to the nodes */
    addParkingMeters(nodes);

    /* add points of interest */
    addOtherPoints(nodes);

    /* create map model */
    Map *map = new Map(800, nodes, roads, links);

    /* create map view */
    MapView *mapView = new MapView(map);

    /* show map */
    cout << "Opening Map View..." << endl;

    mapView->initialize();

    /* update cycle based on actions */
    int running = true;

    while (running) {

        int opt;
        cout << "\nWhat do you want to do? " << endl;
        cout << "-> 1 - go to a location" << endl;
        cout << "-> 0 - exit" << endl;
        cin >> opt;

        if (opt == 0) {
            running = false;
        } else if (opt == 1) {
            int near_or_cheap, gas, startingPoint, endingPoint;

            /* ask starting and ending point */
            startingPoint = chooseStartingPoint();
            endingPoint = chooseEndingPoint();

            while (endingPoint == startingPoint) {
                cout << "Same starting and ending point, please choose to go to another location." << endl;
                endingPoint = chooseEndingPoint();
            }

            near_or_cheap = chooseNearestOrCheapest();
            gas = chooseGasStation();

            // Parse start and ending point
            Node *startingNode = getNodeFromLocation(startingPoint, nodes);
            Node *endingNode = getNodeFromLocation(endingPoint, nodes);

            // TODO: calculate
            // vector<Node *> path = calculatePath(startingNode, endingNode);

            // TODO: show path on screen
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

Node* Application::getNodeFromLocation(int opt, map<int, Node*> nodes){
    switch (opt){
        case 1: // Home
            return nodes.at(HOME);
        case 2: // University
            return nodes.at(UNIVERSITY);
        case 3: // Shopping Mall
            return nodes.at(MALL);
        default:
            return nullptr;
    }
}

Application::Application() {

}


int main() {

    Application app = Application();
    app.start();

    return 0;
}
