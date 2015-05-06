//
// Created by roberto on 06/04/15.
//

#ifndef VH2015_VARRAY_H
#define VH2015_VARRAY_H
#include "../libs/vheaplib.h"
#include "vHeap/Headers/vRef.h"
#include "vTypes/Headers/vInt.h"

template <class T> class vArray {
    vRef<vInt> vSize;
    vRef<void> chunk;
    public:
        vArray(int,int);
        vArray(int);
        ~vArray();
        int operator =(vArray);
        bool operator ==(vArray);
        T* operator [](int);
        T* operator [](vInt);
        int len();

};

#endif //VH2015_VARRAY_H

template <class T> vArray<T>::vArray(int len){
    vSize = vMalloc(sizeof(int));
    vPlacement(vSize, vInt(len));
    chunk = vMalloc((unsigned int) (sizeof(T) * len));
}

template <class T> vArray<T>::~vArray(){
    //vFree(chunk);
    //vFree(vSize);
}

template <class T> int vArray<T>::operator =(vArray<T> other){
    if(vSize == other.len()){
        for(vInt i = 0; i < **vSize; i+=1){
            *static_cast<T*>(*chunk + (!i)*sizeof(T)) = *(other[(!i)]);
        }
    }
    return 0;
}

template <class T> bool vArray<T>::operator ==(vArray<T> other){
    if(vSize == other.len()){
        for(vInt i = 0; i < **vSize; i+=1) {
            if(!(*static_cast<T*>(*chunk + (!i)*sizeof(T)) == *(other[(!i)]))) return false;
        }
        return true;
    }
    return false;
}

template <class T> T* vArray<T>::operator [](int pos){
    if(**vSize > pos){
       return  static_cast<T*>((*chunk) + pos*sizeof(T));
    }
    return 0;
}

template <class T> T* vArray<T>::operator [](vInt pos){
    if(**vSize > !pos){
        return static_cast<T*>((*chunk) + !pos*sizeof(T));
    }
    return 0;
}

template <class T> int vArray<T>::len(){
    return !**vSize;
}

template <class T>
vArray<T>::vArray(int i, int j) {
    vSize = i;
    chunk = vMalloc((unsigned int) (sizeof(vArray<T>) * i));
    for (int k = 0; k < i; ++k) {
        vArray<T>* ptr = static_cast<vArray<T>*>((*chunk) + k*sizeof(T));
        new(ptr) vArray<T>(j);
    }
}
