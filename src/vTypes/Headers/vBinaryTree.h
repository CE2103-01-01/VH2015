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
    vRef<vNodeTree<T>> _left ;
    vRef<vNodeTree<T>> _right ;
public:
    vNodeTree(const vNodeTree<T> &obj);
    vNodeTree( T data);

    T getData();

    void insert(vRef<vNodeTree<T>>);

    void set_right(vRef<vNodeTree<T>>);
    void set_left(vRef<vNodeTree<T>>);

    vRef<vNodeTree<T>> getRight();

    vRef<vNodeTree<T>> getLeft();

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
vNodeTree<T>::vNodeTree( T pData) {
    data = vMalloc(sizeof(pData));
    vPlacement(data, pData);
}

template<class T>
T vNodeTree<T>::getData() {
    return **data;
}

/**
* Se inserta un dato en un nodo buscando los extremos y nodos
* inferiores
*/
template<class T>
void vNodeTree<T>::insert(vRef<vNodeTree<T>> pData) {
    if ((**pData).getData() >= **data) {
        if (!!_right) {
            _right = pData;
        }
        else (**_right).insert(pData);
    }
    else {
        if (!!_left) {
            _left = pData;
        }
        else (**_left).insert(pData);
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
void vNodeTree<T>::set_left(vRef<vNodeTree<T>> pleft) {
    _left = pleft;
}

template<class T>
void vNodeTree<T>::set_right(vRef<vNodeTree<T>>  pright) {
    _right = pright;
}


/**
* Inserta un dato en un arbol binario
*/
template<class T>
void vBinaryTree<T>::insert(T pDato) {
    if (!!_root) {
        _root = vMalloc(sizeof(vNodeTree<T>));
        vNodeTree<T> rootNode = vNodeTree<T>(pDato);
        vPlacement(_root, rootNode);
    }
    else
    {
        vRef<vNodeTree<T>> nodo = vMalloc(sizeof(vNodeTree<T>));
        vPlacement(nodo,vNodeTree<T>(pDato));
        (**_root).insert(nodo);
    }
}

/**
* Busca un dato en un arbol binario y si existe lo devuelve o si no retorna nullptr
*/
template<class T>
vRef<T> vBinaryTree<T>::find(T compare) {
    vRef<T> dato = nullptr;
    vRef<vNodeTree<T>> actualNode = _root;
    while (true) {
        if (!!actualNode) break;
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
template <class T>
vNodeTree<T>::vNodeTree(const vNodeTree<T> &obj) {
    data = obj.data;
    _left = obj._left;
    _right = obj._right;
}
