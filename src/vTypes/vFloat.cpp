//
// Created by roberto on 30/03/15.
//

#include "vFloat.h"

vFloat::vChar(float data){
    address= static_cast<vRef*>(malloc(sizeof(vRef)));
    *address = vHeap::getInstance()->vMalloc(sizeof(float),"vFloat");
};

vFloat::~vChar(){};

int vFloat::operator +=(char){};

int vFloat::operator --(){};

int vFloat::operator !(){};

vRef vFloat::operator &(){
    return *address;
};
