cmake_minimum_required(VERSION 3.1)
project(VH2015)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)

set(HEADERS_FILES headers/vObject.h)

include_directories(src headers)
add_executable(VH2015 ${SOURCE_FILES} ${HEADERS_FILES})add_executable(VH2015 ${SOURCE_FILES} src/vheap/vHeap.cpp src/vheap/vHeap.h src/vheap/vGarbageCollector.cpp src/vheap/vGarbageCollector.h)