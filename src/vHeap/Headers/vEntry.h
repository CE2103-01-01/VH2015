//
// Created by pablo on 31/03/15.
//

#ifndef VH2015_VENTRY_H
#define VH2015_VENTRY_H

#include "vGarbageCollector.h"

class vEntry {
private:
    void* offset = 0;
    unsigned int dataSize = 0;
    bool useFlag = false;
    unsigned int numReferences = 0;
    bool onHeap = false;
    unsigned int idRef = 0;
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

void setDefault(vEntry* entry, void*);

#endif //VH2015_VENTRY_H
