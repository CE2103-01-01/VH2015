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
#include <cstdlib>
#include "vTypes/Headers/vObject.h"

class vRef;
class vObject;
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
    vMetaData* metaData;
    vPager* pager;
    vDefragmenter* dfrag;
    pthread_mutex_t* memoryMutex;
    pthread_t* dfragThread;
public:
    vHeap(int,float);
    ~vHeap();
    unsigned int vMalloc(int);
    void vFree(vRef);
    void vFree(unsigned int);
    static vHeap* getInstance();
    bool makeDump();
    void startDumpThread();
    vMetaData* getMetaData();
    int removeVRef(int);
    int addVRef(int);
    int vPlacement(vRef, vObject);
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



