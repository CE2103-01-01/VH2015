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
    vRef<vSimpleNode> next;
    vRef<T> data;
public:
    vSimpleNode();
    vSimpleNode(T);
    ~vSimpleNode();
    vRef<T> operator !();                    //get Data
    vRef<vSimpleNode<T>> operator ++();         //get Next
    int operator *=(T);                      //assign
    int operator [](vRef<vSimpleNode>);      //swap
    int operator +(vRef<vSimpleNode>);       //add
    int operator +(vSimpleNode);             //add
};

template <class T> vSimpleNode<T>::vSimpleNode(){
    data = vRef<T>(vMalloc(sizeof(T)));
    next = vRef<vSimpleNode>();
};

template <class T> vSimpleNode<T>::vSimpleNode(T dt){
    data = vRef<T>(vMalloc(sizeof(T)));
    vPlacement<T>(data,dt);
    next = vRef<vSimpleNode>();
};

template <class T> vSimpleNode<T>::~vSimpleNode(){
    vFree(!data);
};

template <class T> vRef<T> vSimpleNode<T>::operator !(){
    return data;
};

template <class T> vRef<vSimpleNode<T>> vSimpleNode<T>::operator ++(){
    return next;
};

template <class T>int vSimpleNode<T>::operator *=(T d){
    try{
        vPlacement<T>(data,d);
        return 0;
    }catch(int e){
        return 1;
    };
};

template <class T> int vSimpleNode<T>::operator [](vRef<vSimpleNode> node){
    try{
        vRef<T> tmp = data;
        data = !node;
        node *= *(*tmp);
        return 0;
    }catch(int e){
        return 1;
    };
};

template <class T> int vSimpleNode<T>::operator +(vRef<vSimpleNode> vR){
    try{
        next=vR;
        return 0;
    }catch(int e){
        return 1;
    };
};

template <class T> int vSimpleNode<T>::operator +(vSimpleNode node){
    try{
        next = vRef<vSimpleNode>(vMalloc(sizeof(vSimpleNode)));
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
    vRef<vSimpleNode<T>> m_head;
    vRef<vSimpleNode<T>> m_tail;

public:
    vSimpleList();
    ~vSimpleList();
    int operator +(T);              //add
    int operator -(T);              //delete
    T operator [](vInt);            //getPos
    int operator --();              //delete all
    vRef<vSimpleNode<T>> operator *();              //get head
    vRef<vSimpleNode<T>> operator &();              //get tail
};

template <class T> vSimpleList<T>::vSimpleList(){
    std::cout<<"1"<<std::endl;
    m_len = vInt(0);
    std::cout<<"2"<<std::endl;
    m_head = vRef<vSimpleNode<T>>(0);
    std::cout<<"3"<<std::endl;
    m_tail = vRef<vSimpleNode<T>>(0);
    std::cout<<"4"<<std::endl;
};

template <class T> vSimpleList<T>::~vSimpleList(){
    vRef<vSimpleNode<T>> tmp = m_head;
        for(vInt i = 0; i<m_len; ++i){
            vRef<vSimpleNode<T>> tmp2 = tmp;
            tmp = ++(**tmp);
            vFree(!tmp2);
        };
};

template <class T> int vSimpleList<T>::operator +(T data){
    vRef<T> r = vRef<T>(vMalloc(sizeof(T)));
    vPlacement<T>(r,data);
    if(0 != !m_tail){
        (**m_tail) + r;
        m_tail = r;
        return 0;
    }else if(0 != !m_head){
        m_tail = r;
        (**m_head) + m_tail;
        return 0;
    }else{
        m_head = r;
        return 0;
    };
    return 1;
};

template <class T> int vSimpleList<T>::operator -(T data){
    if( **!**m_head == data){
        if(m_len>1){
            m_head = ++(**m_head);
            return 0;
        }else{
            m_head.~vRef();
            m_head=0;
            return 0;
        };
    }else if(m_len>1){
        vRef<vSimpleNode<T>> tmp = m_head;
        vRef<vSimpleNode<T>> tmpB = ++(**tmp);

        for(vInt i = 1; i<m_len; ++i){
            if(!**tmpB == data){
                (**tmp) + (++(**tmpB));
                vFree(tmpB);
                return 0;
            };
            tmp = ++(**tmp);
            tmpB = ++(**tmpB);
        };
        return -1;
    }else{
        return -2;
    };
};

template <class T> T vSimpleList<T>::operator [](vInt pos){
    if(pos<m_len){
        vRef<vSimpleNode<T>> tmp = m_head;
        for(vInt i = 0; i<pos; ++i){
            tmp = ++(**tmp);
        };
        return **!**tmp;
    };
};

template <class T> int vSimpleList<T>::operator --(){
    this->~vSimpleList();
};

template <class T> vRef<vSimpleNode<T>> vSimpleList<T>::operator *(){
    return m_head;
};

template <class T> vRef<vSimpleNode<T>> vSimpleList<T>::operator &(){
    return m_tail;
};

#endif //_VH2015_VSIMPLELIST_H_
