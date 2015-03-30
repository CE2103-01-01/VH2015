//
// Created by roberto on 29/03/15.
//

#include "List.h"
#include <iostream>

#ifndef _VH2015_VSTRING_H_
#define _VH2015_VSTRING_H_


class vString{
    List<char>* word;
    public:
        vString(std::string);
        ~vString();
        int operator +=(std::string);
        char operator [](int);
        int operator --();
        int operator !();
};


#endif //_VH2015_VSTRING_H_
