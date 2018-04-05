//
// Created by mateus on 05/04/18.
//

#include <fstream>
#include <iostream>
#include <utils/StringSplitter.h>
#include <vector>
#include "ApiReader.h"

using namespace std;

void ApiReader::readNodes(string nodeFilePath) {
    ifstream nodeFile(nodeFilePath);

    if (nodeFile.is_open()) {
        string line;

        while (getline(nodeFile, line)) {
            string id, latitude_in_degrees, longitude_in_degrees, longitude_in_radians, latitude_in_radians;

            vector<string> split = StringSplitter::split(line, ';');

            // check line attributes
            if (split.size() != 5) {
                cout << "Nodes reading parse error: invalid line: \n\t" << line << endl;
                return;
            }

            id = split[0];
            latitude_in_degrees = split[1];
            longitude_in_degrees = split[2];
            longitude_in_radians = split[3];
            latitude_in_radians = split[4];

            // TODO: return the vector<nodes> with the parsed attributes
        }

        nodeFile.close();

    } else {
        cout << "Unable to load nodes file " << nodeFilePath << endl;
    }
}

void ApiReader::readRoads(const string roadsFilePath) {

    ifstream nodeFile(roadsFilePath);

    if (nodeFile.is_open()) {
        string line;

        while (getline(nodeFile, line)) {
            string road_id, road_name, is_two_way;

            vector<string> split = StringSplitter::split(line, ';');

            // check line attributes
            if (split.size() != 3) {
                cout << "Roads file parsing error: invalid line: \n\t" << line << endl;
                return;
            }

            road_id = split[0];
            road_name = split[1];
            is_two_way = split[2];

            // TODO: return the vector<edges> with the parsed attributes
        }

        nodeFile.close();

    } else {
        cout << "Unable to load roads file " << roadsFilePath << endl;
    }
}

void ApiReader::readNodeLinks(const string nodesLinksPath) {

    ifstream nodeFile(nodesLinksPath);

    if (nodeFile.is_open()) {
        string line;

        string road_id, node1_id, node2_id;

        vector<string> split = StringSplitter::split(line, ';');

        // check line attributes
        while (getline(nodeFile, line)) {
            if (split.size() != 3) {
                cout << "Node links file parsing error: invalid line: \n\t" << line << endl;
                return;
            }

            road_id = split[0];
            node1_id = split[1];
            node2_id = split[2];

            // TODO: return the vector<links> with the parsed attributes
        }

        nodeFile.close();

    } else {
        cout << "Unable to load nodes links file " << nodesLinksPath << endl;
    }
}
