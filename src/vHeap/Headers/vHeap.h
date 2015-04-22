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

#include "vTypes/Headers/vList.h"
#include "vRef.h"
#include <vheaplibpp.h>
#include "vDefragmenter.h"
#include "vPager.h"
#include "Dump.h"
#include "vMetaData.h"
#include "Tree/Tree.h"

template<class T> class vRef;
class vMetaData;

class vHeap{
    bool* vDebug;
    int* dumpFrecuency;
    static vHeap* vHeapSingleton;
    float* overweight;
    int* vSize;
    void* mainChunk;
    void* initPos;
    void* finalPos;
    void* actualPos;
    void* dmp;
    void* dfrag;
    vMetaData* metaData;
    pthread_mutex_t* memoryMutex;
    pthread_t dfragThread;
    pthread_t dumpThread;
public:
    bool getVDebug();
    vHeap();
    ~vHeap();
    unsigned int vMalloc(int);
    template <class T> void vFree(vRef<T>);
    void vFree(unsigned int);
    static vHeap* getInstance();
    vMetaData* getMetaData();
    int removeVRef(int);
    int addVRef(int);
    template <class T> int vPlacement(vRef<T>, T);
    void* de_vReference(int);
    long getUse();
};
/**
 * Metodo para liberar memoria
 */
template<class T> void vHeap::vFree(vRef<T> r) {
    pthread_mutex_lock(memoryMutex);
    metaData->removeEntry(!r);
    pthread_mutex_unlock(memoryMutex);
};
/**
 * Se usa para poner un objeto en una vRef en memoria
 */
template<class T> int vHeap::vPlacement(vRef<T> memory, T object) {
    **memory = object;
    return 0;
};

#endif //_VH2015_VHEAP_H_



