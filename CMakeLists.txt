cmake_minimum_required(VERSION 3.1)
project(VH2015)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES    main.cpp
                    src/vheap/Source/vHeap.cpp
                    src/vheap/Source/vObject.cpp
                    src/vheap/Source/vGarbageCollector.cpp
                    src/vheap/Source/vMallocMetaData.cpp
                    src/vheap/Source/vRef.cpp
                    src/vTypes/Source/vChar.cpp
                    src/vTypes/Source/vFloat.cpp
                    src/vTypes/Source/vInt.cpp
                    src/vTypes/Source/vLong.cpp
                    src/vTypes/Source/vString.cpp
                    libs/pugixml.cpp
                    src/vheap/Source/vObject.cpp
                    src/vTypes/Source/vString.cpp
                    src/vTypes/Source/vInt.cpp
                    src/vTypes/Source/vChar.cpp
                    src/vTypes/Source/vFloat.cpp
                    src/vTypes/Source/vLong.cpp
                    src/TestApplication.cpp
                    src/vTypes/Source/vSimpleList.cpp
                    src/vTypes/Source/vSimpleNode.cpp)

set(HEADERS_FILES
                    src/vheap/Headers/vHeap.h
                    src/vheap/Headers/vObject.h
                    src/vheap/Headers/vRef.h
                    src/vheap/Headers/vMallocMetaData.h
                    src/vheap/Headers/vGarbageCollector.h
                    src/vTypes/Source/vChar.cpp
                    src/vTypes/Source/vFloat.cpp
                    src/vTypes/Source/vInt.cpp
                    src/vTypes/Headers/vList.h
                    src/vTypes/Source/vLong.cpp
                    src/vTypes/Headers/vString.h
                    libs/pugiconfig.hpp
                    libs/pugixml.hpp
                    src/vheap/Headers/vObject.h
                    src/vTypes/Headers/vString.h
                    src/vTypes/Headers/vInt.h
                    src/vTypes/Headers/vChar.h
                    src/vTypes/Headers/vFloat.h
                    src/vTypes/Headers/vLong.h
                    src/TestApplication.h
                    src/vTypes/Headers/vBinaryTree.h
                    src/vTypes/Headers/vSimpleList.h
                    src/vTypes/Headers/vSimpleNode.h)

include_directories(src headers vheap)
include_directories(src headers vheap XML)
add_executable(VH2015 ${SOURCE_FILES} ${HEADERS_FILES} )