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
    unsigned int idRef = 0;
    void *offset = 0;
    unsigned int dataSize = 0;
    bool useFlag;   //TODO: usar
    unsigned int numReferences = 0;
    bool onHeap;
    std::string path;
public:
    vEntry();
    vEntry(int, int, void*);
    vEntry(int, int, void*, bool, std::string);
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
    void fileDown(std::string);
    void fileUp(void*);
    bool isOnHeap();
    std::string getPath();
};


#endif //VH2015_VENTRY_H
