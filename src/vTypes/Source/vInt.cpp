//
// Created by roberto on 30/03/15.
//

#include "vTypes/Headers/vInt.h"

vInt::vInt(){
    data = vMalloc(sizeof(int),"int");
};

vInt::vInt(int d){
    data = vMalloc(sizeof(d),"int");
    vPlacement(data, d);
};

vInt::~vInt(){
    vFree(data);
};

int vInt::operator +=(int pls){
    try{
        *static_cast<int*>(*data)+pls;
        return 0;
    }catch(int e){
        return -1;
    };
};

vRef vInt::operator &(){
    return data;
};

int vInt::operator --(){
    try{
        (*static_cast<int*>(*data))--;
        return 0;
    }catch(int e){
        return -1;
    };
};

int vInt::operator ++(){
    try{
        (*static_cast<int*>(*data))++;
        return 0;
    }catch(int e){
        return -1;
    };
};

int vInt::operator !(){
    try{
        return *static_cast<int*>(*data);
    }catch(int e){
        return -1;
    };
};

int vInt::operator =(int var){
    try{
        *static_cast<int*>(*data) = var;
        return 0;
    }catch(int e){
        return -1;
    };
};

int vInt::operator =(vInt var){
    try{
        *static_cast<int*>(*data) = !var;
        return 0;
    }catch(int e){
        return -1;
    };
};

bool vInt::operator <(vInt other){
    return *static_cast<int*>(*data) < !other;
};

bool vInt::operator <=(vInt other){
    return *static_cast<int*>(*data) <= !other;
};

bool vInt::operator >(vInt other){
    return *static_cast<int*>(*data) > !other;
};

bool vInt::operator >=(vInt other){
    return *static_cast<int*>(*data) >= !other;
};

bool vInt::operator ==(vInt other){
    return *static_cast<int*>(*data) == !other;
};

bool vInt::operator !=(vInt other){
    return *static_cast<int*>(*data) != !other;
};

bool vInt::operator <(int other){
    return *static_cast<int*>(*data) < other;
};

bool vInt::operator <=(int other){
    return *static_cast<int*>(*data) <= other;
};

bool vInt::operator >(int other){
    return *static_cast<int*>(*data) > other;
};

bool vInt::operator >=(int other){
    return *static_cast<int*>(*data) >= other;
};

bool vInt::operator ==(int other){
    return *static_cast<int*>(*data) == other;
};

bool vInt::operator !=(int other){
    return *static_cast<int*>(*data) != other;
};