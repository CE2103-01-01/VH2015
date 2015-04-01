//
// Created by roberto on 30/03/15.
//



#ifndef _VH2015_VFLOAT_H_
#define _VH2015_VFLOAT_H_

#include "vHeap/Headers/vRef.h"
#include "vHeap/Headers/vObject.h"
#include "../libs/vheaplib.h"

class vFloat : public vObject{
        vRef data;
    public:
        vFloat(float);
        ~vFloat();
        int operator +=(float);
};


#endif //_VH2015_VFLOAT_H_
