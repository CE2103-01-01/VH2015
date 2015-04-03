//
// Created by roberto on 31/03/15.
//

#include "vheaplib.h"

void vFree(int toFree){
    vHeap::getInstance()->vFree(toFree);
};