//
// Created by roberto on 30/03/15.
//

#include "vheap/vRef.h"
#include "vheap/vObject.h"

#ifndef _VH2015_VLONG_H_
#define _VH2015_VLONG_H_


class vLong {
    vRef* address;
public:
    vLong(long);
    ~vLong();
    int operator +=(long);
    int operator --();
    int operator !();
    vRef operator &();
};


#endif //_VH2015_VLONG_H_
