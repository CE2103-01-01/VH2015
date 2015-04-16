//
// Created by roberto on 29/03/15.
//


#ifndef _VH2015_VSTRING_H_
#define _VH2015_VSTRING_H_

#include "vList.h"
#include <iostream>

class vString{
    vList<char> *word;
    public:
        vString(std::string);
        ~vString();
        unsigned int len();
        int operator +=(std::string);
        int operator +=(vString);
	    int operator =(vString);
	    int operator =(std::string);
        char operator [](int);
        int operator --();
        vList<char>* operator !();
	    bool operator==(std::string);
	    bool operator==(vString);
        bool operator>=(vString);
};


#endif //_VH2015_VSTRING_H_
