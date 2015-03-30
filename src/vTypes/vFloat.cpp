//
// Created by roberto on 30/03/15.
//

#include "vFloat.h"

vFloat::vFloat(float data){
    address = vHeap::getInstance()->vMalloc(sizeof(vFloat),"vFloat");
    vHeap::getInstance()->vPlacement(address,this);
};

vFloat::~vFloat(){};

int vFloat::operator +=(float){};

int vFloat::operator --(){};

int vFloat::operator !(){};

vRef vFloat::operator &(){
    return address;
};
