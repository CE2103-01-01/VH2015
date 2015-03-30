//
// Created by roberto on 30/03/15.
//

#include "vLong.h"

vLong::vLong(long data){
    address= static_cast<vRef*>(malloc(sizeof(vRef)));
    *address = vHeap::getInstance()->vMalloc(sizeof(long),"vLong");
};

vLong::~vLong(){};

int vLong::operator +=(long){};

int vLong::operator --(){};

int vLong::operator !(){};

vRef vLong::operator &(){
    return *address;
};
