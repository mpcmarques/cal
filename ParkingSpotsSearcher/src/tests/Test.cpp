#include "cute.h"
#include "ide_listener.h"
#include "xml_listener.h"
#include "cute_runner.h"

#include <sstream>
#include <random>
#include <ctime>
#include <chrono>
#include <iostream>
#include <vector>

#include <Graph.h>
#include <Dijkstra.h>
#include <graphviewer.h>
#include <ParkingSpotSearcher.h>

#include <unordered_map>
#include <ApiParser.h>
#include <KmpMatcher.h>
#include <EditDistance.h>
#include "node/Node.h"

////Graph<int, int> CreateTestGraph() {
////    Graph<int, int> myGraph;
////
////    for (int i = 1; i <= 6; i++)
////        myGraph.addVertex(i, VertexType::NONE);
////    myGraph.addVertex(7, VertexType::PARKING_SPOT);
////
////    myGraph.addEdge(1, 2, 2);
////    myGraph.addEdge(1, 4, 7);
////    myGraph.addEdge(2, 4, 3);
////    myGraph.addEdge(2, 5, 5);
////    myGraph.addEdge(3, 1, 2);
////    myGraph.addEdge(3, 6, 5);
////    myGraph.addEdge(4, 3, 1);
////    myGraph.addEdge(4, 5, 1);
////    myGraph.addEdge(4, 6, 6);
////    myGraph.addEdge(4, 7, 4);
////    myGraph.addEdge(5, 7, 2);
////    myGraph.addEdge(6, 4, 3);
////    myGraph.addEdge(7, 6, 4);
////
////    return myGraph;
////}

//template<class V, class E>
//void checkSinglePath(Dijkstra<V, E> &g, std::vector<Vertex<V, E> *> path,
//                     std::string expected) {
//    std::stringstream ss;
//    for (unsigned int i = 0; i < path.size(); i++)
//        ss << path[i]->getInfo() << " ";
//    ASSERT_EQUAL(expected, ss.str());
//}

////void checkAllPaths(Dijkstra &g, std::string expected) {
////    std::stringstream ss{};
////    std::vector<Vertex<int> *> vs = g.getVertexSet();
////
////    for (unsigned int i = 0; i < vs.size(); i++) {
////        ss << vs[i]->getInfo() << "<-";
////        if (vs[i]->getPath() != nullptr)
////            ss << vs[i]->getPath()->getInfo();
////        ss << "|";
////    }
////    ASSERT_EQUAL(expected, ss.str());
////}

//std::string printPath(std::vector<int> path) {
//    std::stringstream ss;
//    for (unsigned int i = 0; i < path.size(); i++)
//        ss << path[i] << " ";
//    return ss.str();
//}

//ParkingSpotSearcher<int, int> createTestSearcher() {
//    ParkingSpotSearcher<int, int> searcher{};
//    searcher.addVertex(11, VertexType::NONE, 11);
//    searcher.addVertex(14, VertexType::GAS_STATION, 14);
//    searcher.addVertex(22, VertexType::NONE, 22);
//    searcher.addVertex(23, VertexType::NONE, 23);
//    searcher.addVertex(24, VertexType::NONE, 24);
//    searcher.addVertex(25, VertexType::NONE, 25);
//    searcher.addVertex(33, VertexType::NONE, 33);
//    searcher.addVertex(35, VertexType::PARKING_SPOT, 35, 10);
//    searcher.addVertex(41, VertexType::PARKING_SPOT, 41, 1000);
//    searcher.addVertex(42, VertexType::NONE, 42);
//    searcher.addVertex(43, VertexType::PARKING_SPOT, 43, 2);
//    searcher.addVertex(52, VertexType::NONE, 52);
//    searcher.addVertex(54, VertexType::NONE, 54);
//    searcher.addVertex(55, VertexType::NONE, 55);

//    searcher.addEdge(11, 41, 3, 1);

//    searcher.addEdge(22, 42, 2, 2);
//    searcher.addEdge(42, 22, 2, 2);
//    searcher.addEdge(42, 52, 1, 2);

//    searcher.addEdge(23, 33, 1, 2);
//    searcher.addEdge(33, 23, 1, 2);
//    searcher.addEdge(43, 33, 1, 2);

//    searcher.addEdge(14, 24, 1, 2);
//    searcher.addEdge(24, 14, 1, 2);

//    searcher.addEdge(25, 35, 1, 2);
//    searcher.addEdge(35, 25, 1, 2);
//    searcher.addEdge(35, 55, 2, 2);
//    searcher.addEdge(55, 35, 2, 2);

//    searcher.addEdge(14, 11, 3, 2);

