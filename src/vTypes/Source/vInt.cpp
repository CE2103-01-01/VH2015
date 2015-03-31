//
// Created by roberto on 30/03/15.
//

#include "vTypes/Headers/vInt.h"

vInt::vInt(int data){
    address = vHeap::getInstance()->vMalloc(sizeof(vInt),"vInt");
    vHeap::getInstance()->vPlacement(address,this);
};

vInt::~vInt(){};

int vInt::operator +=(int){};

int vInt::operator --(){};

int vInt::operator !(){};

vRef vInt::operator &(){
    return address;
};