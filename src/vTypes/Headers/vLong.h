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
        vRef<vLong> vThis;
    public:
        vLong();
        vLong(long);
        ~vLong();
        long operator !();
        int operator +=(long);
        vRef<vLong> operator &();
        int operator --();
        int operator ++();
        int operator =(long);
        int operator =(vLong);
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
