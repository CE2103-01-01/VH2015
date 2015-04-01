//
// Created by pablo on 28/03/15.
//

#include "vHeap/Headers/vRef.h"

vRef::vRef(int id){
    referenceID=id;
    vHeap::getInstance()->addVRef(id); // aumenta contador de referencias
};

vRef::vRef(){};

vRef::~vRef() {
    vHeap::getInstance()->removeVRef(referenceID); // disminuye contador de referencias
};

int vRef::operator!() {
    return referenceID;
};

vObject vRef::operator*() {};

int vRef::operator=(int id){
    referenceID=id;
    return 0;
};

int vRef::operator=(vRef other){
    referenceID=!other;
    return 0;
};

unsigned int vRef::getId() {
    return referenceID;
}
