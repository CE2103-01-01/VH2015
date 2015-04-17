//
// Created by roberto on 30/03/15.
//

#include "vTypes/Headers/vChar.h"

vChar::vChar(){
    data = vMalloc(sizeof(char));
    vPlacement(data,(char)0);
};

vChar::vChar(char dataParam){
    data = vMalloc(sizeof(char));
    vPlacement(data,dataParam);
};

char vChar::operator !(){
    return (**data);
};

vChar vChar::operator +(vChar param){
    (**data) += !param;
    return *this;
};

void vChar::operator +=(vChar pls){
    (**data) += !pls;
};

void vChar::operator =(vChar var){
    (**data) = !var;
};

bool vChar::operator <(vChar other){
    return (**data) < (!other);
};

bool vChar::operator <=(vChar other){
    return (**data) <= (!other);
};

bool vChar::operator >(vChar other){
    return (**data) > (!other);
};

bool vChar::operator >=(vChar other){
    return (**data) >= (!other);
};

bool vChar::operator ==(vChar other){
    return (**data) == (!other);
};

bool vChar::operator !=(vChar other){
    return (**data) != (!other);
};

vChar vChar::operator +(char param){
    (**data) += param;
    return *this;
};

void vChar::operator +=(char pls){
    (**data) += pls;
};

void vChar::operator =(char var){
    (**data) = var;
};

bool vChar::operator <(char other){
    return (**data) < other;
};

bool vChar::operator <=(char other){
    return (**data) <= other;
};

bool vChar::operator >(char other){
    return (**data) > other;
};

bool vChar::operator >=(char other){
    return (**data) >= other;
};

bool vChar::operator ==(char other){
    return (**data) == other;
};

bool vChar::operator !=(char other){
    return (**data) != other;
};

void vChar::operator --(){
    --(**data);
};

void vChar::operator ++(){
    ++(**data);
};