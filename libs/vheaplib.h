//
// Created by roberto on 31/03/15.
//

#ifndef _VH2015_HEAP_H_
#define _VH2015_HEAP_H_

#include "../src/vHeap/Headers/vHeap.h"

template<class T> vRef<T> vMalloc(int, std::string);
template<class T> void vFree(vRef<T>);
template<class T> int vPlacement(vRef<T>, T);
void vFree(unsigned int);

template<class T> vRef<T> vMalloc(int vSize, std::string vType){
    vHeap::getInstance()->vMalloc<T>(vSize, vType);
};
template<class T> void vFree(vRef<T> toFree){
    vHeap::getInstance()->vFree<T>(toFree);
};

template<class T> int vPlacement(vRef<T> vR, T toPlace) {
    vHeap::getInstance()->vPlacement<T>(vR, toPlace);
};

#endif //_VH2015_HEAP_H_
