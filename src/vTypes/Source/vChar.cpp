//
// Created by roberto on 30/03/15.
//

#include "vTypes/Headers/vChar.h"

vChar::vChar(){
    data = vRef<char>(vMalloc(sizeof(char)));
};

vChar::vChar(char d){
    int id = vMalloc(sizeof(char));
    data = vRef<char>(id);
    vPlacement<char>(data, d);
};

vChar::~vChar(){
    vFree(!data);
};
vRef<char> vChar::operator &(){
    return data;
};

int vChar::operator +=(char pls){
    try{
        (**data) += pls;
        return 0;
    }catch(int e){
        return -1;
    };
};

int vChar::operator --(){
    try{
        ((**data))--;
        return 0;
    }catch(int e){
        return -1;
    };
};

int vChar::operator ++(){
    try{
        ((**data))++;
        return 0;
    }catch(int e){
        return -1;
    };
};

char vChar::operator !(){
    try{
        return (**data);
    }catch(int e){
        return -1;
    };
};

int vChar::operator =(char var){
    try{
        (**data) = var;
        return 0;
    }catch(int e){
        return -1;
    };
};

int vChar::operator =(vChar var){
    try{
        (**data) = !var;
        return 0;
    }catch(int e){
        return -1;
    };
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