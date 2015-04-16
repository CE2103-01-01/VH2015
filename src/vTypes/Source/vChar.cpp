//
// Created by roberto on 30/03/15.
//

#include "vTypes/Headers/vChar.h"

vChar::vChar(){
    data = 0;
    vThis = vRef<vChar>(vMalloc(sizeof(vChar)));
    vPlacement(vThis, *this);
};

vChar::vChar(char dataParam){
    data = dataParam;
    vThis = vRef<vChar>(vMalloc(sizeof(vChar)));
    vPlacement(vThis, *this);
};

vChar::~vChar(){};

vRef<vChar> vChar::operator &(){
    return vThis;
};

int vChar::operator +=(char pls){
    try{
        data += pls;
        return 0;
    }catch(int e){
        return -1;
    };
};

int vChar::operator --(){
    try{
        data -= 1;
        return 0;
    }catch(int e){
        return -1;
    };
};

int vChar::operator ++(){
    try{
        data += 1;
        return 0;
    }catch(int e){
        return -1;
    };
};

char vChar::operator !(){
    try{
        return data;
    }catch(int e){
        return 0;
    };
};

int vChar::operator =(char var){
    try{
        data = var;
        return 0;
    }catch(int e){
        return -1;
    };
};

int vChar::operator =(vChar var){
    try{
        data = !var;
        vThis = &var;
        return 0;
    }catch(int e){
        return -1;
    };
};

bool vChar::operator <(vChar other){
    return data < (!other);
};

bool vChar::operator <=(vChar other){
    return data <= (!other);
};

bool vChar::operator >(vChar other){
    return data > (!other);
};

bool vChar::operator >=(vChar other){
    return data >= (!other);
};

bool vChar::operator ==(vChar other){
    return data == (!other);
};

bool vChar::operator !=(vChar other){
    return data != (!other);
};

bool vChar::operator <(char other){
    return data < other;
};

bool vChar::operator <=(char other){
    return data <= other;
};

bool vChar::operator >(char other){
    return data > other;
};

bool vChar::operator >=(char other){
    return data >= other;
};

bool vChar::operator ==(char other){
    return data == other;
};

bool vChar::operator !=(char other){
    return data != other;
};