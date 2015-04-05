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
        char data;
        int ref=0;
    public:
        vChar();
        ~vChar();
        vChar operator =(char);
        vChar operator =(vChar);
        vRef operator &();
        char operator !();
        void operator +=(char);
        void operator --();
        void operator ++();
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
