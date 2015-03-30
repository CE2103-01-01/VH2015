//
// Created by pablo on 28/03/15.
//

#include "vRef.h"

vRef::vRef(int id){
    *referenceID=id;
};

vRef::~vRef(){};

int vRef::operator!() {
    return *referenceID;
};

int vRef::operator*() {};

int vRef::operator=(int id){
    *referenceID=id;
    return 0;
};

int vRef::operator=(vRef other){
    *referenceID=!other;
    return 0;
};