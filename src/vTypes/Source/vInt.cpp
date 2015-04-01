//
// Created by roberto on 30/03/15.
//

#include "vTypes/Headers/vInt.h"

vInt::vInt(int d){
    data = vMalloc(sizeof(d),"int");
    vPlacement(data,d);
};

vInt::~vInt(){
    vFree(data);
};

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