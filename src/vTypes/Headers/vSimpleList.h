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
    vRef operator !();          //get Data
    vRef operator ->();         //get Next
    int operator *=(T);         //assign
    int operator [](vRef);      //swap
    int operator +(vRef);       //add
    int operator +(vSimpleNode);//add
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
    vInt m_len;
    vRef m_head;
    vRef m_tail;

public:
    vSimpleList();
    ~vSimpleList();
    int operator +(T);              //add
    int operator -(T);              //delete
    int operator [](vInt);          //getPos
    int operator --();              //delete all
    vRef operator ++(vSimpleList);  //get head
    vRef operator ++();             //get tail
    void print();
};

template <class T> vSimpleList::vSimpleList(){
    m_len = vInt(0);
    m_head = vRef();
    m_tail = vRef();
};

template <class T> vSimpleList::~vSimpleList(){};

template <class T> vSimpleList::int operator +(T data){
    vRef r = vMalloc(sizeof(T),data);
    vPlacement(r,data);
    if(0 != !m_tail){
        *static_cast<vSimpleNode*>(*m_tail) + r;
        m_tail=r;
        return 0;
    }else if(0 != !m_head){
        m_tail = r;
        *static_cast<vSimpleNode*>(*m_head) + m_tail;
        return 0;
    }else{
        m_head = r;
        return 0;
    };
    return 1;
};

template <class T> vSimpleList::int operator -(T data){};

template <class T> vSimpleList::int operator [](vInt pos){};

template <class T> vSimpleList::int operator --(){};

template <class T> vSimpleList::vRef operator ++(vSimpleList){};

template <class T> vSimpleList::vRef operator ++(){};

template <class T> vSimpleList::void print(){};

#endif //_VH2015_VSIMPLELIST_H_
