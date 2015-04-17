//
// Created by roberto on 30/03/15.
//



#ifndef _VH2015_VFLOAT_H_
#define _VH2015_VFLOAT_H_


#include "vHeap/Headers/vRef.h"
#include "../libs/vheaplib.h"

void vFree(int toFree);
unsigned int vMalloc(unsigned int);
template<class T> void vFree(vRef<T> toFree);
template<class T> int vPlacement(vRef<T> vR, T toPlace);

class vFloat{
    vRef<float> data;
public:
    vFloat();
    vFloat(float);
    vFloat operator +(vFloat);
    vFloat operator +(float);
    float operator !();
    void operator +=(float);
    void operator +=(vFloat);
    void operator --();
    void operator ++();
    void operator =(float);
    void operator =(vFloat);
    bool operator <(vFloat);
    bool operator <=(vFloat);
    bool operator >(vFloat);
    bool operator >=(vFloat);
    bool operator ==(vFloat);
    bool operator !=(vFloat);
    bool operator <(float);
    bool operator <=(float);
    bool operator >(float);
    bool operator >=(float);
    bool operator ==(float);
    bool operator !=(float);
};

#endif //_VH2015_VFLOAT_H_
