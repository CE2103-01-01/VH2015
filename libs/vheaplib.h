//
// Created by roberto on 31/03/15.
//

#ifndef _VH2015_HEAP_H_
#define _VH2015_HEAP_H_

#include "../src/vHeap/Headers/vHeap.h"

vRef vMalloc(int, std::string);
void vFree(vRef);
void vFree(unsigned int);

template<typename T>
int vPlacement(vRef *, T);
void* de_vReference(vRef);

template<typename T>
int vPlacement(vRef *vR, T toPlace) {
    vHeap::getInstance()->vPlacement(vR, toPlace);
};

#endif //_VH2015_HEAP_H_
