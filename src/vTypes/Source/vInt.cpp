//
// Created by roberto on 30/03/15.
//

#include "vTypes/Headers/vInt.h"

vInt::vInt(){
    data = vRef<int>(vMalloc(sizeof(int)));
};

vInt::vInt(int d){
    int id = vMalloc(sizeof(int));
    data = vRef<int>(id);
    vPlacement(data, d);
};

vInt::~vInt(){
    vFree(!data);
};

int vInt::operator +=(int pls){
    try{
        (**data) += pls;
        return 0;
    }catch(int e){
        return -1;
    };
};

vRef<int> vInt::operator &(){
    return data;
};

int vInt::operator --(){
    try{
        (**data)--;
        return 0;
    }catch(int e){
        return -1;
    };
};

int vInt::operator ++(){
    try{
        (**data)++;
        return 0;
    }catch(int e){
        return -1;
    };
};

int vInt::operator !(){
    try{
        return (**data);
    }catch(int e){
        return -1;
    };
};

int vInt::operator =(int var){
    try{
        (**data) = var;
        return 0;
    }catch(int e){
        return -1;
    };
};

int vInt::operator =(vInt var){
    try{
        (**data) = (!var);
        return 0;
    }catch(int e){
        return -1;
    };
};

bool vInt::operator <(vInt other){
    return (**data) < (!other);
};

bool vInt::operator <=(vInt other){
    return (**data) <= (!other);
};

bool vInt::operator >(vInt other){
    return (**data) > (!other);
};

bool vInt::operator >=(vInt other){
    return (**data) >= (!other);
};

bool vInt::operator ==(vInt other){
    return (**data) == (!other);
};

bool vInt::operator !=(vInt other){
    return (**data) != (!other);
};

bool vInt::operator <(int other){
    return (**data) < other;
};

bool vInt::operator <=(int other){
    return (**data) <= other;
};

bool vInt::operator >(int other){
    return (**data) > other;
};

bool vInt::operator >=(int other){
    return (**data) >= other;
};

bool vInt::operator ==(int other){
    return (**data) == other;
};

bool vInt::operator !=(int other){
    return (**data) != other;
};