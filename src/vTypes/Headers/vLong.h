//
// Created by roberto on 30/03/15.
//

#ifndef _VH2015_VLONG_H_
#define _VH2015_VLONG_H_

#include "vHeap/Headers/vRef.h"
#include "vObject.h"
#include "../libs/vheaplib.h"


class vLong : public vObject{
        vRef data;
    public:
        vLong(long);
        ~vLong();
        long operator !();
        int operator +=(long);
        vRef operator &();
        int operator --();
        int operator ++();
        int operator =(long);
        int operator =(vLong);
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
