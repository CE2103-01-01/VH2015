//
// Created by roberto on 30/03/15.
//

#include "vTypes/Headers/vFloat.h"

vFloat::vFloat(){
    data = vRef<float>(vMalloc(sizeof(float)));
};

vFloat::vFloat(float d){
    data = vRef<float>(vMalloc(sizeof(float)));
    vPlacement<float>(data, d);
};

vFloat::~vFloat(){
    vFree(!data);
};

vRef<float> vFloat::operator &(){
    return data;
};

int vFloat::operator +=(float pls){
    try{
        (**data) += pls;
        return 0;
    }catch(int e){
        return -1;
    };
};

int vFloat::operator --(){
    try{
        ((**data))--;
        return 0;
    }catch(int e){
        return -1;
    };
};

int vFloat::operator ++(){
    try{
        ((**data))++;
        return 0;
    }catch(int e){
        return -1;
    };
};

float vFloat::operator !(){
    try{
        return (**data);
    }catch(int e){
        return -1;
    };
};

int vFloat::operator =(float var){
    try{
        (**data) = var;
        return 0;
    }catch(int e){
        return -1;
    };
};

int vFloat::operator =(vFloat var){
    try{
        (**data) = (!var);
        return 0;
    }catch(int e){
        return -1;
    };
};

bool vFloat::operator <(vFloat other){
    return (**data) < (!other);
};

bool vFloat::operator <=(vFloat other){
    return (**data) <= (!other);
};

bool vFloat::operator >(vFloat other){
    return (**data) > (!other);
};

bool vFloat::operator >=(vFloat other){
    return (**data) >= (!other);
};

bool vFloat::operator ==(vFloat other){
    return (**data) == (!other);
};

bool vFloat::operator !=(vFloat other){
    return (**data) != (!other);
};

bool vFloat::operator <(float other){
    return (**data) < other;
};

bool vFloat::operator <=(float other){
    return (**data) <= other;
};

bool vFloat::operator >(float other){
    return (**data) > other;
};

bool vFloat::operator >=(float other){
    return (**data) >= other;
};

bool vFloat::operator ==(float other){
    return (**data) == other;
};

bool vFloat::operator !=(float other){
    return (**data) != other;
};