#include "cute.h"
#include "ide_listener.h"
#include "xml_listener.h"
#include "cute_runner.h"

#include <sstream>
#include <random>
#include <time.h>
#include <chrono>
#include <stdlib.h>

#include "Graph.h"
#include "Dijkstra.h"
#include "graphviewer.h"


#include <unordered_map>

void thisIsATest() {
	ASSERTM("start writing tests", false);	
}

void test_graphTest() {
	Graph graph { };

	ASSERTM("addVertex1", graph.addVertex(1, VertexType::NONE));
	ASSERTM("addVertex2", graph.addVertex(2, VertexType::NONE));
	ASSERTM("addVertex3", graph.addVertex(2, VertexType::NONE) == false);

	ASSERTM("getVertex1", graph.getVertex(1)->getType() == VertexType::NONE);
	ASSERTM("getVertex2", graph.getVertex(0) == nullptr);

	ASSERTM("addEdge1", graph.addEdge(1, 2, 10));
	ASSERTM("addEdge2", graph.addEdge(1, 2, 20));
	ASSERTM("addEdge3", graph.addEdge(1, 0, 10) == false);

	graph.addEdge(2, 1, 10);

	ASSERTM("getVertex2", graph.getVertex(1)->getEdges().size() == 2);
	ASSERTM("getVertex2", graph.getVertex(2)->getEdges().size() == 1);
}

Graph CreateTestGraph() {
	Graph myGraph;

	for(int i = 1; i <= 7; i++)
		myGraph.addVertex(i, VertexType::NONE);

	myGraph.addEdge(1, 2, 2);
	myGraph.addEdge(1, 4, 7);
	myGraph.addEdge(2, 4, 3);
	myGraph.addEdge(2, 5, 5);
	myGraph.addEdge(3, 1, 2);
	myGraph.addEdge(3, 6, 5);
	myGraph.addEdge(4, 3, 1);
	myGraph.addEdge(4, 5, 1);
	myGraph.addEdge(4, 6, 6);
	myGraph.addEdge(4, 7, 4);
	myGraph.addEdge(5, 7, 2);
	myGraph.addEdge(6, 4, 3);
	myGraph.addEdge(7, 6, 4);

	return myGraph;
}

void checkSinglePath(Dijkstra &g, std::vector<int> path, std::string expected) {
	std::stringstream ss;
	for(unsigned int i = 0; i < path.size(); i++)
		ss << path[i] << " ";
	ASSERT_EQUAL(expected, ss.str());
}

void checkAllPaths(Dijkstra &g, std::string expected) {
	std::stringstream ss { };
	std::vector<Vertex* > vs = g.getVertexSet();

	for(unsigned int i = 0; i < vs.size(); i++) {
		ss << vs[i]->getId() << "<-";
		if ( vs[i]->getPath() != nullptr )
			ss << vs[i]->getPath()->getId();
		ss << "|";
	}
	ASSERT_EQUAL(expected, ss.str());
}

void test_dijkstra() {
	Graph myGraph = CreateTestGraph();

	Dijkstra dijkstra{myGraph.getVertexSet()};

	dijkstra.compute(3);
	//checkAllPaths(dijkstra, "1<-3|2<-1|3<-|4<-2|5<-4|6<-3|7<-5|");

	dijkstra.compute(1);
	//checkAllPaths(dijkstra, "1<-|2<-1|3<-4|4<-2|5<-4|6<-4|7<-5|");
	checkSinglePath(dijkstra, dijkstra.getPath(1, 7), "1 2 4 5 7 ");

	dijkstra.compute(5);
	checkSinglePath(dijkstra, dijkstra.getPath(5, 6), "5 7 6 ");

	dijkstra.compute(7);
	checkSinglePath(dijkstra, dijkstra.getPath(7, 1), "7 6 4 3 1 ");
}


bool runAllTests(int argc, char const *argv[]) {
	cute::suite s { };


	s.push_back(CUTE(test_graphTest));
	s.push_back(CUTE(test_dijkstra));
	cute::xml_file_opener xmlfile(argc, argv);
	cute::xml_listener<cute::ide_listener<>> lis(xmlfile.out);
	auto runner = cute::makeRunner(lis, argc, argv);
	bool success = runner(s, "AllTests");
	return success;
}

//int main(int argc, char const *argv[]) {
//    return runAllTests(argc, argv) ? EXIT_SUCCESS : EXIT_FAILURE;
//}

