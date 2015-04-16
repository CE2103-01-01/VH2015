//
// Created by roberto on 30/03/15.
//

#include "vTypes/Headers/vFloat.h"

vFloat::vFloat(){
    data = 0;
    vThis = vRef<vFloat>(vMalloc(sizeof(vFloat)));
    vPlacement(vThis, *this);
};

vFloat::vFloat(float dataParam){
    data = dataParam;
    vThis = vRef<vFloat>(vMalloc(sizeof(vFloat)));
    vPlacement(vThis, *this);
};

vFloat::~vFloat(){};

vRef<vFloat> vFloat::operator &(){
    return vThis;
};

int vFloat::operator +=(float pls){
    try{
        data += pls;
        return 0;
    }catch(int e){
        return -1;
    };
};

int vFloat::operator --(){
    try{
        data -= 1;
        return 0;
    }catch(int e){
        return -1;
    };
};

int vFloat::operator ++(){
    try{
        data += 1;
        return 0;
    }catch(int e){
        return -1;
    };
};

float vFloat::operator !(){
    try{
        return data;
    }catch(int e){
        return 0;
    };
};

int vFloat::operator =(float var){
    try{
        data = var;
        return 0;
    }catch(int e){
        return -1;
    };
};

int vFloat::operator =(vFloat var){
    try{
        data = !var;
        vThis = &var;
        return 0;
    }catch(int e){
        return -1;
    };
};

bool vFloat::operator <(vFloat other){
    return data < (!other);
};

bool vFloat::operator <=(vFloat other){
    return data <= (!other);
};

bool vFloat::operator >(vFloat other){
    return data > (!other);
};

bool vFloat::operator >=(vFloat other){
    return data >= (!other);
};

bool vFloat::operator ==(vFloat other){
    return data == (!other);
};

bool vFloat::operator !=(vFloat other){
    return data != (!other);
};

bool vFloat::operator <(float other){
    return data < other;
};

bool vFloat::operator <=(float other){
    return data <= other;
};

bool vFloat::operator >(float other){
    return data > other;
};

bool vFloat::operator >=(float other){
    return data >= other;
};

bool vFloat::operator ==(float other){
    return data == other;
};

bool vFloat::operator !=(float other){
    return data != other;
};