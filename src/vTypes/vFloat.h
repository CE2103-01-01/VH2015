//
// Created by roberto on 30/03/15.
//



#ifndef _VH2015_VFLOAT_H_
#define _VH2015_VFLOAT_H_

#include "vheap/vRef.h"
#include "vheap/vObject.h"

class vFloat {
    vRef* address;
public:
    vFloat(float);
    ~vFloat();
    int operator +=(float);
    int operator --();
    int operator !();
    vRef operator &();
};


#endif //_VH2015_VFLOAT_H_
