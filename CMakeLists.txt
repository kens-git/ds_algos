cmake_minimum_required(VERSION 3.0)

set(CMAKE_CXX_STANDARD 14)

add_executable(selection_sort selection_sort.cpp "utility/Utility.cpp")
target_include_directories(selection_sort PUBLIC DArray utility)

add_executable(insertion_sort insertion_sort.cpp "utility/Utility.cpp")
target_include_directories(insertion_sort PUBLIC DArray utility)

add_executable(merge_sort merge_sort.cpp "utility/Utility.cpp")
target_include_directories(merge_sort PUBLIC DArray utility)
