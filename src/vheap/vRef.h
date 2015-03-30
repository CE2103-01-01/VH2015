//
// Created by alex on 18/03/15.
//

#ifndef _VH2015_VREF_H_
#define _VH2015_VREF_H_

#include "vObject.h"

class vRef {
    protected:
        int* referenceID;
    public:
        vRef();
        vRef(int ID);
        void changeID(int);
        int getPtr();
        virtual ~vRef();
        int operator *();
        void operator=(vRef ptr);
        void operator=(vObject dato);
};

#endif //_VH2015_VREF_H_
