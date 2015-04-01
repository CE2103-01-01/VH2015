//
// Created by roberto on 30/03/15.
//

#ifndef _VH2015_VLONG_H_
#define _VH2015_VLONG_H_

#include "vHeap/Headers/vRef.h"
#include "vHeap/Headers/vObject.h"
#include "../libs/vheaplib.h"


class vLong : public vObject{
    vRef data;
public:
    vLong(long);
    ~vLong();
    int operator +=(long);
    int operator --();
    int operator !();
    vRef operator &();
};


#endif //_VH2015_VLONG_H_
