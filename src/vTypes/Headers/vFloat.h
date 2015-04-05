//
// Created by roberto on 30/03/15.
//



#ifndef _VH2015_VFLOAT_H_
#define _VH2015_VFLOAT_H_

#include "vHeap/Headers/vRef.h"
#include "vObject.h"
#include "../libs/vheaplib.h"

class vFloat : public vObject{
        vRef<float> data;
    public:
        vFloat();
        vFloat(float);
        ~vFloat();
        float operator !();
        int operator +=(float);
        vRef<float> operator &();
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
