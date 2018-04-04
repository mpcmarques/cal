cmake_minimum_required(VERSION 3.10)
project(ParkingSpotsSearcher)

set(CMAKE_CXX_STANDARD 17)

include_directories(cute)
include_directories(src)

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
        src/connection.cpp
        src/connection.h
        src/Dijkstra.cpp
        src/Dijkstra.h
        src/Edge.cpp
        src/Edge.h
        src/edgetype.h
        src/Graph.cpp
        src/Graph.h
        src/graphviewer.cpp
        src/graphviewer.h
        src/MutablePriorityQueue.h
        src/ParkingSpotSearcher.cpp
        src/ParkingSpotSearcher.h
        src/Test.cpp
        src/Vertex.cpp
        src/Vertex.h
        GraphViewerController.jar
        ParkingSpotsSearcher.exe.xml
        )

