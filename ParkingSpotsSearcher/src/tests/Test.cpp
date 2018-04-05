#include "cute.h"
#include "ide_listener.h"
#include "xml_listener.h"
#include "cute_runner.h"

#include <sstream>
#include <random>
#include <time.h>
#include <chrono>
#include <stdlib.h>

#include "algorithms/Graph.h"
#include "algorithms/Dijkstra.h"
#include "graph-viewer/graphviewer.h"
#include "algorithms/ParkingSpotSearcher.h"

#include <unordered_map>


Graph<int> CreateTestGraph() {
    Graph<int> myGraph;

    for (int i = 1; i <= 6; i++)
        myGraph.addVertex(i, VertexType::NONE);
    myGraph.addVertex(7, VertexType::PARKING_SPOT);

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

template <class T>
void checkSinglePath(Dijkstra<T> &g, std::vector<Vertex<T> *> path, std::string expected) {
    std::stringstream ss;
    for (unsigned int i = 0; i < path.size(); i++)
        ss << path[i]->getInfo() << " ";
    ASSERT_EQUAL(expected, ss.str());
}

//void checkAllPaths(Dijkstra &g, std::string expected) {
//    std::stringstream ss{};
//    std::vector<Vertex<int> *> vs = g.getVertexSet();
//
//    for (unsigned int i = 0; i < vs.size(); i++) {
//        ss << vs[i]->getInfo() << "<-";
//        if (vs[i]->getPath() != nullptr)
//            ss << vs[i]->getPath()->getInfo();
//        ss << "|";
//    }
//    ASSERT_EQUAL(expected, ss.str());
//}

ParkingSpotSearcher createTestSearcher() {
	ParkingSpotSearcher searcher{};

    for (int i = 1; i <= 6; i++)
    	searcher.addVertex(i, VertexType::NONE);
    searcher.addVertex(7, VertexType::PARKING_SPOT);

    searcher.addEdge(1, 2, 2);
    searcher.addEdge(1, 4, 7);
    searcher.addEdge(2, 4, 3);
    searcher.addEdge(2, 5, 5);
    searcher.addEdge(3, 1, 2);
    searcher.addEdge(3, 6, 5);
    searcher.addEdge(4, 3, 1);
    searcher.addEdge(4, 5, 1);
    searcher.addEdge(4, 6, 6);
    searcher.addEdge(4, 7, 4);
    searcher.addEdge(5, 7, 2);
    searcher.addEdge(6, 4, 3);
    searcher.addEdge(7, 6, 4);

    return searcher;
}

void test_algorithms(){
	ParkingSpotSearcher searcher = createTestSearcher();
	ASSERT_EQUAL("1 2 4 5 7 7 6 4 3 1 ", searcher.printShortestPath(1,1));
}


bool runAllTests(int argc, char const *argv[]) {
    cute::suite s{};


    //s.push_back(CUTE(test_graphTest));
    s.push_back(CUTE(test_algorithms));
    cute::xml_file_opener xmlfile(argc, argv);
    cute::xml_listener<cute::ide_listener<>> lis(xmlfile.out);
    auto runner = cute::makeRunner(lis, argc, argv);
    bool success = runner(s, "AllTests");
    return success;
}

int main(int argc, char const *argv[]) {
    return runAllTests(argc, argv) ? EXIT_SUCCESS : EXIT_FAILURE;
}

