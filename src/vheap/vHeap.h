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

class vHeap{
    bool* vDebug;
    int* dumpFrecuency;
    static vHeap* vHeapSingleton;
    List<vMallocMetaData>* memoryTable;
    float* overweight;
    void* mainChunk;
    void* actualPos;
    int* actualID;
public:
    vHeap(int,float);
    ~vHeap();
    vRef vMalloc(int, std::string);
    void vFree();
    static vHeap* getInstance();
    bool makeDump();
    void startDumpThread();
    void printMetadata();
};
#endif //_VH2015_VHEAP_H_
