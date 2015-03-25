cmake_minimum_required(VERSION 3.1)
project(VH2015)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES    main.cpp
                    src/vheap/vHeap.cpp
                    src/vheap/vGarbageCollector.cpp)

set(HEADERS_FILES
                    src/vheap/vHeap.h
                    src/vheap/vGarbageCollector.h)

include_directories(src headers vheap)
