//
// Created by alex on 18/03/15.
//

#ifndef _VH2015_VREF_H_
#define _VH2015_VREF_H_

#include "vHeap.h"

class vRef {
        int referenceID;
    public:
        vRef();
        vRef(int);
        ~vRef();
        void* operator *();
        int operator !();
        int operator =(int);
        int operator =(vRef);
        int operator ++();
        int operator --();
};

#endif //_VH2015_VREF_H_
