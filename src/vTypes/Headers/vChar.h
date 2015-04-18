//
// Created by roberto on 30/03/15.
//

#ifndef _VH2015_VCHAR_H_
#define _VH2015_VCHAR_H_

#include "vHeap/Headers/vRef.h"
#include "../libs/vheaplib.h"

void vFree(int toFree);
unsigned int vMalloc(unsigned int);
template<class T> void vFree(vRef<T> toFree);
template<class T> int vPlacement(vRef<T> vR, T toPlace);

class vChar{
    vRef<char> data;
public:
    vChar();
    vChar(char);
    vChar operator +(vChar);
    vChar operator +(char);
    char operator !();
    void operator +=(char);
    void operator +=(vChar);
    void operator --();
    void operator ++();
    void operator =(char);
    void operator =(vChar);
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
