//
// Created by roberto on 30/03/15.
//

#include "vTypes/Headers/vInt.h"

vInt::vInt(){
    data = 0;
    vThis = vRef<vInt>(vMalloc(sizeof(vInt)));
    vPlacement(vThis, *this);
};

vInt::vInt(int dataParam){
    data = dataParam;
    vThis = vRef<vInt>(vMalloc(sizeof(vInt)));
    vPlacement(vThis, *this);
};

vInt::~vInt(){};

vRef<vInt> vInt::operator &(){
    return vThis;
};

int vInt::operator +=(int pls){
    try{
        data += pls;
        return 0;
    }catch(int e){
        return -1;
    };
};

int vInt::operator --(){
    try{
        data -= 1;
        return 0;
    }catch(int e){
        return -1;
    };
};

int vInt::operator ++(){
    try{
        data += 1;
        return 0;
    }catch(int e){
        return -1;
    };
};

int vInt::operator !(){
    try{
        return data;
    }catch(int e){
        return 0;
    };
};

int vInt::operator =(int var){
    try{
        data = var;
        return 0;
    }catch(int e){
        return -1;
    };
};

int vInt::operator =(vInt var){
    try{
        data = !var;
        vThis = &var;
        return 0;
    }catch(int e){
        return -1;
    };
};

bool vInt::operator <(vInt other){
    return data < (!other);
};

bool vInt::operator <=(vInt other){
    return data <= (!other);
};

bool vInt::operator >(vInt other){
    return data > (!other);
};

bool vInt::operator >=(vInt other){
    return data >= (!other);
};

bool vInt::operator ==(vInt other){
    return data == (!other);
};

bool vInt::operator !=(vInt other){
    return data != (!other);
};

bool vInt::operator <(int other){
    return data < other;
};

bool vInt::operator <=(int other){
    return data <= other;
};

bool vInt::operator >(int other){
    return data > other;
};

bool vInt::operator >=(int other){
    return data >= other;
};

bool vInt::operator ==(int other){
    return data == other;
};

bool vInt::operator !=(int other){
    return data != other;
};