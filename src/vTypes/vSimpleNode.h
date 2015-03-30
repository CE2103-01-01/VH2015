//
// Created by alex on 30/03/15.
//

#ifndef _VH2015_VSIMPLENODE_H_
#define _VH2015_VSIMPLENODE_H_


#include <stddef.h>
#include <iostream>

template <class T>
class vSimpleNode{

public:
    vSimpleNode *next;
    T data;

    vSimpleNode(){
        data = NULL;
        next = NULL;
    }
    vSimpleNode(T data_){
        vSimpleNode::data = data_;
        vSimpleNode::next = NULL;
    }
    ~vSimpleNode(){

    }


    void delete_all(){
        if (vSimpleNode::next)
            vSimpleNode::next->delete_all();

    }
    void print(){
        std::cout << data << "-> ";
        //Node::~Node();
    }
};
#endif //_VH2015_VSIMPLENODE_H_
