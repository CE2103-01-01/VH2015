//
// Created by pablo on 28/03/15.
//

#include "vHeap/Headers/vRef.h"

vRef::vRef(int id){
    referenceID=id;
    vHeap::getInstance()->addVRef(referenceID); // aumenta contador de referencias
};

vRef::vRef(){
    referenceID=0;
};

vRef::~vRef() {
    vHeap::getInstance()->removeVRef(referenceID); // disminuye contador de referencias
};

int vRef::operator!() {
    return referenceID;
};

void* vRef::operator*() {
    return vHeap::getInstance()->de_vReference(referenceID);
};

int vRef::operator=(int id){
    referenceID=id;
    vHeap::getInstance()->addVRef(referenceID); // aumenta contador de referencias
    return 0;
};

int vRef::operator=(vRef other){
    referenceID=!other;
    vHeap::getInstance()->addVRef(referenceID); // aumenta contador de referencias
    return 0;
};