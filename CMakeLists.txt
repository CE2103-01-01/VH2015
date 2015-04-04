cmake_minimum_required(VERSION 3.1)
project(VH2015)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES    main.cpp
                    src/vHeap/Source/vHeap.cpp
                    src/vHeap/Source/vGarbageCollector.cpp
                    src/vHeap/Source/vMetaData.cpp
                    src/vHeap/Source/vRef.cpp
                    src/vHeap/Source/vEntry.cpp
                    src/vHeap/Source/vDefragmenter.cpp
                    src/vHeap/Source/vPager.cpp
                    libs/pugixml.cpp
                    libs/vheaplib.cpp
                    libs/vheaplibpp.cpp
                    src/vTypes/Source/vObject.cpp
                    src/vTypes/Source/vInt.cpp
                    src/vTypes/Source/vString.cpp
                    src/vTypes/Source/vChar.cpp
                    src/vTypes/Source/vFloat.cpp
                    src/vTypes/Source/vLong.cpp
                    src/Test/Source/TestApplication.cpp)

set(HEADERS_FILES
                    src/vHeap/Headers/vHeap.h
                    src/vHeap/Headers/vRef.h
                    src/vHeap/Headers/vMetaData.h
                    src/vHeap/Headers/vGarbageCollector.h
                    src/vHeap/Headers/vEntry.h
                    src/vHeap/Headers/vDefragmenter.h
                    src/vHeap/Headers/vPager.h
                    libs/pugiconfig.hpp
                    libs/pugixml.hpp
                    libs/vheaplib.h
                    libs/vheaplibpp.h
                    src/vTypes/Headers/vObject.h
                    src/vTypes/Headers/vList.h
                    src/vTypes/Headers/vString.h
                    src/vTypes/Headers/vInt.h
                    src/vTypes/Headers/vChar.h
                    src/vTypes/Headers/vFloat.h
                    src/vTypes/Headers/vLong.h
                    src/vTypes/Headers/vBinaryTree.h
                    src/vTypes/Headers/vSimpleList.h
                    src/Test/Headers/TestApplication.h)

file(GLOB RES_FILES res/book.txt
                    res/vHeap.xml)

file(COPY ${RES_FILES} DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
include_directories(src res libs)
add_executable(VH2015 ${SOURCE_FILES} ${HEADERS_FILES} ${RES_FILES}  libs/vheaplib.h libs/vheaplib.cpp src/XML/vHeapOptions.cpp src/XML/vHeapOptions.h libs/vheaplibpp.h libs/vheaplibpp.h libs/vheaplibpp.cpp src/vHeap/Source/vDefragmenter.cpp src/vHeap/Headers/vDefragmenter.h src/vHeap/Source/vPager.cpp src/vHeap/Headers/vPager.h src/vTypes/Source/vList.cpp)
include_directories(res)