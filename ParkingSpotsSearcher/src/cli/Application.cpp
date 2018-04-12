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
#include <link/StreetLink.h>
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

void Application::addGasStations(Map *map) {
    int gas_station_id = 0, gas_station_id2 = 1;

    // insert nodes 0 and 1
    map->addNode(new GasStation(gas_station_id, 41.1709, -8.5892));
    map->addNode(new GasStation(gas_station_id2, 41.17554, -8.5963));

    // add roads
    map->addRoad(gas_station_id, 4455723064);
    map->addRoad(gas_station_id, 4455723082);
    map->addRoad(gas_station_id2, 2460915667);
    map->addRoad(gas_station_id2, 4282469014);
}

void Application::addParkingSpots(Map *map) {
    int garageId = 2, garageId1 = 3, garageId2 = 4, garageId3 = 5;

    map->addNode(new ParkingGarage(garageId, 41.17823, -8.59394, 5));
    map->addNode(new ParkingGarage(garageId1, 41.1749, -8.5883, 5));
    map->addNode(new ParkingGarage(garageId2, 41.17602, -8.59958, 5));
    map->addNode(new ParkingGarage(garageId3, 41.1763, -8.59586, 5));

    // parking garage roads
    map->addRoad(garageId, 4282469053);
    map->addRoad(garageId3, 4517268345);
    map->addRoad(garageId2, 430012030);
    map->addRoad(garageId2, 432578817);
    map->addRoad(garageId1, 4478085704);
}

void Application::addParkingMeters(Map *map) {
    int meterId = 6, meterId1 = 7, meterId2 = 8;

    map->addNode(new ParkingMeter(meterId, 41.17899, -8.6006, 1));
    map->addNode(new ParkingMeter(meterId1, 41.17707, -8.59228, 1));
    map->addNode(new ParkingMeter(meterId2, 41.16938, -8.59301, 1));

    // roads to parking meters
    map->addRoad(meterId1, 4474021937);
    map->addRoad(meterId2, 343634632);
    map->addRoad(meterId, 430006694);
}

void Application::addOtherPoints(Map *map) {
    map->addNode(new ShoppingMall(MALL_NODE_ID, 41.1754, -8.5874));
    map->addNode(new University(UNIVERSITY_NODE_ID, 41.1781, -8.5962));
    map->addNode(new Home(HOME_NODE_ID, 41.17026, -8.59661));

    // roads to other points with walking links
    map->addWalkingPath(MALL_NODE_ID, 4452315785);
    map->addWalkingPath(UNIVERSITY_NODE_ID, 2185756687);
    map->addWalkingPath(HOME_NODE_ID, 2168903808);
}

int Application::chooseMaxDistance(){
    int distance;
    cout << "What is the maximum distance?" << endl;
    cin >> distance;

    if(distance < 0){
        cout << "Distance must be greater than zero" << endl;
        return chooseMaxDistance();
    } else
        return distance;
}

void Application::start() {

    cout << "Welcome to the Parking Spot Searcher!" << endl;

    cout << "Loading data from .txt files... " << endl;

    /* load osm */
    map<int, Node *> nodes = ApiParser::readNodes("../maps/A.txt");
    vector<Link *> links = ApiParser::readNodeLinks("../maps/C.txt");
    map<int, Road> roads = ApiParser::readRoads("../maps/B.txt");

    cout << "Adding nodes of places of interest..." << endl;

    /* create map model */
    Map *map = new Map(800, nodes, roads, links);

    /* add gas stations  */
    addGasStations(map);

    /* add parking spots */
    addParkingSpots(map);

    /* add parking lanes to the nodes */
    addParkingMeters(map);

    /* add points of interest */
    addOtherPoints(map);

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
            int near_or_cheap, gas, startingPoint, endingPoint, maxDistance;

            /* ask starting and ending point */
            startingPoint = chooseStartingPoint();
            endingPoint = chooseEndingPoint();

            while (endingPoint == startingPoint) {
                cout << "Same starting and ending point, please choose to go to another location." << endl;
                endingPoint = chooseEndingPoint();
            }

            near_or_cheap = chooseNearestOrCheapest();
            gas = chooseGasStation();
            maxDistance = chooseMaxDistance();

            // Parse start and ending point
            Node *startingNode = getNodeFromLocation(startingPoint, nodes);
            Node *endingNode = getNodeFromLocation(endingPoint, nodes);

            // TODO: calculate path
            vector<Node *> path = calculatePath(map, startingNode, endingNode, near_or_cheap, gas, maxDistance);
            cout<<path.size()<<endl; //TODEL
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

vector<Node *> Application::calculatePath(Map *map, Node * startingNode, Node * endingNode, int near_or_cheap, int gas, int maxDistance){
    if(near_or_cheap == 1)
        return map->findCheapestPath(startingNode->getId(), endingNode->getId(), maxDistance, gas == 1);
    else
        return map->findShortestPath(startingNode->getId(), endingNode->getId(), maxDistance, gas == 1);
}

Node *Application::getNodeFromLocation(int opt, map<int, Node *> nodes) {
    switch (opt) {
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

Application::Application() {}


int main() {

    Application app = Application();
    app.start();

    return 0;
}
