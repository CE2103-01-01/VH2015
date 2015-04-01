//
// Created by roberto on 30/03/15.
//

#ifndef _VH2015_VCHAR_H_
#define _VH2015_VCHAR_H_

#include "vHeap/Headers/vRef.h"
#include "../libs/vheaplib.h"
#include "vObject.h"
#include <iostream>

class vChar: public vObject{
        vRef data;
    public:
        vChar(char);
        ~vChar();
        int operator =(char);
        char operator !();
        int operator +=(char);
        vRef operator &();
        int operator --();
        bool operator <(vChar);
        bool operator <=(vChar);
        bool operator >(vChar);
        bool operator >=(vChar);
        bool operator ==(vChar);
        bool operator !=(vChar);
};


#endif //_VH2015_VCHAR_H_
