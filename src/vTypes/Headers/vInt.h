//
// Created by roberto on 30/03/15.
//

#ifndef _VH2015_VINT_H_
#define _VH2015_VINT_H_


#include "vHeap/Headers/vRef.h"
#include "vHeap/Headers/vObject.h"
#include "vHeap/Headers/vHeap.h"

class vInt : public vObject{
    vRef address;
public:
    vInt(int);
    ~vInt();
    int operator +=(int);
    int operator --();
    int operator !();
    vRef operator &();
};


#endif //_VH2015_VINT_H_
