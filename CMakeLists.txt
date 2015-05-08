cmake_minimum_required(VERSION 3.1)
project(VH2015)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES    src/vHeap/Source/vHeap.cpp
                    src/vHeap/Source/vGarbageCollector.cpp
                    src/vHeap/Source/vMetaData.cpp
                    src/vHeap/Source/vEntry.cpp
                    src/vHeap/Source/vDefragmenter.cpp
                    src/vHeap/Source/vPager.cpp
                    src/vHeap/Source/Dump.cpp
                    src/vHeap/Source/vCleaner.cpp
                    libs/pugixml.cpp
                    libs/vheaplib.cpp
                    libs/vheaplibpp.cpp
                    src/vTypes/Source/vString.cpp
                    src/Test/Source/proof.cpp src/Tree/Leaf.cpp
                    src/Constants.cpp
                    src/Socket/Socket.cpp
                    main.cpp
                                                                   )

set(HEADERS_FILES
                    src/vHeap/Headers/vHeap.h
                    src/vHeap/Headers/vRef.h
                    src/vHeap/Headers/vMetaData.h
                    src/vHeap/Headers/vGarbageCollector.h
                    src/vHeap/Headers/vEntry.h
                    src/vHeap/Headers/vDefragmenter.h
                    src/vHeap/Headers/vPager.h
                    src/vHeap/Headers/Dump.h
                    src/vHeap/Headers/vCleaner.h
                    libs/pugiconfig.hpp
                    libs/pugixml.hpp
                    libs/vheaplib.h
                    libs/vheaplibpp.h
                    src/vTypes/Headers/vArray.h
                    src/vTypes/Headers/vBinaryTree.h
                    src/vTypes/Headers/vList.h
                    src/vTypes/Headers/vString.h
                    src/vTypes/Headers/vDoubleList.h
                    src/vTypes/Headers/vArray.h
                    src/vTypes/Headers/vBinaryTree.h
                    src/vTypes/Headers/vSimpleList.h
                    src/vTypes/Headers/vNumber.h
                    src/Tree/Leaf.h
                    src/Tree/Tree.h
                    src/Test/Headers/proof.h
                    src/Test/Headers/Ship.h
                    src/Socket/Socket.h
                    src/Constants.h)

file(GLOB RES_FILES res/book.txt
                    res/vHeap.xml)

file(COPY ${RES_FILES} DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
include_directories(src res libs)
find_package (Threads)
add_executable(VH2015 ${HEADERS_FILES} ${SOURCE_FILES} ${RES_FILES} libs/rapidjson/internal/pow10.h libs/rapidjson/internal/stack.h libs/rapidjson/internal/strfunc.h libs/rapidjson/document.h libs/rapidjson/filestream.h libs/rapidjson/prettywriter.h libs/rapidjson/rapidjson.h libs/rapidjson/reader.h libs/rapidjson/stringbuffer.h libs/rapidjson/writer.h)

target_link_libraries (VH2015 ${CMAKE_THREAD_LIBS_INIT})
include_directories(res)

#add_subdirectory(Memory\ Visor)
