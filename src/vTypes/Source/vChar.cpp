//
// Created by roberto on 30/03/15.
//

#include "vTypes/Headers/vChar.h"

vChar::vChar(){
    data = 0;
    ref = vMalloc(sizeof(vChar));
    vChar* ret = this;
    vPlacement(ref,*ret);
};

vChar::~vChar(){
    vFree(!ref);
};

vChar vChar::operator = (char var){
    if(ref==0){
        data = var;
        ref = vMalloc(sizeof(vChar));
        vChar* ret = this;
        vPlacement(ref,*ret);
        return *ret;
    }else{
        data = var;
        vChar* ret = this;
        return *ret;
    };
};

vChar vChar::operator =(vChar var){
    if(!ref){
        data = !var;
        ref = vMalloc(sizeof(vChar));
        vChar* ret = this;
        vPlacement(ref,*ret);
        return *ret;
    }else{
        data = !var;
        vChar* ret = this;
        return *ret;
    };
};

vRef vChar::operator &() {
    return vRef(ref);

};
void vChar::operator +=(char pls){
    data += pls;
};

void vChar::operator --(){
    (data)--;
};

void vChar::operator ++(){
    (data)++;
};

char vChar::operator !(){
    return data;
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