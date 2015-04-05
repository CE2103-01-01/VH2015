//
// Created by roberto on 31/03/15.
//

#include "vheaplib.h"

void vFree(int toFree){
    vHeap::getInstance()->vFree(toFree);
};

unsigned int vMalloc(unsigned int vSize) {
    return vHeap::getInstance()->vMalloc(vSize);
};

template<class T>
void vFree(vRef<T> toFree) {
    vHeap::getInstance()->vFree(toFree);
};

template<class T>
int vPlacement(vRef<T> vR, T toPlace) {
    return vHeap::getInstance()->vPlacement<T>(vR, toPlace);
};