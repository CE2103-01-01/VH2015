//
// Created by roberto on 30/03/15.
//

#include "vTypes/Headers/vFloat.h"

vFloat::vFloat(float d){
    data = vMalloc(sizeof(d),"float");
    vPlacement(data,d);
};

vFloat::~vFloat(){
    vObject::~vObject();
};

int vFloat::operator +=(float pls){};

int vObject::operator --(){};

int vObject::operator !(){
    try{
        return *static_cast<float*>(*data);
    }catch(int e){
        return -1;
    };};

vRef vObject::operator &(){};