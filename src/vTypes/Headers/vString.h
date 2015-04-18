//
// Created by roberto on 29/03/15.
//


#ifndef _VH2015_VSTRING_H_
#define _VH2015_VSTRING_H_

#include "vSimpleList.h"
#include "vChar.h"
#include <iostream>

class vString{
    vSimpleList<vChar> word;
    public:
        vString(std::string);
        ~vString();
        vInt len();
        void operator =(std::string);
        void operator =(vString);
        void operator +=(std::string);
        void operator +=(vString);
        void operator +=(vChar);
        void operator --();
        vChar operator [](vInt);
        std::string operator !();
	    bool operator==(std::string);
	    bool operator==(vString);
};

#endif //_VH2015_VSTRING_H_
