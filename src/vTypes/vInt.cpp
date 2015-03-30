//
// Created by roberto on 30/03/15.
//

#include "vInt.h"

vInt::vInt(int data){
    address= static_cast<vRef*>(malloc(sizeof(vRef)));
    *address = vHeap::getInstance()->vMalloc(sizeof(int),"vInt");
};

vInt::~vInt(){};

int vInt::operator +=(int){};

int vInt::operator --(){};

int vInt::operator !(){};

vRef vInt::operator &(){
    return *address;
};