//
// Created by roberto on 30/03/15.
//

#ifndef _VH2015_VCHAR_H_
#define _VH2015_VCHAR_H_

#include "vHeap/Headers/vRef.h"
#include "../libs/vheaplib.h"
#include <iostream>

void vFree(int toFree);
unsigned int vMalloc(unsigned int);
template<class T> void vFree(vRef<T> toFree);
template<class T> int vPlacement(vRef<T> vR, T toPlace);

class vChar{
        char data;
        vRef<vChar> vThis;
    public:
        vChar();
        vChar(char);
        ~vChar();
        int operator =(char);
        int operator =(vChar);
        char operator !();
        int operator +=(char);
        vRef<vChar> operator &();
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
