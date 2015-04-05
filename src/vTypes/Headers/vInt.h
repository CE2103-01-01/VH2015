//
// Created by roberto on 30/03/15.
//

#ifndef _VH2015_VINT_H_
#define _VH2015_VINT_H_


#include "vHeap/Headers/vRef.h"
#include "vObject.h"
#include "../libs/vheaplib.h"

class vInt: public vObject{
    int data;
    vRef* ref;
public:
    vInt();
    ~vInt();
    vInt operator =(int);
    vInt operator =(vInt);
    vRef operator &();
    int operator !();
    void operator +=(int);
    void operator --();
    void operator ++();
    bool operator <(vInt);
    bool operator <=(vInt);
    bool operator >(vInt);
    bool operator >=(vInt);
    bool operator ==(vInt);
    bool operator !=(vInt);
    bool operator <(int);
    bool operator <=(int);
    bool operator >(int);
    bool operator >=(int);
    bool operator ==(int);
    bool operator !=(int);
};

#endif //_VH2015_VINT_H_
