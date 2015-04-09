#ifndef _VH2015_VHEAP_H_
#define _VH2015_VHEAP_H_

#include <iostream>
#include <stdlib.h>
#include <pthread.h>
#include <stdio.h>
#include <sstream>
#include <fstream>
#include <cstdlib>
#include <unistd.h>
#include "../libs/pugixml.hpp"
#include "vTypes/Headers/vList.h"
#include "vRef.h"
#include "vDefragmenter.h"
#include "vPager.h"
#include "Dump.h"
#include "vMetaData.h"

template<class T> class vRef;
class vMetaData;

class vHeap{
    bool* vDebug;
    int* dumpFrecuency;
    static vHeap* vHeapSingleton;

    float* overweight;
    void* mainChunk;
    void* initPos;
    void* finalPos;
    void* actualPos;
    void* dmp;
    void* dfrag;
    vMetaData* metaData;
    vPager* pager;
    pthread_mutex_t* memoryMutex;
    pthread_t dfragThread;
    pthread_t dumpThread;
public:
    int* vSize;
    vHeap(int,float);
    ~vHeap();
    unsigned int vMalloc(int);
    template <class T> void vFree(vRef<T>);
    void vFree(unsigned int);
    static vHeap* getInstance();
    bool makeDump();
    void startDumpThread();
    vMetaData* getMetaData();
    int removeVRef(int);
    int addVRef(int);
    template <class T> int vPlacement(vRef<T>, T);
    void* de_vReference(int);
};

template<class T> void vHeap::vFree(vRef<T> r) {
    pthread_mutex_lock(memoryMutex);
    metaData->removeEntry(!r);
    pthread_mutex_unlock(memoryMutex);
};

template<class T> int vHeap::vPlacement(vRef<T> memory, T object) {
    pthread_mutex_lock(memoryMutex);
    try {
        *static_cast<T *>(de_vReference(!memory)) = object;
        pthread_mutex_unlock(memoryMutex);
        return 0;
    } catch (int error) {
        pthread_mutex_unlock(memoryMutex);
        return -1;
    };
};

#endif //_VH2015_VHEAP_H_



