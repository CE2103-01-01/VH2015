//
// Created by roberto on 30/03/15.
//

#include "vChar.h"

vChar::vChar(char data){
    std::cout<<"address = vHeap::getInstance()->vMalloc(sizeof(vChar),\"vChar\");"<<std::endl;
    address = vHeap::getInstance()->vMalloc(sizeof(vChar),"vChar");
    std::cout<<"vHeap::getInstance()->vPlacement(address,this);"<<std::endl;
    vHeap::getInstance()->vPlacement(address,this);
};

vChar::~vChar(){};

int vChar::operator +=(char){};

int vChar::operator --(){};

int vChar::operator !(){};

vRef vChar::operator &(){
    return address;
};