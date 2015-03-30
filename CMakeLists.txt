cmake_minimum_required(VERSION 3.1)
project(VH2015)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES    main.cpp
                    src/vheap/vHeap.cpp
                    src/vheap/vGarbageCollector.cpp
                    src/vheap/vMallocMetaData.cpp
                    src/vheap/vRef.cpp
                    src/vTypes/vString.cpp
                    libs/pugixml.cpp
                    )

set(HEADERS_FILES
                    src/vheap/vHeap.h
                    src/vheap/vObject.h
                    src/vheap/vRef.h
                    src/vheap/vMallocMetaData.h
                    src/vheap/vGarbageCollector.h
                    src/vTypes/vList.h
                    src/vTypes/vString.h
                    libs/pugiconfig.hpp
                    libs/pugixml.hpp)

include_directories(src headers vheap)
include_directories(src headers vheap XML)
add_executable(VH2015 ${SOURCE_FILES} ${HEADERS_FILES} src/vTypes/vString.cpp src/vTypes/vString.h)