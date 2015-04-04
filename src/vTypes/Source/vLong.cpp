//
// Created by roberto on 30/03/15.
//

#include "vTypes/Headers/vLong.h"

vLong::vLong(){
    data = vRef<long>(vMalloc(sizeof(long)));
};

vLong::vLong(long d){
    data = vRef<long>(vMalloc(sizeof(long)));
    vPlacement<long>(data, d);
};

vLong::~vLong(){
    vFree(!data);
};

vRef vLong::operator &(){
    return *data;
};

int vLong::operator +=(long pls){
    try{
        *data+pls;
        return 0;
    }catch(int e){
        return -1;
    };
};

int vLong::operator --(){
    try{
        (*data)--;
        return 0;
    }catch(int e){
        return -1;
    };
};

int vLong::operator ++(){
    try{
        (*data)++;
        return 0;
    }catch(int e){
        return -1;
    };
};

long vLong::operator !(){
    try{
        return *data;
    }catch(int e){
        return -1;
    };
};

int vLong::operator =(long var){
    try{
        *data = var;
        return 0;
    }catch(int e){
        return -1;
    };
};

int vLong::operator =(vLong var){
    try{
        *data = !var;
        return 0;
    }catch(int e){
        return -1;
    };
};

bool vLong::operator <(vLong other){
    return *data < !other;
};

bool vLong::operator <=(vLong other){
    return *data <= !other;
};

bool vLong::operator >(vLong other){
    return *data > !other;
};

bool vLong::operator >=(vLong other){
    return *data >= !other;
};

bool vLong::operator ==(vLong other){
    return *data == !other;
};

bool vLong::operator !=(vLong other){
    return *data != !other;
};

bool vLong::operator <(long other){
    return *data < other;
};

bool vLong::operator <=(long other){
    return *data <= other;
};

bool vLong::operator >(long other){
    return *data > other;
};

bool vLong::operator >=(long other){
    return *data >= other;
};

bool vLong::operator ==(long other){
    return *data == other;
};

bool vLong::operator !=(long other){
    return *data != other;
};