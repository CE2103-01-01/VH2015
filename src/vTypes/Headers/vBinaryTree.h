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
    vRef<vNodeTree> vThis;
    vRef<vNodeTree> _left = 0;
    vRef<vNodeTree> _right = 0;
    vRef<vNodeTree> _parent = 0;
public:
    vNodeTree(vRef<vNodeTree> parent, T data);

    vRef<T> getData();

    void insert(T, vRef<vNodeTree>);

    vRef<vNodeTree<T>> getRight();

    vRef<vNodeTree<T>> getLeft();

    vRef<vNodeTree<T>> getParent();
};

template<class T>
class vBinaryTree {
private:
    vRef<vNodeTree<T>> _root;
public:
    void insert(T pDato);

    vRef<T> find(T compare);
};

#endif //_VH2015_VBINARYTREE_H

/**
* Le asigna el padre a un nodo y l dato
*/
template<class T>
vNodeTree<T>::vNodeTree(vRef<vNodeTree> parent, T pData) {
    vThis = parent;
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
void vNodeTree<T>::insert(T pData, vRef<vNodeTree> me) {
    if (pData >= **data) {
        if (!!_right) {
            _right = vMalloc(sizeof(vNodeTree));
            vPlacement(_right,vNodeTree(me,pData));
            //_right = new vNodeTree(this, pData);
        }
        else (**_right).insert(pData,_right);
    }
    else {
        if (!!_left) {
            _left = vMalloc(sizeof(vNodeTree));
            vPlacement(_left,vNodeTree(me, pData));
        }
        else (**_left).insert(pData,_left);
    }
}
template<class T>
vRef<vNodeTree<T>> vNodeTree<T>::getRight() {
    return _right;
}
template<class T>
vRef<vNodeTree<T>> vNodeTree<T>::getLeft() {
    return _left;
}
template<class T>
vRef<vNodeTree<T>> vNodeTree<T>::getParent() {
    return _parent;
}

/**
* Inserta un dato en un arbol binario
*/
template<class T>
void vBinaryTree<T>::insert(T pDato) {
    if (!!_root) {
        _root = vMalloc(sizeof(vNodeTree<T>));
        vPlacement(_root, vNodeTree(vRef<vNodeTree>(0),pDato));
        //_root = new vNodeTree<T>(nullptr, pDato);
    }
    else (**_root).insert(pDato,_root);
}

/**
* Busca un dato en un arbol binario y si existe lo devuelve o si no retorna nullptr
*/
template<class T>
vRef<T> vBinaryTree<T>::find(T compare) {
    vRef<T> dato = nullptr;
    vRef<vNodeTree<T>> actualNode = _root;
    while (true) {
        if (!actualNode) break;
        else if (compare == (**actualNode).getData()) {
            dato = (**actualNode).getData();
            break;
        }
        else if (*compare > (**actualNode).getData()) {
            actualNode = (**actualNode).getRight();
        }
        else if (*compare < (**actualNode).getData()) {
            actualNode = (**actualNode).getLeft();
        }

    }
    return dato;
}
