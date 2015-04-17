//
// Created by roberto on 30/03/15.
//

#ifndef _VH2015_VLONG_H_
#define _VH2015_VLONG_H_

#include "vHeap/Headers/vRef.h"
#include "../libs/vheaplib.h"

void vFree(int toFree);
unsigned int vMalloc(unsigned int);
template<class T> void vFree(vRef<T> toFree);
template<class T> int vPlacement(vRef<T> vR, T toPlace);

class vLong{
    long data;
public:
    vLong();
    vLong(long);
    vLong operator +(vLong);
    vLong operator +(long);
    long operator !();
    void operator +=(long);
    void operator +=(vLong);
    void operator --();
    void operator ++();
    void operator =(long);
    void operator =(vLong);
    bool operator <(vLong);
    bool operator <=(vLong);
    bool operator >(vLong);
    bool operator >=(vLong);
    bool operator ==(vLong);
    bool operator !=(vLong);
    bool operator <(long);
    bool operator <=(long);
    bool operator >(long);
    bool operator >=(long);
    bool operator ==(long);
    bool operator !=(long);
};

#endif //_VH2015_VLONG_H_
