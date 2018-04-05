cmake_minimum_required(VERSION 3.10)
project(ParkingSpotsSearcher)

set(CMAKE_CXX_STANDARD 17)

include_directories(cute)
include_directories(src)
include_directories(src/api-reader)
include_directories(src/graph-viewer)
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
        src/api-reader/ApiReader.cpp
        src/api-reader/ApiReader.h
        src/graph-viewer/connection.cpp
        src/graph-viewer/connection.h
        src/graph-viewer/edgetype.h
        src/graph-viewer/graphviewer.cpp
        src/graph-viewer/graphviewer.h
        src/tests/Test.cpp
        src/utils/MutablePriorityQueue.h
        src/utils/StringSplitter.cpp
        src/utils/StringSplitter.h
        src/Dijkstra.cpp
        src/Dijkstra.h
        src/Edge.cpp
        src/Edge.h
        src/Graph.cpp
        src/Graph.h
        src/ParkingSpotSearcher.cpp
        src/ParkingSpotSearcher.h
        src/Vertex.cpp
        src/Vertex.h
        GraphViewerController.jar
        ParkingSpotsSearcher.exe.xml src/model/Node.cpp src/model/Node.h src/model/Road.cpp src/model/Road.h src/model/Link.cpp src/model/Link.h)
