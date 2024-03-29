#ifndef PARKINGSPOTSEARCHERBUILDER_H
#define PARKINGSPOTSEARCHERBUILDER_H

#include "Map.h"
#include "node/ParkingGarage.h"
#include "node/ParkingMeter.h"
#include <math.h>


class ParkingSpotSearcherBuilder {
    Map *map;
public:
    ParkingSpotSearcherBuilder(Map *map) {
        this->map = map;


    }

    ParkingSpotSearcher<Node *, long> *build() {
        ParkingSpotSearcher<Node *, long> *parkingSpotSearcher = new ParkingSpotSearcher<Node *, long>();
        addVertecies(parkingSpotSearcher);
        addEdges(parkingSpotSearcher);

        return parkingSpotSearcher;
    }

private:
    void addVertecies(ParkingSpotSearcher<Node *, long> *parkingSpotSearcher) {
        for (auto node : map->getNodes()) {
            VertexType type = mapType(node.second->getType());
            double cost = 0;
            if (type == VertexType::PARKING_SPOT) {
                bool isGarage = node.second->getType() == NodeType::PARKING_GARAGE;
                cost = isGarage ? ((ParkingGarage *) node.second)->getCost()
                                : ((ParkingMeter *) node.second)->getCost();
            }
            parkingSpotSearcher->addVertex(node.second->getId(), type, node.second, cost);
        }
    }

    void addEdges(ParkingSpotSearcher<Node *, long> *parkingSpotSearcher) {
        for (auto link : map->getLinks()) {
            Road r = map->getRoads().at(link->getId());
            Node *n1 = map->getNodes().at(link->getNode1_id());
            Node *n2 = map->getNodes().at(link->getNode2_id());

            float distance = getDistance(n1->getLatitude(), n1->getLongitute(), n2->getLatitude(), n2->getLongitute());
            //pow(n1->getLatitude() - n2->getLatitude(), 2) + pow(n1->getLongitute() - n2->getLongitute(), 2));
            //std::cout<<distance<<std::endl;
            parkingSpotSearcher->addEdge(link->getNode1_id(), link->getNode2_id(), distance, link->getId());
            if (r.isIs_two_way())
                parkingSpotSearcher->addEdge(link->getNode2_id(), link->getNode1_id(), distance, link->getId());
        }
    }

    float getDistance(double lat1, double lon1, double lat2, double lon2) {
        double earthRadius = 6371000; // Radius of earth in KM
        double dLat = (M_PI / 180) *  (lat2 - lat1);
        double dLng = (M_PI / 180) * (lon2 - lon1);
        double a = sin(dLat/2) * sin(dLat/2) +
                   cos((M_PI / 180)*(lat1)) * cos((M_PI / 180)*(lat2)) *
                   sin(dLng/2) * sin(dLng/2);
        double c = 2 * atan2(sqrt(a), sqrt(1-a));
        float dist = (float) (earthRadius * c);
        return dist;
    }

    VertexType mapType(NodeType type) {
        if (type == NodeType::PARKING_GARAGE || type == NodeType::PARKING_LANE)
            return VertexType::PARKING_SPOT;
        if (type == NodeType::GAS_STATION)
            return VertexType::GAS_STATION;
        return VertexType::NONE;
    }

};

#endif // PARKINGSPOTSEARCHERBUILDER_H
