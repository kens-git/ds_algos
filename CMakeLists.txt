cmake_minimum_required(VERSION 3.0)

set(CMAKE_CXX_STANDARD 14)

file(GLOB graph_sources Graph/*.cpp)

include_directories(DArray Graph utility)

# sorting algorithms
add_executable(selection_sort selection_sort.cpp utility/Utility.cpp)
add_executable(insertion_sort insertion_sort.cpp utility/Utility.cpp)
add_executable(merge_sort merge_sort.cpp utility/Utility.cpp)
add_executable(quick_sort quick_sort.cpp utility/Utility.cpp)

#graph algorithms
add_executable(DFS unweighted_DFS.cpp utility/GraphUtility.cpp ${graph_sources})
add_executable(BFS unweighted_BFS.cpp utility/GraphUtility.cpp ${graph_sources})
