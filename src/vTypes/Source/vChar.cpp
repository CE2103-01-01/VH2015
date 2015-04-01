//
// Created by roberto on 30/03/15.
//

#include "vTypes/Headers/vChar.h"

vChar::vChar(char d){
    data = vMalloc(sizeof(d),"char");
    vPlacement(data,d);
};

vChar::~vChar(){
    vFree(data);
};

int vChar::operator +=(char pls){};

int vChar::operator --(){};

char vChar::operator !(){
    try{
        return *static_cast<char*>(*data);
    }catch(int e){
        return -1;
    };
};

vRef vChar::operator &(){};