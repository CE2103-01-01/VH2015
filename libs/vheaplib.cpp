//
// Created by roberto on 31/03/15.
//

#include "vheaplib.h"

void vFree(int toFree){
    vHeap::getInstance()->vFree(toFree);
}

unsigned int vMalloc(unsigned int vSize) {
    return vHeap::getInstance()->vMalloc(vSize);
}

unsigned int vCalloc(unsigned int vSize) {
    return vHeap::getInstance()->vCalloc(vSize);
}