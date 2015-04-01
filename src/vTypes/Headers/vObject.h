//
// Created by roberto on 29/03/15.
//


#ifndef _VH2015_VOBJECT_H_
#define _VH2015_VOBJECT_H_

#include "../libs/vheaplib.h"

class vObject {
    public:
        vObject();
        ~vObject();
        vRef operator &();
        int operator --();
};


#endif //_VH2015_VOBJECT_H_
