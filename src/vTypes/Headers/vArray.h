//
// Created by roberto on 06/04/15.
//

#ifndef VH2015_VARRAY_H
#define VH2015_VARRAY_H
#include "../libs/vheaplib.h"
#include "vHeap/Headers/vRef.h"
#include "vTypes/Headers/vInt.h"

template <class T> class vArray {
    vInt vSize;
    vRef<T> first;
    vRef<T> last;
    vRef<vArray<T>> ths;
    public:
        vArray(vInt);
        ~vArray();
        int operator =(vArray);
        vRef<vArray<T>> operator &();
        bool operator ==(vArray);
        vRef<T> operator [](vInt);
        vInt len();
};

template <class T> vArray::vArray(vInt len){
    vSize=len;
    first = vRef<T>(vMalloc(sizeof(T)));
    vRef<T> tmp = first;
    for(vInt i = 0; i<vSize; i++){
        tmp = vRef<T>(vMalloc(sizeof(T)));
    }
    last = tmp;
    ths = vRef<vArray<T>>(vMalloc(sizeof(vArray)));
    vArray* toPlace = this;
    vPlacement<vArray<T>>(ths, *toPlace);
};

template <class T> vArray::~vArray(){
    vRef<T> tmp1 = first;
    vRef<T> tmp2 = first;
    for(vInt i = 0; i<vSize; i++){
        ++tmp2;
        vFree(tmp1);
        ++tmp1;
    }
};

template <class T> int vArray::operator =(vArray<T> other){
    if(vSize == other.len()){
        vRef<T> tmp = first;
        for(vInt i = 0; i<vSize; i++){
            tmp = other[i];
            ++tmp;
        }
    };
};

template <class T> vRef<vArray<T>> vArray::operator &(){
    return ths;
};

template <class T> bool vArray::operator ==(vArray<T> other){
    if(vSize == other.len()){
        vRef<T> tmp = first;
        for(vInt i = 0; i<vSize; i++){
            if(!(tmp==other[i])){
                return false;
            }
            ++tmp;
        }
        return true;
    };
    return false;
};

template <class T> vRef<T> vArray::operator [](vInt pos){
    if(vSize > pos){
        vRef<T> tmp = first;
        for(vInt i = 0; i<pos; i++){
            ++tmp;
        }
        return tmp;
    };
};

template <class T> vInt vArray::len(){
    return vSize;
};

#endif //VH2015_VARRAY_H