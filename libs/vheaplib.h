//
// Created by roberto on 31/03/15.
//

#ifndef _VH2015_VHEAPLIB_H_
#define _VH2015_VHEAPLIB_H_

#include "../src/vHeap/Headers/vHeap.h"
#include "../src/vHeap/Headers/vRef.h"


void vFree(int);
unsigned int vMalloc(unsigned int);
unsigned int vCalloc(unsigned int);
template<class T> void vFree(vRef<T> toFree) {
    vHeap::getInstance()->vFree(toFree);
};
template<class T> int vPlacement(vRef<T> vR, T toPlace) {
    return vHeap::getInstance()->vPlacement<T>(vR, toPlace);
};


#endif //_VH2015_VHEAPLIB_H_
