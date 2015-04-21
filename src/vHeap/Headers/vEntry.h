//
// Created by pablo on 31/03/15.
//

#ifndef VH2015_VENTRY_H
#define VH2015_VENTRY_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include "vGarbageCollector.h"

class vEntry {
private:
    void *offset;
    unsigned int dataSize;
    bool useFlag;   //TODO: usar
    unsigned int numReferences = 0;
    bool onHeap;
    unsigned int idRef;
public:
    vEntry();
    vEntry(int, int, void*);
    vEntry(int, int, void*, bool);
    void changeFlag();
    int getIdRef();
    void* getOffSet();
    int getDataSize();
    bool getUseFlag();
    unsigned int getNumReferences();
    void decreaseNumReferences();
    void increaseNumReferences();
    void fileDown();
    void fileUp(void*);
    bool isOnHeap();
    void setOffset(void*);
    void setNumRef(int);
    void setID(int);
    void setDefault();
};

void setDefault(vEntry* entry);

#endif //VH2015_VENTRY_H
