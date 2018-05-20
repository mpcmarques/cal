//
// Created by mateus on 06/04/18.
//

#include <iostream>
#include <graphviewer.h>
#include <ApiParser.h>
#include <vector>
#include <Edge.h>
#include <node/ParkingMeter.h>
#include <node/ShoppingMall.h>
#include <node/University.h>
#include <node/Home.h>
#include <link/StreetLink.h>
#include <iomanip>
#include "Application.h"

using namespace std;

Application::Application() {
    cout << "Loading data from .txt files... " << endl;

    /* load osm */
    map<long, Node *> nodes = ApiParser::readNodes("../maps/A.txt");
    vector<Link *> links = ApiParser::readNodeLinks("../maps/C.txt");
    map<long, Road> roads = ApiParser::readRoads("../maps/B.txt");

    cout << "Adding nodes of places of interest..." << endl;

    /* create map model */
    Map *model = new Map(800, nodes, roads, links);

    /* add gas stations  */
    addGasStations(model);

    /* add parking spots */
    addParkingSpots(model);

    /* add parking lanes to the nodes */
    addParkingMeters(model);

    /* add points of interest */
    addOtherPoints(model);

    /* create map view */
    this->model = model;
    this->view = new MapView(this->model);
}

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

int Application::chooseMaxDistance() {
    int distance;
    cout << "What is the maximum parking distance?" << endl;

    if (!(cin >> distance) || distance < 0) {
        cout << "Distance must be greater than zero" << endl;
        return chooseMaxDistance();
    } else
        return distance;
}

int Application::choosePreselectedPoint() {
    int opt;
    cout << "Choose point of interest:" << endl;
    cout << "1 -> Home." << endl;
    cout << "2 -> University." << endl;
    cout << "3 -> Shopping Mall." << endl;
    cin >> opt;

    if (opt > 0 && opt < 4) return opt;

    else {
        cout << "Invalid option, choose again." << endl;
        return choosePreselectedPoint();
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

    // add missing graph roads
    map->addRoad(411504977, 432578781);
    map->addRoad(432578827, 4517268345);
    map->addRoad(299574280, 773982494);
    map->addRoad(343634632, 343634636);
    map->addRoad(343646684, 343634635);
    map->addRoad(319327503, 319327505);
}

void Application::run() {

    cout << "Welcome to the Parking Spot Searcher!" << endl;

    /* show map */
    cout << "Opening Map View..." << endl;

    this->view->initialize();
    this->view->updateView();
    /* update cycle based on actions */
    int running = true;

    while (running) {

        this->view->updateView();

        cout << "\nWhat do you want to do?" << endl;
        cout << "1 - Search path." << endl;
        cout << "0 - Exit." << endl;
        int opt;
        cin >> opt;

        if (opt != 1)
            running = false;
        else
            this->loop();
    }

    this->view->close();
    free(this->view);
    cout << "Application ended." << endl;
}

int Application::chooseTextSearchMode() {
    int opt;

    cout << "What kind of search?" << endl;
    cout << "1 - Exact." << endl;
    cout << "2 - Approximate." << endl;

    if (!(cin >> opt) || opt < 0 || opt > 2) {
        cout << "Invalid option, please choose again." << endl;
        return chooseTextSearchMode();
    }

    return opt;
}


Road Application::selectRoadFound(vector<Road> roads) {
    int count = 1, opt;

    cout << "Showing results (Number/Road/District):" << endl;

    for (const auto &road: roads) {
        cout << setw(4) << left << setfill(' ') << count++ << " - ";
        cout << setw(100) << left << setfill(' ') << road.getName();
        cout << " - " << this->model->getNodeByRoad(road)->getDistrict() << endl;
    }

    cout << "What is the number of the desired road?" << endl;
    if (!(cin >> opt) || opt < 1 || opt > roads.size()) {
        cout << "Invalid road selected, please try again." << endl;
        return selectRoadFound(roads);
    }

    return roads[opt - 1];
}

Road Application::searchStreetByName() {

    // ask search mode
    int searchMode = chooseTextSearchMode();

    // ask search text
    cout << "Type search:" << endl;
    string text;
    cin.ignore();
    getline(cin, text);

    // search
    vector<Road> roads = this->model->findStreetName(searchMode, text);

    // handle results
    if (roads.empty()) {
        cout << "No results found, please try again." << endl;
        return searchStreetByName();
    } else {
        // ask user to select one road in the results
        return selectRoadFound(roads);
    }
}

const Node *Application::chooseNode() {
    int opt;
    cout << "1 - Point of interest." << endl;
    cout << "2 - Street or district." << endl;

    cin >> opt;

    if (opt == 1) {
        int startingPoint = choosePreselectedPoint();
        return getNodeFromLocation(startingPoint, this->model);
    } else if (opt == 2) {
        Road startingRoad = searchStreetByName();
        return this->model->getNodeByRoad(startingRoad);
    } else {
        cout << "Invalid option." << endl;
        return chooseNode();
    }
}

void Application::loop() {
    int near_or_cheap, gas, maxDistance;


    /* ask starting and ending point */
    cout << "Where do you want to start?" << endl;
    const Node *startingNode = chooseNode();

    cout << "Where do you want to go?" << endl;
    const Node *endingNode = chooseNode();


    // other options
    near_or_cheap = chooseNearestOrCheapest();
    gas = chooseGasStation();
    maxDistance = chooseMaxDistance();


    // calculate path
    vector<Node *> path = calculatePath(this->model, startingNode, endingNode, near_or_cheap, gas, maxDistance);

    // show path
    if (!path.empty()) {
        // show path on screen
        view->showPath(path);
        cout << "Path calculated, showing on map..." << endl;
    } else {
        cout << "No path was found, please try again with a bigger walking distance." << endl;
    }
}

vector<Node *>
Application::calculatePath(Map *map, const Node *startingNode, const Node *endingNode, int near_or_cheap, int gas,
                           int maxDistance) {
    if (near_or_cheap == 1)
        return map->findCheapestPath(startingNode->getId(), endingNode->getId(), maxDistance, gas == 1);
    else
        return map->findShortestPath(startingNode->getId(), endingNode->getId(), maxDistance, gas == 1);
}

Node *Application::getNodeFromLocation(int opt, const Map *map) {
    switch (opt) {
        case 1: // Home
            return map->getNodes().at(HOME_NODE_ID);
        case 2: // University
            return map->getNodes().at(UNIVERSITY_NODE_ID);
        case 3: // Shopping Mall
            return map->getNodes().at(MALL_NODE_ID);
        default:
            return nullptr;
    }
}

int main() {

    Application app = Application();
    app.run();

    return 0;
}
