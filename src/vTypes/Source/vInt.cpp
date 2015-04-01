//
// Created by roberto on 30/03/15.
//

#include "vTypes/Headers/vInt.h"

vInt::vInt(int d){
    data = vHeap::getInstance()->vMalloc(sizeof(d),"int");
    vHeap::getInstance()->vPlacement(data,d);
};

vInt::~vInt(){};

int vInt::operator +=(int pls){};

int vInt::operator --(){};

int vInt::operator !(){
    try{
        return *static_cast<int*>(*data);
    }catch(int e){
        return -1;
    };
};

vRef vInt::operator &(){};