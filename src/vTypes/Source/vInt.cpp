//
// Created by roberto on 30/03/15.
//

#include "vTypes/Headers/vInt.h"

vInt::vInt(){
    data = 0;
    ref = vMalloc(sizeof(vInt));
    vInt* ret = this;
    vPlacement(ref,*ret);
};

vInt::~vInt(){
    vFree(!ref);
};

vInt vInt::operator = (int var){
    if(!ref){
        data = var;
        ref = vMalloc(sizeof(vInt));
        vInt* ret = this;
        vPlacement(ref,*ret);
        return *ret;
    }else{
        data = var;
        vInt* ret = this;
        return *ret;
    };
};

vInt vInt::operator =(vInt var){
    if(!ref){
        data = !var;
        ref = vMalloc(sizeof(vInt));
        vInt* ret = this;
        vPlacement(ref,*ret);
        return *ret;
    }else{
        data = !var;
        vInt* ret = this;
        return *ret;
    };
};

vRef vInt::operator &() {
    return vRef(ref);

}
void vInt::operator +=(int pls){
    data += pls;
};

void vInt::operator --(){
    (data)--;
};

void vInt::operator ++(){
    (data)++;
};

int vInt::operator !(){
    return data;
};

bool vInt::operator <(vInt other){
    return data < (!other);
};

bool vInt::operator <=(vInt other){
    return data <= (!other);
};

bool vInt::operator >(vInt other){
    return data > (!other);
};

bool vInt::operator >=(vInt other){
    return data >= (!other);
};

bool vInt::operator ==(vInt other){
    return data == (!other);
};

bool vInt::operator !=(vInt other){
    return data != (!other);
};

bool vInt::operator <(int other){
    return data < other;
};

bool vInt::operator <=(int other){
    return data <= other;
};

bool vInt::operator >(int other){
    return data > other;
};

bool vInt::operator >=(int other){
    return data >= other;
};

bool vInt::operator ==(int other){
    return data == other;
};

bool vInt::operator !=(int other){
    return data != other;
};