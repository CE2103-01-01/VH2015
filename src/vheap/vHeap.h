//
// Created by alex on 20/03/15.
//

#ifndef _VH2015_VHEAP_H_
#define _VH2015_VHEAP_H_

#include "dataStructures/List.h"
#include <iostream>
#include <stdlib.h>
#include "Metadata.h"
#include "vRef.h"


class vHeap
{
private:
    bool vDebug;
    int dumpFrecuency;
    static vHeap vHeapSingleton;
    int* overweight;
    void* mainChunk;
    void* actualDir;
    int* actualID;
    List<Metadata>* control;
public:
    static vHeap getInstance();
    vHeap(int, int);
    virtual ~vHeap();
    vRef vMalloc(int,std::string);
    void vFree(vRef);
    bool makeDump();
    void printMetadata();
};



#endif //_VH2015_VHEAP_H_
