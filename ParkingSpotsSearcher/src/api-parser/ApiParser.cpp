//
// Created by mateus on 05/04/18.
//

#include <fstream>
#include <iostream>
#include "StringSplitter.h"
#include <vector>
#include <map>
#include "Node.h"
#include "Road.h"
#include "Link.h"
#include "ApiParser.h"

using namespace std;

map<long, Node> ApiParser::readNodes(string nodeFilePath) {
    map<long, Node> nodes;

    ifstream nodeFile(nodeFilePath);

    if (nodeFile.is_open()) {
        string line;

        while (getline(nodeFile, line)) {
            long id;
            float latitude_in_degrees, longitude_in_degrees, longitude_in_radians, latitude_in_radians;

            vector<string> split = StringSplitter::split(line, ';');

            // check line attributes
            if (split.size() != 5) {
                cout << "Nodes reading parse error: invalid line: \n\t" << line << endl;
                nodeFile.close();
                return nodes;
            }

            id = stol(split[0]);
            latitude_in_degrees = stof(split[1]);
            longitude_in_degrees = stof(split[2]);
            longitude_in_radians = stof(split[3]);
            latitude_in_radians = stof(split[4]);

            //  return the vector<nodes> with the parsed attributes
            Node node = Node(id, latitude_in_degrees, longitude_in_degrees, latitude_in_radians, longitude_in_radians);
            nodes.insert(pair<long,Node>(id, node));
        }

        nodeFile.close();
        return nodes;

    } else {
        cout << "Unable to load nodes file " << nodeFilePath << endl;
    }
}

map<int, Road> ApiParser::readRoads(const string roadsFilePath) {

    ifstream nodeFile(roadsFilePath);

    map<int, Road> roads;

    if (nodeFile.is_open()) {
        string line;

        while (getline(nodeFile, line)) {
            string road_name;
            int road_id;
            bool is_two_way;

            vector<string> split = StringSplitter::split(line, ';');

            // check line attributes
            if (split.size() != 3) {
                cout << "Roads file parsing error: invalid line: \n\t" << line << endl;
                nodeFile.close();
                return roads;
            }

            road_id = stoi(split[0]);
            road_name = split[1];
            if (split[2] == "true")
                is_two_way = true;
            else if (split[2] == "false")
                is_two_way = false;

            // return the vector<edges> with the parsed attributes
            Road road = Road(road_id, road_name, is_two_way);
            roads.insert(pair<int,Road>(road_id, road));
        }

        nodeFile.close();

        return roads;

    } else {
        cout << "Unable to load roads file " << roadsFilePath << endl;
    }
}

vector<Link> ApiParser::readNodeLinks(const string nodesLinksPath) {

    ifstream nodeFile(nodesLinksPath);

    vector<Link> links;

    if (nodeFile.is_open()) {
        string line;

        long road_id, node1_id, node2_id;

        // check line attributes
        while (getline(nodeFile, line)) {

            vector<string> split = StringSplitter::split(line, ';');

            if (split.size() != 3) {
                cout << "Node links file parsing error: invalid line: \n\t" << line << endl;
                nodeFile.close();
                return links;
            }

            road_id = stol(split[0]);
            node1_id = stol(split[1]);
            node2_id = stol(split[2]);

            // return the vector<links> with the parsed attributes
            Link link = Link(road_id, node1_id, node2_id);
            links.push_back(link);
        }

        nodeFile.close();

        return links;

    } else {
        cout << "Unable to load nodes links file " << nodesLinksPath << endl;
    }
}
