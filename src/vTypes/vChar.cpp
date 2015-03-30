//
// Created by roberto on 30/03/15.
//

#include "vChar.h"

vChar::vChar(char data){
    address= static_cast<vRef*>(malloc(sizeof(vRef)));
    *address = vHeap::getInstance()->vMalloc(sizeof(char),"vChar");
};

vChar::~vChar(){};

int vChar::operator +=(char){};

int vChar::operator --(){};

int vChar::operator !(){};

vRef vChar::operator &(){
    return *address;
};