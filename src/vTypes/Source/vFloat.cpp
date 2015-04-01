//
// Created by roberto on 30/03/15.
//

#include "vTypes/Headers/vFloat.h"

vFloat::vFloat(float d){
    data = vMalloc(sizeof(d),"float");
    vPlacement(data,d);
};

vFloat::~vFloat(){
    vFree(data);
};

vRef vFloat::operator &(){
    return data;
};

int vFloat::operator +=(float pls){
    try{
        *static_cast<float*>(*data)+pls;
        return 0;
    }catch(int e){
        return -1;
    };
};

int vFloat::operator --(){
    try{
        *static_cast<float*>(*data)-1;
        return 0;
    }catch(int e){
        return -1;
    };
};

float vFloat::operator !(){
    try{
        return *static_cast<float*>(*data);
    }catch(int e){
        return -1;
    };
};

int vFloat::operator =(float var){
    try{
        *static_cast<float*>(*data)=var;
        return 0;
    }catch(int e){
        return -1;
    };
};