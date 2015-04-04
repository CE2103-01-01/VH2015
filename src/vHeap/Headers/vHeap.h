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

template<class T>
class vRef;
class vMetaData;
class Dump;
class vHeap{
    friend class Dump;
    bool* vDebug;
    int* dumpFrecuency;
    static vHeap* vHeapSingleton;
    int* vSize;
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





/***********************************************************************************************************/
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



