//
// Created by roberto on 30/03/15.
//

#include "vTypes/Headers/vFloat.h"

vFloat::vFloat(float d){
    data = vHeap::getInstance()->vMalloc(sizeof(d),"float");
    vHeap::getInstance()->vPlacement(data,d);
};

vFloat::~vFloat(){};

int vFloat::operator +=(float){};

int vFloat::operator --(){};

int vFloat::operator !(){};

vRef vFloat::operator &(){};
