//
// Created by roberto on 31/03/15.
//

#include "vheaplib.h"

vRef vMalloc(int, std::string){
    vHeap::getInstance()->vMalloc(int, std::string);
};
void vFree(vRef){
    vHeap::getInstance()->vFree(vRef);
};
void vFree(unsigned int){
    vHeap::getInstance()->vFree(unsigned int);
};
template <typename T> int vPlacement(vRef,T){
    vHeap::getInstance()->vPlacement(vRef,T);
};
void *de_vReference(vRef){
    vHeap::getInstance()->*de_vReference(vRef);
};