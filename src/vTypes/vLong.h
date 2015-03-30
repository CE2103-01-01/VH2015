//
// Created by roberto on 30/03/15.
//

#ifndef _VH2015_VLONG_H_
#define _VH2015_VLONG_H_

#include "vheap/vRef.h"
#include "vheap/vObject.h"


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