//    searcher.addEdge(22, 23, 1, 2);
//    searcher.addEdge(23, 22, 1, 2);
//    searcher.addEdge(23, 24, 1, 2);
//    searcher.addEdge(24, 25, 1, 2);
//    searcher.addEdge(25, 24, 1, 2);

//    searcher.addEdge(33, 35, 2, 2);
//    searcher.addEdge(35, 33, 2, 2);

//    searcher.addEdge(41, 42, 1, 2);
//    searcher.addEdge(42, 41, 1, 2);
//    searcher.addEdge(42, 43, 1, 2);

//    searcher.addEdge(52, 54, 2, 2);
//    searcher.addEdge(54, 55, 1, 2);
//    return searcher;
//}

//void test_algorithms() {
//    ParkingSpotSearcher<int, int> searcher = createTestSearcher();
//    ASSERT_EQUAL("11 41 41 42 52 54 55 ",
//                 printPath(searcher.findShortestPath(11, 55, 100, false)));
//    ASSERT_EQUAL("11 41 42 43 33 35 35 55 ",
//                 printPath(searcher.findShortestPath(11, 55, 2, false)));
//    ASSERT_EQUAL("11 41 42 22 23 24 14 14 24 25 35 35 55 ",
//                 printPath(searcher.findShortestPath(11, 55, 100, true)));

//    ASSERT_EQUAL("11 41 42 43 43 33 35 55 ",
//                 printPath(searcher.findCheapestPath(11, 55, 100, false)));

//    ASSERT_EQUAL("11 41 42 43 33 23 24 14 14 11 41 42 43 43 33 35 55 ",
//                 printPath(searcher.findCheapestPath(11, 55, 100,
//                                                     true))); //can be 11 41 42 22 23 24 14 14 11 41 42 43 43 33 35 55

//    ASSERT_EQUAL("11 41 42 43 33 35 35 55 ",
//                 printPath(searcher.findCheapestPath(11, 55, 2, false)));
//}

//void test_node_parser() {

//    // test node parser
//    map<int, Node *> nodes = ApiParser::readNodes("../maps/A.txt");
//    ASSERT(nodes.size() > 0);

//}

//void test_roads_parser() {
//    map<int, Road> roads = ApiParser::readRoads("../maps/B.txt");
//    ASSERT(roads.size() > 0);
//}

//void test_links_parser() {
//    vector<Link *> links = ApiParser::readNodeLinks("../maps/C.txt");
//    ASSERT(links.size() > 0);
//}


void test_string_full_match(){
    ASSERT(KmpMatcher::matches("teste", "teste"));

    ASSERT_EQUAL(false, KmpMatcher::matches("teste", "1234"));

    ASSERT(KmpMatcher::matches("teste", "TESTE"));
}

void test_string_that_contains_match(){
    ASSERT(KmpMatcher::matches("12345teste", "teste"));

    ASSERT_EQUAL(false, KmpMatcher::matches("12345test1", "teste"));

    ASSERT_EQUAL(false, KmpMatcher::matches("Rua da Igreja da Areosa", "Ajuda"));
}

void test_string_distance(){

    // edit distance simple
    ASSERT(EditDistance::editDistance("teste", "teste") == 0);
    ASSERT(EditDistance::editDistance("teste", "test1") == 1);
    ASSERT(EditDistance::editDistance("tebta", "teste") == 2);

    ASSERT(EditDistance::calculate("teste", "teste") == 0);

    ASSERT_EQUAL(1, EditDistance::calculate("test1", "teste"));

    ASSERT_EQUAL(1, EditDistance::calculate("Marcal", "rua horácio mar1al"));

    ASSERT_EQUAL(0, EditDistance::calculate("cabral", "Rua de Costa Cabral"));
}


bool runAllTests(int argc, char const *argv[]) {
    cute::suite s{};

    //s.push_back(CUTE(test_graphTest));
    //.push_back(CUTE(test_algorithms));

    /* parser tests */
    //s.push_back(CUTE(test_node_parser));
   // s.push_back(CUTE(test_roads_parser));
   // s.push_back(CUTE(test_links_parser));

    // string
    s.push_back(CUTE(test_string_full_match));
    s.push_back(CUTE(test_string_that_contains_match));
    s.push_back(CUTE(test_string_distance));

    /* init cute */
    cute::xml_file_opener xmlfile(argc, argv);
    cute::xml_listener<cute::ide_listener<>> lis(xmlfile.out);
    auto runner = cute::makeRunner(lis, argc, argv);
    bool success = runner(s, "AllTests");
    return success;
}


//int main(int argc, char const *argv[]) {
//    return runAllTests(argc, argv) ? EXIT_SUCCESS : EXIT_FAILURE;
//}

