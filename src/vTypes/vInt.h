//
// Created by roberto on 30/03/15.
//

#include "vheap/vRef.h"
#include "vheap/vObject.h"

#ifndef _VH2015_VINT_H_
#define _VH2015_VINT_H_


class vInt {
    vRef* address;
public:
    vInt(int);
    ~vInt();
    int operator +=(int);
    int operator --();
    int operator !();
    vRef operator &();
};


#endif //_VH2015_VINT_H_
