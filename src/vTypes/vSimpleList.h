//
// Created by alex on 30/03/15.
//

#ifndef _VH2015_VSIMPLELIST_H_
#define _VH2015_VSIMPLELIST_H_
#include "vSimpleNode.h"
template <class T>
class vSimpleList {
private:
    int m_num_nodes;
    vSimpleNode<T> *m_head;

public:
    vSimpleList();
    ~vSimpleList();

    void add_head(T);
    void add_end(T);


    void del_all();
    void del_by_data(T);
    void del_by_position(int);



    void print();

    void Search(T);

};




#endif //_VH2015_VSIMPLELIST_H_
