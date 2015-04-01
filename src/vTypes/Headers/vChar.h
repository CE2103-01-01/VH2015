//
// Created by roberto on 30/03/15.
//

#ifndef _VH2015_VCHAR_H_
#define _VH2015_VCHAR_H_

#include "vHeap/Headers/vRef.h"
#include "../libs/vheaplib.h"
#include <iostream>
class vHeap;
class vChar: public vObject{
    public:
        vChar(char);
        ~vChar();
        int operator +=(char);
};


#endif //_VH2015_VCHAR_H_
