//
// Created by alex on 30/03/15.
//

#include <stddef.h>
#include <iostream>
#include "vTypes/Headers/vSimpleList.h"

// Constructor por defecto


template <typename T>
vSimpleList<T>::vSimpleList() {
    vSimpleList::m_num_nodes = 0;
    vSimpleList::m_head = NULL;
}

// Insertar al inicio
template <typename T>
void vSimpleList<T>::add_head(T data_) {
    vSimpleNode<T> *new_node = new vSimpleNode<T> (data_);
    vSimpleNode<T> *temp = vSimpleList::m_head;

    if (!vSimpleList::m_head){
        vSimpleList::m_head = new_node;
    } else {
        new_node->next = vSimpleList::m_head;
        vSimpleList::m_head = new_node;

        while (temp) {
            temp = temp->next;
        }
    }
    vSimpleList::m_num_nodes++;
}

// Insertar al final
template <typename T>
void vSimpleList<T>::add_end(T data_) {
    vSimpleNode<T> *new_node = new vSimpleNode<T> (data_);
    vSimpleNode<T> *temp = vSimpleList::m_head;
    if (!vSimpleList::m_head) {
        vSimpleList::m_head = new_node;
    } else {
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
    m_num_nodes++;
}

// Eliminar todos los nodos
template < typename T>
void vSimpleList<T>::del_all() {
    m_head->delete_all();
    m_head = 0;
}

// Eliminar por data del nodo
template<typename T>
void vSimpleList<T>::del_by_data(T data_) {
    vSimpleNode<T> *temp = vSimpleList::m_head;
    vSimpleNode<T> *temp1 = vSimpleList::m_head->next;

    int cont = 0;

    if (vSimpleList::m_head->data == data_) {
        vSimpleList::m_head = temp->next;
    } else {

        while (temp1) {
            if (temp1->data == data_) {
                vSimpleNode<T> *aux_node = temp1;
                temp->next = temp1->next;
                delete aux_node;
                cont++;
                vSimpleList::m_num_nodes--;
            }

            temp = temp->next;
            temp1 = temp1->next;
        }
    }

    if (cont == 0) {
        std::cout << "No existe el dato " << std::endl;
    }
}

// Eliminar por posición del nodo
template<typename T>
void vSimpleList<T>::del_by_position(int pos)
{
    vSimpleNode<T> *temp = vSimpleList::m_head;
    vSimpleNode<T> *temp1 = temp->next;

    if (pos < 1 || pos > m_num_nodes) {
        std::cout << "Fuera de rango " << std::endl;
    } else if (pos == 1) {
        m_head = temp->next;
    } else {
        for (int i = 2; i <= pos; i++) {
            if (i == pos) {
                vSimpleNode<T> *aux_node = temp1;
                temp->next = temp1->next;
                delete aux_node;
                m_num_nodes--;
            }
            temp = temp->next;
            temp1 = temp1->next;
        }
    }
}

// Imprimir la Lista
template<typename T>
void vSimpleList<T>::print() {
    vSimpleNode<T> *temp = vSimpleList::m_head;
    if (!vSimpleList::m_head) {
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
// Buscar el dato de un nodo
template<typename T>
void vSimpleList<T>::Search(T data_) {
    vSimpleNode<T> *temp = m_head;
    int cont = 1;
    int cont2 = 0;

    while (temp) {
        if (temp->data == data_) {
            std::cout << "El dato se encuentra en la posición: " << cont << std::endl;
            cont2++;
        }
        temp = temp->next;
        cont++;
    }

    if (cont2 == 0) {
        std::cout << "No existe el dato " <<std::endl;
    }
    std::cout << std::endl << std::endl;
}

// Destructuor por defecto
template<typename T>
vSimpleList<T>::~vSimpleList() {

}






