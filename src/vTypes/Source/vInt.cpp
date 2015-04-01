//
// Created by roberto on 30/03/15.
//

#include "vTypes/Headers/vInt.h"

vInt::vInt(int d){
    data = vMalloc(sizeof(d),"int");
    vPlacement(data,d);
};

vInt::~vInt(){
    vObject::~vObject();
};

int vInt::operator +=(int pls){};

int vObject::operator --(){};

int vObject::operator !(){
    try{
        return *static_cast<int*>(*data);
    }catch(int e){
        return -1;
    };
};

vRef vObject::operator &(){};