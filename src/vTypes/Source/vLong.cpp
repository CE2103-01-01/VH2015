//
// Created by roberto on 30/03/15.
//

#include "vTypes/Headers/vLong.h"

vLong::vLong(long d){
    data = vMalloc(sizeof(d),"long");
    vPlacement(&data, d);
};

vLong::~vLong(){
    vFree(data);
};

vRef vLong::operator &(){
    return data;
};

int vLong::operator +=(long pls){
    try{
        *static_cast<long*>(*data)+pls;
        return 0;
    }catch(int e){
        return -1;
    };
};

int vLong::operator --(){
    try{
        (*static_cast<long*>(*data))--;
        return 0;
    }catch(int e){
        return -1;
    };
};

int vLong::operator ++(){
    try{
        (*static_cast<long*>(*data))++;
        return 0;
    }catch(int e){
        return -1;
    };
};

long vLong::operator !(){
    try{
        return *static_cast<long*>(*data);
    }catch(int e){
        return -1;
    };
};

int vLong::operator =(long var){
    try{
        *static_cast<long*>(*data) = var;
        return 0;
    }catch(int e){
        return -1;
    };
};

int vLong::operator =(vLong var){
    try{
        *static_cast<long*>(*data) = !var;
        return 0;
    }catch(int e){
        return -1;
    };
};

bool vLong::operator <(vLong other){
    return *static_cast<long*>(*data) < !other;
};

bool vLong::operator <=(vLong other){
    return *static_cast<long*>(*data) <= !other;
};

bool vLong::operator >(vLong other){
    return *static_cast<long*>(*data) > !other;
};

bool vLong::operator >=(vLong other){
    return *static_cast<long*>(*data) >= !other;
};

bool vLong::operator ==(vLong other){
    return *static_cast<long*>(*data) == !other;
};

bool vLong::operator !=(vLong other){
    return *static_cast<long*>(*data) != !other;
};

bool vLong::operator <(long other){
    return *static_cast<long*>(*data) < other;
};

bool vLong::operator <=(long other){
    return *static_cast<long*>(*data) <= other;
};

bool vLong::operator >(long other){
    return *static_cast<long*>(*data) > other;
};

bool vLong::operator >=(long other){
    return *static_cast<long*>(*data) >= other;
};

bool vLong::operator ==(long other){
    return *static_cast<long*>(*data) == other;
};

bool vLong::operator !=(long other){
    return *static_cast<long*>(*data) != other;
};