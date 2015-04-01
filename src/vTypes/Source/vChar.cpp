//
// Created by roberto on 30/03/15.
//

#include "vTypes/Headers/vChar.h"

vChar::vChar(char d){
    data = vHeap::getInstance()->vMalloc(sizeof(d),"char");
    vHeap::getInstance()->vPlacement(data,d);
};

vChar::~vChar(){};

int vChar::operator +=(char pls){};

int vChar::operator --(){};

char vChar::operator !(){
    try{
        return *static_cast<char*>(vHeap::getInstance()->de_vReference(data));
    }catch(int e){
        return -1;
    };
};

vRef vChar::operator &(){};