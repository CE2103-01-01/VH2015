//
// Created by roberto on 30/03/15.
//

#include "vheap/vRef.h"
#include "vheap/vObject.h"

#ifndef _VH2015_VCHAR_H_
#define _VH2015_VCHAR_H_

class vChar: public vObject{
        vRef* address;
    public:
        vChar(char);
        ~vChar();
        int operator +=(char);
        int operator --();
        int operator !();
        vRef operator &();
};


#endif //_VH2015_VCHAR_H_
