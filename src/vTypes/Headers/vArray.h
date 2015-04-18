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
        vArray<T>(int);

        int operator =(vArray);
        bool operator ==(vArray);
        T* operator [](int);
        vInt len();
};

template <class T> vArray<T>::vArray(int len){
    vSize = len;
    chunk = vMalloc((unsigned int) (sizeof(T) * len));
};

template <class T> int vArray<T>::operator =(vArray<T> other){
    if(vSize == other.len()){
        for(vInt i = 0; i<vSize; i+=1){
            *static_cast<T*>(*chunk + !i*sizeof(T)) = *(other[!i]);
        }
    };

    return 0;
};

template <class T> bool vArray<T>::operator ==(vArray<T> other){
    if(vSize == other.len()){
        for(vInt i = 0; i<vSize; i+=1){
            if(!(*static_cast<T*>(*chunk + !i*sizeof(T))==*(other[!i]))){
                return false;
            }
        }
        return true;
    };
    return false;
};

template <class T> T* vArray<T>::operator [](int pos){
    if(vSize > pos){
       return static_cast<T*>(*chunk + pos*sizeof(T));
    }
    return 0;
};

template <class T> vInt vArray<T>::len(){
    return vSize;
};

#endif //VH2015_VARRAY_H