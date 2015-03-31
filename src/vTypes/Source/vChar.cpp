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

char vChar::operator !(){
    vListIterator<vMallocMDEntry>* iter = (!*(vHeap::getInstance()->getMetaData()))->getIterator();
    while(iter->exists()){
        vMallocMDEntry* entry = iter->next();
        std::cout<<"if("<<!entry<<"=="<<!address<<")"<<std::endl;
        if(!entry==!address){
            std::cout<<"return *static_cast<char*>(&*entry)"<<std::endl;
            return *static_cast<char*>(&*entry);
        };
    };
    std::cout<<"return 0"<<std::endl;
    return 0;
};

vRef vChar::operator &(){
    return address;
};