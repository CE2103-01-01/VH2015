//
// Created by roberto on 30/03/15.
//

#include "vTypes/Headers/vInt.h"


vInt::vInt(){
    data = 0;
};

vInt::vInt(int dataParam){
    data = dataParam;
};

int vInt::operator !(){
    return data;
};

vInt vInt::operator +(vInt param){
    data += !param;
    return *this;
};

void vInt::operator +=(vInt pls){
    data += !pls;
};

void vInt::operator =(vInt var){
    data = !var;
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

vInt vInt::operator +(int param){
    data += param;
    return *this;
};

void vInt::operator +=(int pls){
    data += pls;
};

void vInt::operator =(int var){
    data = var;
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

void vInt::operator --(){
    --data;
};

void vInt::operator ++(){
    ++data;
};