//
// Created by roberto on 30/03/15.
//

#include "vTypes/Headers/vLong.h"

vLong::vLong(long d){
    data = vMalloc(sizeof(d),"long");
    vPlacement(data,d);
};

vLong::~vLong(){
    vFree(data);
};

int vLong::operator +=(long pls){};

int vLong::operator --(){};

long vLong::operator !(){
    try{
        return *static_cast<long*>(*data);
    }catch(int e){
        return -1;
    };
};

vRef vLong::operator &(){};
