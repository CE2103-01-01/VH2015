//
// Created by roberto on 30/03/15.
//

#include "vTypes/Headers/vFloat.h"

vFloat::vFloat(float d){
    data = vMalloc(sizeof(d),"float");
    vPlacement(data,d);
};

vFloat::~vFloat(){};

int vFloat::operator +=(float pls){};

int vFloat::operator --(){};

int vFloat::operator !(){
    try{
        return *static_cast<float*>(*data);
    }catch(int e){
        return -1;
    };};

vRef vFloat::operator &(){};
