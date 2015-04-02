//
// Created by Pablo Rodriguez Quesada on 3/30/15.
//

#include <AppKit/AppKit.h>

#ifndef _VH2015_VBINARYTREE_H
#define _VH2015_VBINARYTREE_H


template<class T>
class vNodeTree;

template<class T>
class vBinaryTree;

template<class T>
class vNodeTree {
private:
    T data;
    vNodeTree *_left = 0;
    vNodeTree *_right = 0;
    vNodeTree *_parent = 0;
public:
    vNodeTree(vNodeTree *, T data);

    T *getData();

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

    T find(T compare);
};

#endif //_VH2015_VBINARYTREE_H

/**
* Le asigna el padre a un nodo y l dato
*/
template<class T>
vNodeTree::vNodeTree(vNodeTree *parent, T data) {
    _parent = parent;
}

template<class T>
T *vNodeTree::getData() {
    return &data;
}

/**
* Se inserta un dato en un nodo buscando los extremos y nodos
* inferiores
*/
template<class T>
void vNodeTree::insert(T pData) {
    if (pData >= data) {
        if (!_right) _right = new vNodeTree(this, pData);
        else _right->insert(pData);
    }
    else {
        if (!_left) _left = new vNodeTree(this, pData);
        else _left->insert(pData);
    }
}

vNodeTree *vNodeTree::getRight() {
    return _right;
}

vNodeTree *vNodeTree::getLeft() {
    return _left;
}

vNodeTree *vNodeTree::getParent() {
    return _parent;
}

/**
* Inserta un dato en un arbol binario
*/
template<class T>
void vBinaryTree::insert(T pDato) {
    if (!_root) {
        _root = new vNodeTree<T>(nullptr, pDato);
    }
    else _root->insert(pDato);
}

/**
* Busca un dato en un arbol binario y si existe lo devuelve o si no retorna nullptr
*/
template<class T>
T vBinaryTree::find(T compare) {
    T *dato = nullptr;
    vNodeTree<T> *actualNode = _root;
    while (true) {
        if (!actualNode) break;
        else if (*compare == *actualNode->getData()) {
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
    return *dato;
}
