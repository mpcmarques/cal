/*
 * ParkingSpotSearcher.cpp
 *
 *  Created on: 04.04.2018
 *      Author: Adam
 */

//#include "ParkingSpotSearcher.h"
#include <cstdio>
#include "graph-viewer/graphviewer.h"
#include <fstream>
#include <iostream>
#include <sstream>


int main() {
	GraphViewer *gv = new GraphViewer(600, 600, true);
	gv->createWindow(800, 800);
	gv->defineVertexColor("blue");
	gv->defineEdgeColor("black");

	for(int i = 1; i <= 7; i++)
		gv-> addNode(i);

	gv->addEdge(1,1,2,EdgeType::DIRECTED);
	gv->addEdge(2,1,4,EdgeType::DIRECTED);
	gv->addEdge(3,2,4,EdgeType::DIRECTED);
	gv->addEdge(4,2,5,EdgeType::DIRECTED);
	gv->addEdge(5,3,1,EdgeType::DIRECTED);
	gv->addEdge(6,3,6,EdgeType::DIRECTED);
	gv->addEdge(7,6,3,EdgeType::DIRECTED);

	getchar();
	return 0;
}
