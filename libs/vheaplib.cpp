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

void vFree(vRef toFree) {
    vHeap::getInstance()->vFree(toFree);
};

int vPlacement(vRef vR, vObject toPlace) {
    return vHeap::getInstance()->vPlacement(vR, toPlace);
};