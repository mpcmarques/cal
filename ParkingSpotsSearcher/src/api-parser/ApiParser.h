//
// Created by mateus on 05/04/18.
//

#ifndef PARKINGSPOTSSEARCHER_APIREADER_H
#define PARKINGSPOTSSEARCHER_APIREADER_H

#include <string>
#include "../model/Node.h"
#include "../model/Road.h"
#include "../model/Link.h"
#include <vector>

/**
 * Class is responsible for parsing api data.
 */
class ApiParser {

public:
    /**
     * Read nodes from a node file(A).
     * @param nodesFilePath File full path.
     */
    static std::vector<Node> readNodes(std::string nodesFilePath);

    /**
     * Read roads from a roads file (B).
     * @param roadsFilePath File full path.
     */
    static std::vector<Road> readRoads(std::string roadsFilePath);

    /**
     * Read the file with links between nodes (C):
     * @param nodesLinksPath File full path.
     */
    static std::vector<Link> readNodeLinks(std::string nodesLinksPath);
};


#endif //PARKINGSPOTSSEARCHER_APIREADER_H
