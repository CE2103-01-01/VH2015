//
// Created by alex on 19/03/15.
//

#ifndef _VH2015_NODE_H_
#define _VH2015_NODE_H_

#include <iostream>
using namespace std;
template <class T>
class Node {
public:
    Node();
    Node(T);
    ~Node();

    Node *nextNode;
    T data;
    void delete_all();


};


#endif //_VH2015_NODE_H_
