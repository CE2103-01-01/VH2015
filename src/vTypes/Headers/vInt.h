//
// Created by roberto on 30/03/15.
//

#ifndef _VH2015_VINT_H_
#define _VH2015_VINT_H_


#include "vHeap/Headers/vRef.h"
#include "../libs/vheaplib.h"

class vInt{
        int data;
        vRef<vInt> vThis;
    public:
        vInt();
        vInt(int);
        ~vInt();
        int operator !();
        int operator +=(int);
        vRef<vInt> operator &();
        int operator --();
        int operator ++();
        int operator =(int);
        int operator =(vInt);
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
