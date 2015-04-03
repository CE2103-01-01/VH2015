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
    vRef operator ++();         //get Next
    int operator *=(T);         //assign
    int operator [](vRef);      //swap
    int operator +(vRef);       //add
    int operator +(vSimpleNode);//add
};

template <class T> vSimpleNode<T>::vSimpleNode(){
    data = vMalloc(sizeof(T),"T");
    next = vRef();
};

template <class T> vSimpleNode<T>::vSimpleNode(T dt){
    data = vMalloc(sizeof(T),"T");
    vPlacement(data,dt);
    next = vRef();
};

template <class T> vSimpleNode<T>::~vSimpleNode(){
    vFree(data);
};

template <class T>vRef vSimpleNode<T>::operator !(){
    return data;
};

template <class T> vRef vSimpleNode<T>::operator ++(){
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
    T operator [](vInt);            //getPos
    int operator --();              //delete all
    vRef operator *();              //get head
    vRef operator &();              //get tail
};

template <class T> vSimpleList<T>::vSimpleList(){
    m_len = vInt(0);
    m_head = vRef();
    m_tail = vRef();
};

template <class T> vSimpleList<T>::~vSimpleList(){
	 vRef tmp = m_head;
        for(vInt i = 0; i<m_len; ++i){
	    vRef tmp2 = tmp;
            tmp = (*static_cast<vSimpleNode<T>*>(*tmp))++;
	    vFree(tmp2);
        };
};

template <class T> int vSimpleList<T>::operator +(T data){
    vRef r = vMalloc(sizeof(T),data);
    vPlacement(r,data);
    if(0 != !m_tail){
        *static_cast<vSimpleNode<T>*>(*m_tail) + r;
        m_tail=r;
        return 0;
    }else if(0 != !m_head){
        m_tail = r;
        *static_cast<vSimpleNode<T>*>(*m_head) + m_tail;
        return 0;
    }else{
        m_head = r;
        return 0;
    };
    return 1;
};

template <class T> int vSimpleList<T>::operator -(T data){
    if(*static_cast<T*>(*!*static_cast<vSimpleNode<T>*>(*m_head)) == data){
        if(m_len>1){
            m_head = (*static_cast<vSimpleNode<T>*>(*m_head))++;
            return 0;
        }else{
            m_head.~vRef();
            m_head=0;
            return 0;
        };
    }else if(m_len>1){
        vRef tmp = m_head;
        vRef tmpB = (*static_cast<vSimpleNode<T>*>(*tmp))++;
        for(vInt i = 1; i<m_len; ++i){
            if(*static_cast<T*>(*!*static_cast<vSimpleNode<T>*>(*tmpB)) == data){
                (*static_cast<vSimpleNode<T>*>(*tmp)) + (*static_cast<vSimpleNode<T>*>(*tmpB))++;
                vFree(tmpB);
                return 0;
            };
            tmp = (*static_cast<vSimpleNode<T>*>(*tmp))++;
            tmpB = (*static_cast<vSimpleNode<T>*>(*tmpB))++;
        };
        return -1;
    }else{
        return -2;
    };
};

template <class T> T vSimpleList<T>::operator [](vInt pos){
    if(pos<m_len){
        vRef tmp = m_head;
        for(vInt i = 0; i<pos; ++i){
            tmp = (*static_cast<vSimpleNode<T>*>(*tmp))++;
        };
        return *static_cast<T*>(*(!(*static_cast<vSimpleNode<T>*>(*tmp))));
    };
};

template <class T> int vSimpleList<T>::operator --(){
    this->~vSimpleList();
};

template <class T> vRef vSimpleList<T>::operator *(){
    return m_head;
};

template <class T> vRef vSimpleList<T>::operator &(){
    return m_tail;
};

#endif //_VH2015_VSIMPLELIST_H_
