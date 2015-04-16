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
        float data;
        vRef<vFloat> vThis;
    public:
        vFloat();
        vFloat(float);
        ~vFloat();
        float operator !();
        int operator +=(float);
        vRef<vFloat> operator &();
        int operator --();
        int operator ++();
        int operator =(float);
        int operator =(vFloat);
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
