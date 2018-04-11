cmake_minimum_required(VERSION 3.7)
project(ParkingSpotsSearcher)

set(CMAKE_CXX_STANDARD 11)

include_directories(cute)
include_directories(graph-viewer)
include_directories(src/algorithms)
include_directories(src/api-parser)
include_directories(src/cli)
include_directories(src/model)
include_directories(src/utils)

add_executable(ParkingSpotsSearcher
        cute/cute.h
        cute/cute_base.h
        cute/cute_counting_listener.h
        cute/cute_data_driven.h
        cute/cute_demangle.h
        cute/cute_deprecated.h
        cute/cute_determine_library.h
        cute/cute_determine_traits.h
        cute/cute_determine_version.h
        cute/cute_diff_values.h
        cute/cute_equals.h
        cute/cute_integer_sequence.h
        cute/cute_listener.h
        cute/cute_range.h
        cute/cute_relops.h
        cute/cute_repeated_test.h
        cute/cute_runner.h
        cute/cute_suite.h
        cute/cute_suite_test.h
        cute/cute_test.h
        cute/cute_test_incarnate.h
        cute/cute_testmember.h
        cute/cute_throws.h
        cute/cute_to_string.h
        cute/cute_version.h
        cute/cute_xml_file.h
        cute/ide_listener.h
        cute/ostream_listener.h
        cute/xml_listener.h
        graph-viewer/connection.cpp
        graph-viewer/connection.h
        graph-viewer/edgetype.h
        graph-viewer/graphviewer.cpp
        graph-viewer/graphviewer.h
        src/algorithms/Dijkstra.h
        src/algorithms/Edge.h
        src/algorithms/Graph.h
        src/algorithms/ParkingSpotSearcher.h
        src/algorithms/Vertex.h
        src/api-parser/ApiParser.cpp
        src/api-parser/ApiParser.h
        src/cli/Application.cpp
        src/model/Link.cpp
        src/model/Link.h
        src/model/Node.cpp
        src/model/Node.h
        src/model/Road.cpp
        src/model/Road.h
        src/tests/Test.cpp
        src/utils/LatLongConverter.cpp
        src/utils/LatLongConverter.h
        src/utils/MutablePriorityQueue.h
        src/utils/StringSplitter.cpp
        src/utils/StringSplitter.h src/model/Map.cpp src/model/Map.h src/view/MapView.cpp src/view/MapView.h src/model/GasStation.cpp src/model/GasStation.h src/model/ParkingGarage.cpp src/model/ParkingGarage.cpp src/model/ParkingGarage.h src/model/StreetNode.cpp src/model/StreetNode.h src/model/ParkingMeter.cpp src/model/ParkingMeter.h src/model/University.cpp src/model/University.h src/model/ShoppingMall.cpp src/model/ShoppingMall.h src/model/Home.cpp src/model/Home.h)
