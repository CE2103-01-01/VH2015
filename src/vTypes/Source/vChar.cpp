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
vRef vChar::operator &(){
    return data;
};

int vChar::operator +=(char pls){
    try{
        *static_cast<char*>(*data)+pls;
        return 0;
    }catch(int e){
        return -1;
    };
};

int vChar::operator --(){
    try{
        *static_cast<char*>(*data)-1;
        return 0;
    }catch(int e){
        return -1;
    };
};

char vChar::operator !(){
    try{
        return *static_cast<char*>(*data);
    }catch(int e){
        return -1;
    };
};

int vChar::operator =(char var){
    try{
        *static_cast<char*>(*data)=var;
        return 0;
    }catch(int e){
        return -1;
    };
};