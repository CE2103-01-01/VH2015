//
// Created by roberto on 29/03/15.
//

#include "vRef.h"

#ifndef _VH2015_VOBJECT_H_
#define _VH2015_VOBJECT_H_


class vObject {
    vRef* ref;
public:
    vObject();
    ~vObject();
    int operator =(vObject);
    vRef operator *();
    bool operator ==(vObject);
};


#endif //_VH2015_VOBJECT_H_
