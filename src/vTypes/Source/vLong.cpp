//
// Created by roberto on 30/03/15.
//

#include "vTypes/Headers/vLong.h"

vLong::vLong(){
    data = 0;
    ref = static_cast<vRef*>(malloc(sizeof(vRef)));
    new(ref) vRef(vMalloc(sizeof(vLong)));
    vLong* ret = this;
    vPlacement(*ref,*ret);
};

vLong::~vLong(){
    vFree(!ref);
};

vLong vLong::operator = (long var){
    if(!ref){
        data = var;
        ref = static_cast<vRef*>(malloc(sizeof(vRef)));
        new(ref) vRef(vMalloc(sizeof(vLong)));
        vLong* ret = this;
        vPlacement(*ref,*ret);
        return *ret;
    }else{
        data = var;
        vLong* ret = this;
        return *ret;
    };
};

vLong vLong::operator =(vLong var){
    if(!ref){
        data = !var;
        ref = static_cast<vRef*>(malloc(sizeof(vRef)));
        new(ref) vRef(vMalloc(sizeof(vLong)));
        vLong* ret = this;
        vPlacement(*ref,*ret);
        return *ret;
    }else{
        data = !var;
        vLong* ret = this;
        return *ret;
    };
};

vRef vLong::operator &() {
    return vRef(!*ref);
};

void vLong::operator +=(long pls){
    data += pls;
};

void vLong::operator --(){
    (data)--;
};

void vLong::operator ++(){
    (data)++;
};

long vLong::operator !(){
    return data;
};

bool vLong::operator <(vLong other){
    return data < (!other);
};

bool vLong::operator <=(vLong other){
    return data <= (!other);
};

bool vLong::operator >(vLong other){
    return data > (!other);
};

bool vLong::operator >=(vLong other){
    return data >= (!other);
};

bool vLong::operator ==(vLong other){
    return data == (!other);
};

bool vLong::operator !=(vLong other){
    return data != (!other);
};

bool vLong::operator <(long other){
    return data < other;
};

bool vLong::operator <=(long other){
    return data <= other;
};

bool vLong::operator >(long other){
    return data > other;
};

bool vLong::operator >=(long other){
    return data >= other;
};

bool vLong::operator ==(long other){
    return data == other;
};

bool vLong::operator !=(long other){
    return data != other;
};