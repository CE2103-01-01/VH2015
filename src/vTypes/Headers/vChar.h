//
// Created by roberto on 30/03/15.
//

#ifndef _VH2015_VCHAR_H_
#define _VH2015_VCHAR_H_

#include "vHeap/Headers/vRef.h"
#include "vHeap/Headers/vObject.h"
#include "vHeap/Headers/vHeap.h"
#include <iostream>

class vChar: public vObject{
        vRef data;
    public:
        vChar(char);
        ~vChar();
        int operator +=(char);
        int operator --();
        char operator !();
        vRef operator &();
};


#endif //_VH2015_VCHAR_H_
