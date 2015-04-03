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
        vRef<char> data;
    public:
        vChar();
        vChar(char);
        ~vChar();
        int operator =(char);
        int operator =(vChar);
        char operator !();
        int operator +=(char);
        vRef<char> operator &();
        int operator --();
        int operator ++();
        bool operator <(vChar);
        bool operator <=(vChar);
        bool operator >(vChar);
        bool operator >=(vChar);
        bool operator ==(vChar);
        bool operator !=(vChar);
        bool operator <(char);
        bool operator <=(char);
        bool operator >(char);
        bool operator >=(char);
        bool operator ==(char);
        bool operator !=(char);
};


#endif //_VH2015_VCHAR_H_
