//
// Created by roberto on 31/03/15.
//

#ifndef _VH2015_HEAP_H_
#define _VH2015_HEAP_H_

#include "../src/vHeap/Headers/vHeap.h"
#include "../src/vHeap/Headers/vRef.h"


void vFree(int toFree);

unsigned int vMalloc(unsigned int);

template<class T>
void vFree(vRef<T> toFree);

template<class T>
int vPlacement(vRef<T> vR, T toPlace);


#endif //_VH2015_HEAP_H_
