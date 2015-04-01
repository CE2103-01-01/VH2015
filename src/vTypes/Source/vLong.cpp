//
// Created by roberto on 30/03/15.
//

#include "vTypes/Headers/vLong.h"

vLong::vLong(long d){
    data = vHeap::getInstance()->vMalloc(sizeof(d),"vlong");
    vHeap::getInstance()->vPlacement(data,d);
};

vLong::~vLong(){};

int vLong::operator +=(long){};

int vLong::operator --(){};

int vLong::operator !(){};

vRef vLong::operator &(){};
