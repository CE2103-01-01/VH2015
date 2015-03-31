//
// Created by roberto on 30/03/15.
//

#include "vTypes/Headers/vChar.h"

vChar::vChar(char data){
    address = vHeap::getInstance()->vMalloc(sizeof(vChar),"vChar");
    vHeap::getInstance()->vPlacement(address,this);
};

vChar::~vChar(){};

int vChar::operator +=(char){};

int vChar::operator --(){};

int vChar::operator !(){};

vRef vChar::operator &(){
    return address;
};