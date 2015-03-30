//
// Created by roberto on 29/03/15.
//

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
    char const getInstance();
};


#endif //_VH2015_VOBJECT_H_
