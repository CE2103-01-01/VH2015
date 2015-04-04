//
// Created by pablo on 31/03/15.
//

#ifndef VH2015_VMALLOCMDENTRY_H
#define VH2015_VMALLOCMDENTRY_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <vHeap/Headers/vGarbageCollector.h>

class vEntry {
private:
    int idRef;
    void* offset;
    unsigned int dataSize;
    bool useFlag;
    unsigned int numReferences;

public:
    vEntry();
    vEntry(int, int, void*);
    void changeFlag();
    int getIdRef();
    void* getOffSet();
    int getDataSize();
    bool getUseFlag();
    unsigned int getNumReferences();
    void decreaseNumReferences();
    void increaseNumReferences();
    int operator!();                //idRef
    void* operator&();              //Offset
    int operator[](int);            //setID
    int operator[](void*);          //setOffset
};


#endif //VH2015_VMALLOCMDENTRY_H
