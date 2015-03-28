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




template <class T>

class List


{
private:

    int m_num_nodes;
public:
    Node<T> *m_head;
    List(){
        m_num_nodes = 0;
        m_head = NULL;
    }
    ~List();
    int getCounter(){
        return m_num_nodes;
    }
    Node<T> gethead(){
        return *m_head;
    }

    void add_head(T data_){
        Node<T> *new_node = new Node<T> (data_);
        Node<T> *temp = List::m_head;

        if (!List::m_head){
            List::m_head = new_node;
        } else {
            new_node->next = List::m_head;
            List::m_head = new_node;

            while (temp) {
                temp = temp->next;
            }
        }
        m_num_nodes++;
    }
    void add_end(T data_){
        {
            Node<T> *new_node = new Node<T> (data_);
            Node<T> *temp = List::m_head;

            if (!List::m_head) {
                List::m_head = new_node;
            } else {
                while (temp->next != NULL) {
                    temp = temp->next;
                }
                temp->next = new_node;
            }
            m_num_nodes++;
        }

    }


    void del_all();
    void del_by_data(T);
    void del_by_position(int);




    void print()
    {
        Node<T> *temp = List::m_head;
        if (!List::m_head) {
            std::cout << "La Lista está vacía " << std::endl;
        } else {
            while (temp) {
                temp->print();
                if (!temp->next) std::cout << "NULL";
                temp = temp->next;
            }
        }
        std::cout << std::endl << std::endl;
    }

    void Search(T);



};


#endif //_VH2015_LIST_H_
