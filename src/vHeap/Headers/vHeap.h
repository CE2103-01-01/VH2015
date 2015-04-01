#ifndef _VH2015_VHEAP_H_
#define _VH2015_VHEAP_H_

#include "vRef.h"
#include "vMallocMetaData.h"
#include "vTypes/Headers/vList.h"
#include <iostream>
#include <stdlib.h>
#include <sstream>
#include <mutex>
#include <fstream>
#include <unistd.h>
#include "../libs/pugixml.hpp"

class vRef;
class vMallocMetaData;

class vHeap{
    friend class Dump;
    bool* vDebug;
    int* dumpFrecuency;
    static vHeap* vHeapSingleton;

    float* overweight;
    void* mainChunk;
    void* initPos;
    void* finalPos;
    void* actualPos;
    std::mutex memoryMutex;
    vMallocMetaData* metaData;
public:
    vHeap(int,float);
    ~vHeap();
    vRef vMalloc(int, std::string);
    void vFree(vRef);

    void vFree(unsigned int);
    static vHeap* getInstance();
    bool makeDump();
    void startDumpThread();
    vMallocMetaData* getMetaData();

    int vPlacement(vRef, vObject *);

    int removeVRef(int idRef);

    int addVRef(int idRef);
    template <typename T> int vPlacement(vRef,T);

    void *de_vReference(vRef);
};


template <typename T> int vHeap::vPlacement(vRef memory, T object){
    memoryMutex.lock();
    try{
        *static_cast<T*>(de_vReference(memory)) = object;
        memoryMutex.unlock();
        return 0;
    }catch(int error){
        memoryMutex.unlock();
        return -1;
    };
};


class Dump {
public:
    void startDump();
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