//
// Created by alex on 20/03/15.
//

#ifndef _VH2015_VHEAP_H_
#define _VH2015_VHEAP_H_

#include "list.h"
#include "vRef.h"
#include <iostream>
using namespace std;

class vHeap {
private:
    bool vDebug;
    int dumpFrecuency;
    static vHeapSingleton;
    list MemoryTable;
public:

    vHeap(int size,float overweight);
    ~vHeap();
    vRef vMalloc(int size, string type);
    void vFree;
    static vHeap getInstance();
    bool makeDump();
    void startDumpThread();

};


#endif //_VH2015_VHEAP_H_
