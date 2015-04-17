//
// Created by roberto on 30/03/15.
//

#include "vTypes/Headers/vFloat.h"

vFloat::vFloat(){
    data = vMalloc(sizeof(float));
    vPlacement(data,(float)0);
};

vFloat::vFloat(float dataParam){
    data = vMalloc(sizeof(float));
    vPlacement(data,dataParam);
};

float vFloat::operator !(){
    return (**data);
};

vFloat vFloat::operator +(vFloat param){
    (**data) += !param;
    return *this;
};

void vFloat::operator +=(vFloat pls){
    (**data) += !pls;
};

void vFloat::operator =(vFloat var){
    (**data) = !var;
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

vFloat vFloat::operator +(float param){
    (**data) += param;
    return *this;
};

void vFloat::operator +=(float pls){
    (**data) += pls;
};

void vFloat::operator =(float var){
    (**data) = var;
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

void vFloat::operator --(){
    --(**data);
};

void vFloat::operator ++(){
    ++(**data);
};