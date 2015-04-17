//
// Created by roberto on 30/03/15.
//

#include "vTypes/Headers/vLong.h"

vLong::vLong(){
    data = 0;
};

vLong::vLong(long dataParam){
    data = dataParam;
};

long vLong::operator !(){
    return data;
};

vLong vLong::operator +(vLong param){
    data += !param;
    return *this;
};

void vLong::operator +=(vLong pls){
    data += !pls;
};

void vLong::operator =(vLong var){
    data = !var;
};

bool vLong::operator <(vLong other){
    return data < (!other);
};

bool vLong::operator <=(vLong other){
    return data <= (!other);
};

bool vLong::operator >(vLong other){
    return data > (!other);
};

bool vLong::operator >=(vLong other){
    return data >= (!other);
};

bool vLong::operator ==(vLong other){
    return data == (!other);
};

bool vLong::operator !=(vLong other){
    return data != (!other);
};

vLong vLong::operator +(long param){
    data += param;
    return *this;
};

void vLong::operator +=(long pls){
    data += pls;
};

void vLong::operator =(long var){
    data = var;
};

bool vLong::operator <(long other){
    return data < other;
};

bool vLong::operator <=(long other){
    return data <= other;
};

bool vLong::operator >(long other){
    return data > other;
};

bool vLong::operator >=(long other){
    return data >= other;
};

bool vLong::operator ==(long other){
    return data == other;
};

bool vLong::operator !=(long other){
    return data != other;
};

void vLong::operator --(){
    --data;
};

void vLong::operator ++(){
    ++data;
};