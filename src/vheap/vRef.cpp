//
// Created by alex on 18/03/15.
//
#include "vRef.h"

vRef::vRef(int id){
    referenceID=id;
};

vRef::~vRef(){};

void vRef::changeID(int id) {
    referenceID = id;
};