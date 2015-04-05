//
// Created by roberto on 30/03/15.
//



#ifndef _VH2015_VFLOAT_H_
#define _VH2015_VFLOAT_H_

#include "vHeap/Headers/vRef.h"
#include "vObject.h"
#include "../libs/vheaplib.h"

class vFloat: public vObject{
    float data;
    int ref=0;
public:
    vFloat();
    ~vFloat();
    vFloat operator =(float);
    vFloat operator =(vFloat);
    vRef operator &();
    float operator !();
    void operator +=(float);
    void operator --();
    void operator ++();
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
