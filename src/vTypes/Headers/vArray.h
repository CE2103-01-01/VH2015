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
    vRef<void> chunk;
    public:
        vArray<T>(vInt);
        ~vArray<T>();
        int operator =(vArray);
        bool operator ==(vArray);
        T* operator [](vInt);
        vInt len();
};

template <class T> vArray<T>::vArray(vInt len){
    vSize=len;
    chunk = vRef<void>(vMalloc(sizeof(T) * !len));
};

template <class T> vArray<T>::~vArray(){
    vFree(chunk);
};

template <class T> int vArray<T>::operator =(vArray<T> other){
    if(vSize == other.len()){
        for(int i = 0; i<!vSize; i++){
            *static_cast<T*>(*chunk + i*sizeof(T)) = *other[i];
        }
    };
};

template <class T> bool vArray<T>::operator ==(vArray<T> other){
    if(vSize == other.len()){
        for(int i = 0; i<!vSize; i++){
            if(!(*static_cast<T*>(*chunk + i*sizeof(T))==*other[i])){
                return false;
            }
        }
        return true;
    };
    return false;
};

template <class T> T* vArray<T>::operator [](vInt pos){
    if(vSize > pos){
        for(int i = 0; i<!pos; i++){
            return static_cast<T*>(*chunk + i*sizeof(T));
        }
    };
};

template <class T> vInt vArray<T>::len(){
    return vSize;
};

#endif //VH2015_VARRAY_H