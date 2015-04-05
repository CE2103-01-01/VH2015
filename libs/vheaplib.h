//
// Created by roberto on 31/03/15.
//

#ifndef _VH2015_HEAP_H_
#define _VH2015_HEAP_H_

#include "../src/vHeap/Headers/vHeap.h"
#include "../src/vHeap/Headers/vRef.h"
#include "vTypes/Headers/vObject.h"

class vRef;
class vObject;


void vFree(int toFree);

void vFree(vRef toFree);

unsigned int vMalloc(unsigned int);

int vPlacement(vRef vR, vObject toPlace);


#endif //_VH2015_HEAP_H_
