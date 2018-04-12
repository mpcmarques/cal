#ifndef PARKINGSPOTSEARCHERBUILDER_H
#define PARKINGSPOTSEARCHERBUILDER_H

#include "Map.h"
#include "node/ParkingGarage.h"
#include "node/ParkingMeter.h"



class ParkingSpotSearcherBuilder
{
    Map *map;
public:
    ParkingSpotSearcherBuilder(Map *map){
        this->map=map;



    }
    ParkingSpotSearcher<Node *, int> * build(){
        ParkingSpotSearcher<Node *, int> *parkingSpotSearcher = new ParkingSpotSearcher<Node *, int>();
        addVertecies(parkingSpotSearcher);
        addEdges(parkingSpotSearcher);
        return parkingSpotSearcher;
    }
private:
    void addVertecies(ParkingSpotSearcher<Node *, int>* parkingSpotSearcher){
        for (auto node : map->getNodes()) {
            VertexType type = mapType(node.second->getType());
            double cost = 0;
            if(type == VertexType::PARKING_SPOT) {
                bool isGarage = node.second->getType() == NodeType::PARKING_GARAGE;
                cost = isGarage ? ((ParkingGarage *) node.second)->getCost() : ((ParkingMeter *) node.second)->getCost();
                parkingSpotSearcher->addVertex(node.first,type,node.second, cost);
            }
        }
    }
    void addEdges(ParkingSpotSearcher<Node *, int>* parkingSpotSearcher){
        for (auto link : map->getLinks()) {
            Road r = map->getRoads().at(link->getId());
            Node *n1 = map->getNodes().at(link->getNode1_id());
            Node *n2 = map->getNodes().at(link->getNode2_id());

            double distance = sqrt(
                    pow(n1->getLatitude() - n2->getLatitude(), 2) + pow(n1->getLongitute() - n2->getLongitute(), 2));

            parkingSpotSearcher->addEdge(link->getNode1_id(), link->getNode2_id(), distance, link->getId());
            if (r.isIs_two_way())
                parkingSpotSearcher->addEdge(link->getNode2_id(), link->getNode1_id(), distance, link->getId());
        }
    }

    VertexType mapType(NodeType type){
        if(type == NodeType::PARKING_GARAGE || type == NodeType::PARKING_LANE)
            return VertexType::PARKING_SPOT;
        if(type == NodeType::GAS_STATION)
            return VertexType::GAS_STATION;
        return VertexType::NONE;
    }

};

#endif // PARKINGSPOTSEARCHERBUILDER_H
