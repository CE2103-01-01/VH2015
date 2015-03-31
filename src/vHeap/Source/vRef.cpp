//
// Created by pablo on 28/03/15.
//

#include "vHeap/Headers/vRef.h"

vRef::vRef(int id){
    referenceID=id;
};

vRef::vRef(){};

vRef::~vRef(){};

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