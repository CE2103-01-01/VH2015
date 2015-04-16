//
// Created by roberto on 30/03/15.
//

#include "vTypes/Headers/vLong.h"
vLong::vLong(){
    data = 0;
    vThis = vRef<vLong>(vMalloc(sizeof(vLong)));
    vPlacement(vThis, *this);
};

vLong::vLong(long dataParam){
    data = dataParam;
    vThis = vRef<vLong>(vMalloc(sizeof(vLong)));
    vPlacement(vThis, *this);
};

vLong::~vLong(){};

vRef<vLong> vLong::operator &(){
    return vThis;
};

int vLong::operator +=(long pls){
    try{
        data += pls;
        return 0;
    }catch(int e){
        return -1;
    };
};

int vLong::operator --(){
    try{
        data -= 1;
        return 0;
    }catch(int e){
        return -1;
    };
};

int vLong::operator ++(){
    try{
        data += 1;
        return 0;
    }catch(int e){
        return -1;
    };
};

long vLong::operator !(){
    try{
        return data;
    }catch(int e){
        return 0;
    };
};

int vLong::operator =(long var){
    try{
        data = var;
        return 0;
    }catch(int e){
        return -1;
    };
};

int vLong::operator =(vLong var){
    try{
        data = !var;
        vThis = &var;
        return 0;
    }catch(int e){
        return -1;
    };
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