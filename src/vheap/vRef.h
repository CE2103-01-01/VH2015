//
// Created by alex on 18/03/15.
//

#ifndef _VH2015_VREF_H_
#define _VH2015_VREF_H_

#include "vObject.h"

class vRef {
        int* referenceID;
    public:
        vRef();
        vRef(int);
        virtual ~vRef();
        int operator *();
        int operator=(int);
        int operator=(vRef);
        int operator=(vObject);
};

#endif //_VH2015_VREF_H_
