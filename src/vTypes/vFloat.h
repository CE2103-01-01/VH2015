//
// Created by roberto on 30/03/15.
//


#include "vheap/vRef.h"
#include "vheap/vObject.h"

#ifndef _VH2015_VFLOAT_H_
#define _VH2015_VFLOAT_H_


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
