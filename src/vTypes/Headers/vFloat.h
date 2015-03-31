//
// Created by roberto on 30/03/15.
//



#ifndef _VH2015_VFLOAT_H_
#define _VH2015_VFLOAT_H_

#include "vHeap/Headers/vRef.h"
#include "vHeap/Headers/vObject.h"
#include "vHeap/Headers/vHeap.h"

class vFloat : public vObject{
    vRef address;
public:
    vFloat(float);
    ~vFloat();
    int operator +=(float);
    int operator --();
    int operator !();
    vRef operator &();
};


#endif //_VH2015_VFLOAT_H_
