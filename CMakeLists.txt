cmake_minimum_required(VERSION 3.1)
project(VH2015)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES    main.cpp
                    src/vHeap/Source/vHeap.cpp
                    src/vHeap/Source/vObject.cpp
                    src/vHeap/Source/vGarbageCollector.cpp
                    src/vHeap/Source/vMallocMetaData.cpp
                    src/vHeap/Source/vRef.cpp
                    src/vTypes/Source/vChar.cpp
                    src/vTypes/Source/vFloat.cpp
                    src/vTypes/Source/vInt.cpp
                    src/vTypes/Source/vLong.cpp
                    src/vTypes/Source/vString.cpp
                    src/vTypes/Source/vString.cpp
                    src/vTypes/Source/vInt.cpp
                    src/vTypes/Source/vChar.cpp
                    src/vTypes/Source/vFloat.cpp
                    src/vTypes/Source/vLong.cpp
                    libs/pugixml.cpp
                    src/Test/Source/TestApplication.cpp
                    src/vTypes/Source/vSimpleList.cpp
                    src/vTypes/Source/vSimpleNode.cpp
                    book.txt)

set(HEADERS_FILES
                    src/vHeap/Headers/vHeap.h
                    src/vHeap/Headers/vObject.h
                    src/vHeap/Headers/vRef.h
                    src/vHeap/Headers/vMallocMetaData.h
                    src/vHeap/Headers/vGarbageCollector.h
                    src/vHeap/Headers/vObject.h
                    src/vTypes/Source/vChar.cpp
                    src/vTypes/Source/vFloat.cpp
                    src/vTypes/Source/vInt.cpp
                    src/vTypes/Headers/vList.h
                    src/vTypes/Source/vLong.cpp
                    src/vTypes/Headers/vString.h
                    src/vTypes/Headers/vString.h
                    src/vTypes/Headers/vInt.h
                    src/vTypes/Headers/vChar.h
                    src/vTypes/Headers/vFloat.h
                    src/vTypes/Headers/vLong.h
                    src/vTypes/Headers/vBinaryTree.h
                    src/vTypes/Headers/vSimpleList.h
                    src/vTypes/Headers/vSimpleNode.h
                    libs/pugiconfig.hpp
                    libs/pugixml.hpp
                    src/Test/Headers/TestApplication.h)

file(GLOB RES_FILES res/book.txt
                vHeap.xml)

file(COPY ${RES_FILES} DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
include_directories(src res libs)
add_executable(VH2015 ${SOURCE_FILES} ${HEADERS_FILES} ${RES_FILES} )
include_directories(res)