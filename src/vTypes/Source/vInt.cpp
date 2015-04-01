//
// Created by roberto on 30/03/15.
//

#include "vTypes/Headers/vInt.h"

vInt::vInt(int d){
    data = vHeap::getInstance()->vMalloc(sizeof(d),"int");
    vHeap::getInstance()->vPlacement(data,d);
};

vInt::~vInt(){};

int vInt::operator +=(int){};

int vInt::operator --(){};

int vInt::operator !(){};

vRef vInt::operator &(){};