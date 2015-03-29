//
// Created by alex on 20/03/15.
//

#ifndef _VH2015_VHEAP_H_
#define _VH2015_VHEAP_H_



#include "dataStructures/List.h"
#include "vRef.h"
#include "vMallocMetaData.h"
#include <iostream>
#include <stdlib.h>

class vHeap
    friend class dump;
    bool* vDebug;

    static vHeap* vHeapSingleton;
    List<vMallocMetaData>* memoryTable;
    float* overweight;
    void* mainChunk;
    void* actualPos;
    int* actualID;
public:
    vHeap vHeap(int,float);
    ~vHeap();
    int dumpFrecuency;
    vRef vMalloc(int, std::string);
    void vFree();
    static vHeap* getInstance();
    bool makeDump();
    void startDumpThread();
    void printMetadata();
};

class dump{
public:
    int frecuency;
    static std::string directory;
    static bool dumpping;
    static int counter;
    std::string IntToStr(int n);
    dump();
    ~dump();
    void saveDump();


};
#endif //_VH2015_VHEAP_H_
