#ifndef _VH2015_VHEAP_H_
#define _VH2015_VHEAP_H_


#include "vMetaData.h"
#include "vTypes/Headers/vList.h"
#include <iostream>
#include <stdlib.h>
#include <pthread.h>
#include <stdio.h>
#include "vRef.h"
#include <sstream>
#include <fstream>
#include <unistd.h>
#include "../libs/pugixml.hpp"


class vMetaData;
class vRef;
class Dump;
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
    pthread_mutex_t memoryMutex;
    vMetaData *metaData;
public:
    vHeap(int,float);
    ~vHeap();
    vRef vMalloc(int, std::string);
    void vFree(vRef);
    void vFree(unsigned int);
    static vHeap* getInstance();
    bool makeDump();
    void startDumpThread();
    vMetaData *getMetaData();
    int removeVRef(int);
    int addVRef(int);
    template <typename T> int vPlacement(vRef, T);
    void *de_vReference(int);
};

template <typename T> int vHeap::vPlacement(vRef memory, T object){
    pthread_mutex_lock(&memoryMutex);
    try{
        *static_cast<T *>(de_vReference(!memory)) = object;
        pthread_mutex_unlock(&memoryMutex);
        return 0;
    }catch(int error){
        pthread_mutex_unlock(&memoryMutex);
        return -1;
    };
};


//DUMP

class Dump {
    friend class vHeap;
    int* frecuency;
    int* counter;
    std::string directory;
    bool* dumpping;
    
    public:
        Dump();
        ~Dump();
        std::string IntToStr(int);
        void saveDumpFile();
	bool getDumppingState();
};

#endif //_VH2015_VHEAP_H_