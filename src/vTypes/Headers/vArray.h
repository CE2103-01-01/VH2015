//
// Created by roberto on 06/04/15.
//

#ifndef VH2015_VARRAY_H
#define VH2015_VARRAY_H
#include "../libs/vheaplib.h"
#include "vHeap/Headers/vRef.h"
#include "vTypes/Headers/vInt.h"

template <class T> class vArray {
    int vSize;
    vRef<void> chunk;
    public:
        vArray<T>(int);
        ~vArray<T>();
        int operator =(vArray);
        bool operator ==(vArray);
        T* operator [](int);
        int len();
};

template <class T> vArray<T>::vArray(int len){
    vSize=len;
    chunk = vRef<void>(vMalloc(sizeof(T) * len));
};

template <class T> vArray<T>::~vArray(){
    vFree(chunk);
};

template <class T> int vArray<T>::operator =(vArray<T> other){
    if(vSize == other.len()){
        for(int i = 0; i<vSize; i++){
            *static_cast<T*>(*chunk + i*sizeof(T)) = *other[i];
        }
    };
};

template <class T> bool vArray<T>::operator ==(vArray<T> other){
    if(vSize == other.len()){
        for(int i = 0; i<vSize; i++){
            if(!(*static_cast<T*>(*chunk + i*sizeof(T))==*other[i])){
                return false;
            }
        }
        return true;
    };
    return false;
};

template <class T> T* vArray<T>::operator [](int pos){
    std::cout<<"vSize = "<<vSize<<std::endl;
    std::cout<<"pos = "<<pos<<std::endl;
    if(vSize > pos){
        std::cout<<"0"<<std::endl;
        void* ret = *chunk;
        std::cout<<"1"<<std::endl;
        ret= ret + pos*sizeof(T);
        std::cout<<"2"<<std::endl;
       return static_cast<T*>(ret);
        std::cout<<"3"<<std::endl;
    }
    std::cout<<"return 0"<<std::endl;
    return 0;
};

template <class T> int vArray<T>::len(){
    return vSize;
};

#endif //VH2015_VARRAY_H