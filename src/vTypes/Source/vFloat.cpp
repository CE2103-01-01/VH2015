//
// Created by roberto on 30/03/15.
//

#include "vTypes/Headers/vFloat.h"

vFloat::vFloat(){
    data = 0;
    ref = static_cast<vRef*>(malloc(sizeof(vRef)));
    new(ref) vRef(vMalloc(sizeof(vFloat)));
    vFloat* ret = this;
    vPlacement(*ref,*ret);
};

vFloat::~vFloat(){
    vFree(!ref);
};

vFloat vFloat::operator = (float var){
    if(!ref){
        data = var;
        ref = static_cast<vRef*>(malloc(sizeof(vRef)));
        new(ref) vRef(vMalloc(sizeof(vFloat)));
        vFloat* ret = this;
        vPlacement(*ref,*ret);
        return *ret;
    }else{
        data = var;
        vFloat* ret = this;
        return *ret;
    };
};

vFloat vFloat::operator =(vFloat var){
    if(!ref){
        data = !var;
        ref = static_cast<vRef*>(malloc(sizeof(vRef)));
        new(ref) vRef(vMalloc(sizeof(vFloat)));
        vFloat* ret = this;
        vPlacement(*ref,*ret);
        return *ret;
    }else{
        data = !var;
        vFloat* ret = this;
        return *ret;
    };
};

vRef vFloat::operator &() {
    return vRef(!*ref);
};
void vFloat::operator +=(float pls){
    data += pls;
};

void vFloat::operator --(){
    (data)--;
};

void vFloat::operator ++(){
    (data)++;
};

float vFloat::operator !(){
    return data;
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