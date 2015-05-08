//
// Created by roberto on 29/03/15.
//


#ifndef _VH2015_VSTRING_H_
#define _VH2015_VSTRING_H_

#include "vSimpleList.h"
#include <iostream>

class vString{
    vSimpleList<char> word;
    public:
        vString(std::string);
        int len();
        bool operator >=(std::string);
        bool operator >=(vString);
        void operator =(std::string);
        void operator =(vString);
        void operator +=(std::string);
        void operator +=(vString);
        void operator +=(vNumber<char>);
        void operator +=(char);
        void operator --();
        char operator [](int);
        std::string operator !();
	    bool operator==(std::string);
	    bool operator==(vString);
};

#endif //_VH2015_VSTRING_H_
