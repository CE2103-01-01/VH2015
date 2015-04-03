//
// Created by roberto on 03/04/15.
//

#include "vheaplibpp.h"

int removeVRef(int id){
    return vHeap::getInstance()->addVRef(id);
};

int addVRef(int id){
    return vHeap::getInstance()->removeVRef(id);
};

void* de_vReference(int id){
    return vHeap::getInstance()->de_vReference(id);
};