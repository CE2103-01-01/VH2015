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
        vObject operator =(vObject);
        bool operator <(vObject);
        bool operator <=(vObject);
        bool operator >(vObject);
        bool operator >=(vObject);
        bool operator ==(vObject);
        bool operator !=(vObject);
};


#endif //_VH2015_VOBJECT_H_
