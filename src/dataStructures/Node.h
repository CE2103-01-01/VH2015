//
// Created by alex on 19/03/15.
//

#ifndef _VH2015_NODE_H_
#define _VH2015_NODE_H_


#include <iostream>

using namespace std;

template <class T>

class Node
{
public:
    Node *next;
    T data;

    Node(){
        data = NULL;
        next = NULL;
    }
    Node(T data_){
        Node::data = data_;
        Node::next = NULL;
    }
    ~Node(){

    }


    void delete_all(){
        if (Node::next)
            Node::next->delete_all();

    }
    void print(){
        cout << data << "-> ";
        //Node::~Node();
    }
};


#endif //_VH2015_NODE_H_
