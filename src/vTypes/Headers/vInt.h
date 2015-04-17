//
// Created by roberto on 30/03/15.
//

#ifndef _VH2015_VINT_H_
#define _VH2015_VINT_H_

#include "vHeap/Headers/vRef.h"
#include "../libs/vheaplib.h"

void vFree(int toFree);
unsigned int vMalloc(unsigned int);
template<class T> void vFree(vRef<T> toFree);
template<class T> int vPlacement(vRef<T> vR, T toPlace);

class vInt{
    vRef<int> data;
public:
    vInt();
    vInt(int);
    vInt operator +(vInt);
    vInt operator +(int);
    int operator !();
    void operator +=(int);
    void operator +=(vInt);
    void operator --();
    void operator ++();
    void operator =(int);
    void operator =(vInt);
    bool operator <(vInt);
    bool operator <=(vInt);
    bool operator >(vInt);
    bool operator >=(vInt);
    bool operator ==(vInt);
    bool operator !=(vInt);
    bool operator <(int);
    bool operator <=(int);
    bool operator >(int);
    bool operator >=(int);
    bool operator ==(int);
    bool operator !=(int);
};

#endif //_VH2015_VINT_H_
