//
// Created by roberto on 30/03/15.
//



#ifndef _VH2015_VFLOAT_H_
#define _VH2015_VFLOAT_H_

#include "vHeap/Headers/vRef.h"
#include "vObject.h"
#include "../libs/vheaplib.h"

class vFloat : public vObject{
        vRef data;
    public:
        vFloat(float);
        ~vFloat();
        float operator !();
        int operator +=(float);
        vRef operator &();
        int operator --();
        int operator =(float);
        bool operator <(vFloat);
        bool operator <=(vFloat);
        bool operator >(vFloat);
        bool operator >=(vFloat);
        bool operator ==(vFloat);
        bool operator !=(vFloat);
};


#endif //_VH2015_VFLOAT_H_
