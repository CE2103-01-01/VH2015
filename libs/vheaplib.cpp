//
// Created by roberto on 31/03/15.
//

#include "vheaplib.h"

vRef vMalloc(int vSize, std::string vType){
    vHeap::getInstance()->vMalloc(vSize, vType);
};
void vFree(vRef toFree){
    vHeap::getInstance()->vFree(toFree);
};
void vFree(unsigned int toFree){
    vHeap::getInstance()->vFree(toFree);
};

void* de_vReference(vRef toDeRef){
    return vHeap::getInstance()->de_vReference(toDeRef);
};