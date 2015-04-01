//
// Created by roberto on 30/03/15.
//

#ifndef _VH2015_VINT_H_
#define _VH2015_VINT_H_


#include "vHeap/Headers/vRef.h"
#include "vObject.h"
#include "../libs/vheaplib.h"

class vInt : public vObject{
        vRef data;
    public:
        vInt(int);
        ~vInt();
        int operator +=(int);
};


#endif //_VH2015_VINT_H_
