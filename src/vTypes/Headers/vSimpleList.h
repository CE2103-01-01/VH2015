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
    vRef<vSimpleNode<T>> next;
    vRef<T> data;
public:
    vSimpleNode();
    vSimpleNode(T);
    T operator !();                          //get Data
    vRef<vSimpleNode<T>> operator ++();      //get Next
    void operator *=(T);                     //assign
    void operator +(vRef<vSimpleNode<T>>);   //add
};

template <class T> vSimpleNode<T>::vSimpleNode(){
    next = 0;
};

template <class T> vSimpleNode<T>::vSimpleNode(T param){
    data = vMalloc(sizeof(T));
    vPlacement(data,param);
    next = 0;
};

template <class T> T vSimpleNode<T>::operator !(){
    return **data;
};

template <class T> vRef<vSimpleNode<T>> vSimpleNode<T>::operator ++(){
    return next;
};

template <class T> void vSimpleNode<T>::operator *=(T d){
    if(!data != 0){
        vPlacement(data,d);
    }else{
        data = vMalloc(sizeof(T));
        vPlacement(data,d);
    }
};

template <class T> void vSimpleNode<T>::operator +(vRef<vSimpleNode> vR){
    next=vR;
};


//SIMPLE LIST


template <class T> class vSimpleList {
private:
    int m_len;
    vRef<vSimpleNode<T>> m_head;
public:
    vSimpleList();
    ~vSimpleList();
    void operator +(T);                          //add
    void operator -(T);                          //delete
    void operator --();                          //delete all
    T operator [](int);                         //getPos
    void setPos(int, T);                        //setPos
    int len();
};

template <class T> vSimpleList<T>::vSimpleList(){
    m_len = 0;
    m_head = 0;
};

template <class T> vSimpleList<T>::~vSimpleList(){

};

template <class T> void vSimpleList<T>::operator +(T data){
    if(!m_head != 0){
        vRef<vSimpleNode<T>> tmp = m_head;
        for(int i=1; i < m_len; i++){
            tmp = ++(**tmp);
        }
        (**tmp) + (vMalloc(sizeof(vSimpleNode<T>)));
        vPlacement(++(**tmp),vSimpleNode<T>(data));
        (m_len)++;
    }else{
        m_head = vMalloc(sizeof(vSimpleNode<T>));
        vPlacement(m_head,vSimpleNode<T>(data));
        (m_len)++;
    };
};

template <class T> void vSimpleList<T>::operator -(T data){
    if(!**m_head != data){
        vRef<vSimpleNode<T>> tmp = m_head;
        vRef<vSimpleNode<T>> toDelete = ++(**m_head);
        for(int i=1; i<m_len; i+=1){
            if(!**toDelete == data){
                (**tmp) + ++(**toDelete);
                vFree(toDelete);
                m_len -= 1;
                break;
            }
            tmp = toDelete;
            toDelete = ++(**toDelete);
        }
    }else{
        if(m_len>1){
            vRef<vSimpleNode<T>> tmp = ++(**m_head);
            vFree(m_head);
            m_head = tmp;
        }else{
            vFree(m_head);
        }
        m_len = 0;
    }
};

template <class T> T vSimpleList<T>::operator [](int pos){
    vRef<vSimpleNode<T>> tmp = m_head;
    if(pos < m_len){
        for(int i=0; i<pos; i+=1){
            tmp = ++(**tmp);
        }
    };
    return !**tmp;
};

template <class T> void vSimpleList<T>:: setPos(int pos, T data){
    if(pos < m_len){
        vRef<vSimpleNode<T>> tmp = m_head;
        for(int i=0; i<pos; i+=1){
            tmp = ++(**tmp);
        }
        (**tmp) *= data;
    };
};

template <class T> void vSimpleList<T>::operator --(){
    while(!m_head != 0) {
        vRef<vSimpleNode<T>> tmp = m_head;
        m_head = ++(**m_head);
        vFree(tmp);
    }
    m_len = 0;
};

template <class T> int vSimpleList<T>::len(){
    return m_len;
};

#endif //_VH2015_VSIMPLELIST_H_
