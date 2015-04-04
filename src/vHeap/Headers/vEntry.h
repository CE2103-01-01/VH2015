//
// Created by pablo on 31/03/15.
//

#ifndef VH2015_VENTRY_H
#define VH2015_VENTRY_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <vHeap/Headers/vGarbageCollector.h>

class vEntry {
private:
    unsigned int idRef = 0;
    void *offset = 0;
    unsigned int dataSize = 0;
    bool useFlag;
    unsigned int numReferences = 0;

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


#endif //VH2015_VENTRY_H
