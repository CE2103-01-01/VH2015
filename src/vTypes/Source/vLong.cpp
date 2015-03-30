//
// Created by roberto on 30/03/15.
//

#include "vLong.h"

vLong::vLong(long data){
    address = vHeap::getInstance()->vMalloc(sizeof(vLong),"vLong");
    vHeap::getInstance()->vPlacement(address,this);
};

vLong::~vLong(){};

int vLong::operator +=(long){};

int vLong::operator --(){};

int vLong::operator !(){};

vRef vLong::operator &(){
    return address;
};
