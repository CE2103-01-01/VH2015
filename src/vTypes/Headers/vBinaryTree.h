//
// Created by Pablo Rodriguez Quesada on 3/30/15.
//

#include <vHeap/Headers/vRef.h>
#include <vheaplib.h>

#ifndef _VH2015_VBINARYTREE_H
#define _VH2015_VBINARYTREE_H


template<class T>
class vNodeTree;

template<class T>
class vBinaryTree;

template<class T>
class vNodeTree {
private:
    vRef<T> data;
    vNodeTree *_left = 0;
    vNodeTree *_right = 0;
    vNodeTree *_parent = 0;
public:
    vNodeTree(vNodeTree *, T data);

    vRef<T> getData();

    void insert(T);

    vNodeTree *getRight();

    vNodeTree *getLeft();

    vNodeTree *getParent();
};

template<class T>
class vBinaryTree {
private:
    vNodeTree<T> *_root;
public:
    void insert(T pDato);

    vRef<T> find(T compare);
};

#endif //_VH2015_VBINARYTREE_H

/**
* Le asigna el padre a un nodo y l dato
*/
template<class T>
vNodeTree<T>::vNodeTree(vNodeTree *parent, T pData) {
    _parent = parent;
    data = vMalloc(sizeof(pData));
    vPlacement(data, pData);
}

template<class T>
vRef<T> vNodeTree<T>::getData() {
    return data;
}

/**
* Se inserta un dato en un nodo buscando los extremos y nodos
* inferiores
*/
template<class T>
void vNodeTree<T>::insert(T pData) {
    if (pData >= **data) {
        if (!_right) _right = new vNodeTree(this, pData);
        else _right->insert(pData);
    }
    else {
        if (!_left) _left = new vNodeTree(this, pData);
        else _left->insert(pData);
    }
}
template<class T>
vNodeTree<T> *vNodeTree<T>::getRight() {
    return _right;
}
template<class T>
vNodeTree<T> *vNodeTree<T>::getLeft() {
    return _left;
}
template<class T>
vNodeTree<T> *vNodeTree<T>::getParent() {
    return _parent;
}

/**
* Inserta un dato en un arbol binario
*/
template<class T>
void vBinaryTree<T>::insert(T pDato) {
    if (!_root) {
        _root = new vNodeTree<T>(nullptr, pDato);
    }
    else _root->insert(pDato);
}

/**
* Busca un dato en un arbol binario y si existe lo devuelve o si no retorna nullptr
*/
template<class T>
vRef<T> vBinaryTree<T>::find(T compare) {
    vRef<T> dato = nullptr;
    vNodeTree<T> *actualNode = _root;
    while (true) {
        if (!actualNode) break;
        else if (compare == *actualNode->getData()) {
            dato = actualNode->getData();
            break;
        }
        else if (*compare > *actualNode->getData()) {
            actualNode = actualNode->getRight();
        }
        else if (*compare < *actualNode->getData()) {
            actualNode = actualNode->getLeft();
        }

    }
    return dato;
}
