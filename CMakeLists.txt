cmake_minimum_required(VERSION 3.1)
set(CMAKE_CXX_COMPILER "/usr/bin/g++-4.8")
project(VH2015)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES    src/vHeap/Source/vHeap.cpp
                    src/vHeap/Source/vGarbageCollector.cpp
                    src/vHeap/Source/vMetaData.cpp
                    src/vHeap/Source/vEntry.cpp
                    src/vHeap/Source/vDefragmenter.cpp
                    src/vHeap/Source/vPager.cpp
                    src/vHeap/Source/Dump.cpp
                    libs/pugixml.cpp
                    libs/vheaplib.cpp
                    libs/vheaplibpp.cpp
                    src/vTypes/Source/vInt.cpp
                    src/vTypes/Source/vString.cpp
                    src/vTypes/Source/vChar.cpp
                    src/vTypes/Source/vFloat.cpp
                    src/vTypes/Source/vLong.cpp
                    src/vHeap/Source/Dump.cpp
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
                    libs/pugiconfig.hpp
                    libs/pugixml.hpp
                    libs/vheaplib.h
                    libs/vheaplibpp.h
                    src/vTypes/Headers/vArray.h
                    src/vTypes/Headers/vBinaryTree.h
                    src/vTypes/Headers/vList.h
                    src/vTypes/Headers/vString.h
                    src/vTypes/Headers/vDoubleList.h
                    src/vTypes/Headers/vInt.h
                    src/vTypes/Headers/vChar.h
                    src/vTypes/Headers/vFloat.h
                    src/vTypes/Headers/vLong.h
                    src/vTypes/Headers/vArray.h
                    src/vTypes/Headers/vBinaryTree.h
                    src/vTypes/Headers/vSimpleList.h)

file(GLOB RES_FILES res/book.txt
                    res/vHeap.xml)

file(COPY ${RES_FILES} DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
include_directories(src res libs)
find_package (Threads)
add_executable(VH2015 ${HEADERS_FILES} ${SOURCE_FILES} ${RES_FILES} libs/rapidjson/internal/pow10.h libs/rapidjson/internal/stack.h libs/rapidjson/internal/strfunc.h libs/rapidjson/document.h libs/rapidjson/filestream.h libs/rapidjson/prettywriter.h libs/rapidjson/rapidjson.h libs/rapidjson/reader.h libs/rapidjson/stringbuffer.h libs/rapidjson/writer.h proof.h proof.cpp src/vTypes/Headers/vDoubleList.h src/vHeap/Headers/Tree.h src/Test/Headers/Ship.h src/Constants.cpp src/Constants.h)

target_link_libraries (VH2015 ${CMAKE_THREAD_LIBS_INIT})
include_directories(res)