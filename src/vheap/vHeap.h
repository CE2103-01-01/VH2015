#ifndef _VH2015_VHEAP_H_
#define _VH2015_VHEAP_H_

#include "vRef.h"
#include "vMallocMetaData.h"
#include "List.h"
#include <iostream>
#include <stdlib.h>
#include <sstream>

class vHeap{
    friend class Dump;
    bool* vDebug;
    int* dumpFrecuency;
    static vHeap* vHeapSingleton;
    vMallocMetaData metaData;
    float* overweight;
    void* mainChunk;
    void* actualPos;
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

class Dump {
    Dump();
    ~Dump();
    int frecuency;
    int counter;
    std::string directory;
    bool dumpping;

    std::string IntToStr(int n);
    void saveDumpFile();
};

#endif //_VH2015_VHEAP_H_