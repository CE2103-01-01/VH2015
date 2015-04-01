//
// Created by roberto on 30/03/15.
//

#include "vTypes/Headers/vLong.h"
class vHeap;
vLong::vLong(long d){
    *data = vHeap::getInstance()->vMalloc(sizeof(d),"long");
    vHeap::getInstance()->vPlacement(data,d);
};

vLong::~vLong(){};

int vLong::operator +=(long pls){};

int vLong::operator --(){};

int vLong::operator !(){
    try{
        return *static_cast<long*>(*data);
    }catch(int e){
        return -1;
    };
};

vRef vLong::operator &(){};
