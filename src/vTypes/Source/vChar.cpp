//
// Created by roberto on 30/03/15.
//

#include "vTypes/Headers/vChar.h"

vChar::vChar(char d){
    data = vMalloc(sizeof(d),"char");
    vPlacement(data,d);
};

vChar::~vChar(){
    vObject::~vObject();
};

int vChar::operator +=(char pls){};

int vObject::operator --(){};

char vChar::operator !(){
    try{
        return *static_cast<char*>(*data);
    }catch(int e){
        return -1;
    };
};

vRef vObject::operator &(){};