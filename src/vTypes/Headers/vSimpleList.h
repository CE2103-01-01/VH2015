//
// Created by alex on 30/03/15.
//

#ifndef _VH2015_VSIMPLELIST_H_
#define _VH2015_VSIMPLELIST_H_


#include <stddef.h>
#include <iostream>
#include "../libs/vheaplib.h"
#include "vInt.h"

template <class T>
class vSimpleNode{
    vRef next;
    vRef data;
public:
    vSimpleNode();
    vSimpleNode(T);
    ~vSimpleNode();
    vRef operator !();
    vRef operator ->();
    int operator *=(T);
    int operator [](vRef);
    int operator +(vRef);
    int operator +(vSimpleNode);
};

template <class T> vSimpleNode<T>::vSimpleNode(){
    data = vMalloc(sizeof(T),"T");
    next = vRef();
}
template <class T> vSimpleNode<T>::vSimpleNode(T dt){
    data = vMalloc(sizeof(T),"T");
    vPlacement(data,dt);
    next = vRef();
}
template <class T> vSimpleNode<T>::~vSimpleNode(){
    vFree(data);
}

template <class T>vRef vSimpleNode<T>::operator !(){
    return data;
};

template <class T> vRef vSimpleNode<T>::operator ->(){
    return next;
};

template <class T>int vSimpleNode<T>::operator *=(T d){
    try{
        vPlacement(data,d);
        return 0;
    }catch(int e){
        return 1;
    };
};

template <class T> int vSimpleNode<T>::operator [](vRef node){
    try{
        vRef tmp = data;
        data=node;
        node=tmp;
        return 0;
    }catch(int e){
        return 1;
    };
};

template <class T> int vSimpleNode<T>::operator +(vRef vR){
    try{
        next=vR;
        return 0;
    }catch(int e){
        return 1;
    };
};

template <class T> int vSimpleNode<T>::operator +(vSimpleNode node){
    try{
        next=vMalloc(sizeof(vSimpleNode),"vSimpleNode");
        vPlacement(next,node);
        return 0;
    }catch(int e){
        return 1;
    };
};

//SIMPLE LIST


template <class T> class vSimpleList {
private:
    vInt m_num_nodes;
    vRef m_head;

public:
    vSimpleList();
    ~vSimpleList();
    int operator +(T);
    int operator -(T);
    int operator -(vInt);
    int operator [](vInt);
    int operator --();
    vRef operator !();
    void print();
};

#endif //_VH2015_VSIMPLELIST_H_
