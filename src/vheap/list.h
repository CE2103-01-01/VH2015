//
// Created by alex on 19/03/15.
//

#ifndef _VH2015_LIST_H_
#define _VH2015_LIST_H_
#include <fstream>
#include <iostream>
#include <string>
#include <stdlib.h>

#include "node.h"
#include "node.cpp"

using namespace std;
template <class T>
class list {

public:
    list();
    ~list();

    void add_head(T);
    void add_end(T);
    void del_all();
    void del_by_data(T);
    void del_by_position(int);
    void search(T);


private:
    node<T> *m_head;
    int m_num_nodes;
};


#endif //_VH2015_LIST_H_
