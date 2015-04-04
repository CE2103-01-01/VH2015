//
// Created by roberto on 31/03/15.
//

#ifndef _VH2015_HEAP_H_
#define _VH2015_HEAP_H_

#include "../src/vHeap/Headers/vHeap.h"
#include "../src/vHeap/Headers/vRef.h"

vHeap *heap = vHeap::getInstance();

void vFree(int toFree);

template<class T> vRef<T> vMalloc(int vSize, std::string vType){
    return vHeap::getInstance()->vMalloc<T>(vSize, vType);
};
template<class T> void vFree(vRef<T> toFree){
    vHeap::getInstance()->vFree(toFree);
};

template<class T> int vPlacement(vRef<T> vR, T toPlace) {
    return vHeap::getInstance()->vPlacement<T>(vR, toPlace);
};

void vFree(int toFree) {
    vHeap::getInstance()->vFree(toFree);
};

#endif //_VH2015_HEAP_H_
