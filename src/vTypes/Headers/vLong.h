//
// Created by roberto on 30/03/15.
//

#ifndef _VH2015_VLONG_H_
#define _VH2015_VLONG_H_

#include "vHeap/Headers/vRef.h"
#include "vObject.h"
#include "../libs/vheaplib.h"


class vLong: public vObject{
    long data;
    int ref=0;
public:
    vLong();
    ~vLong();
    vLong operator =(long);
    vLong operator =(vLong);
    vRef operator &();
    long operator !();
    void operator +=(long);
    void operator --();
    void operator ++();
    bool operator <(vLong);
    bool operator <=(vLong);
    bool operator >(vLong);
    bool operator >=(vLong);
    bool operator ==(vLong);
    bool operator !=(vLong);
    bool operator <(long);
    bool operator <=(long);
    bool operator >(long);
    bool operator >=(long);
    bool operator ==(long);
    bool operator !=(long);
};

#endif //_VH2015_VLONG_H_
