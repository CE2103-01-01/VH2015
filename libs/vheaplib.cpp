//
// Created by roberto on 31/03/15.
//

#include "vheaplib.h"

void vFree(unsigned int toFree){
    vHeap::getInstance()->vFree(toFree);
};