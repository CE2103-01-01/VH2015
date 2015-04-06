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
#include "vDefragmenter.h"
#include "vPager.h"
#include "Dump.h"
#include <cstdlib>

template<class T>
class vRef;
class vMetaData;
class vHeap{
    bool* vDebug;
    int* dumpFrecuency;
    static vHeap* vHeapSingleton;
    int* vSize;
    float* overweight;
    void* mainChunk;
    void* initPos;
    void* finalPos;
    void* actualPos;
    vMetaData* metaData;
    vPager* pager;
    Dump* dmp;
    vDefragmenter* dfrag;
    pthread_mutex_t* memoryMutex;
    pthread_t* dfragThread;
    pthread_t* dumpThread;
public:
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

#endif //_VH2015_VHEAP_H_



