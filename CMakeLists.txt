cmake_minimum_required(VERSION 3.1)
project(VH2015)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES    main.cpp
                    src/vheap/vHeap.cpp
                    src/vheap/vMallocMetaData.cpp
                    src/vheap/vRef.cpp
                    src/vheap/vGarbageCollector.cpp
                    src/XML/pugixml.cpp
                    src/XML/xmlWriter.cpp)

set(HEADERS_FILES
                    src/vheap/vHeap.h
                    src/vheap/vObject.h
                    src/vheap/vRef.h
                    src/vheap/vMallocMetaData.h
                    src/vheap/vGarbageCollector.h
                    src/XML/pugiconfig.hpp
                    src/XML/pugixml.hpp
                    src/XML/xmlWriter.h
                    src/dataStructures/List.h)

include_directories(src headers vheap)
include_directories(src headers vheap XML)
add_executable(VH2015 ${SOURCE_FILES} ${HEADERS_FILES}  )