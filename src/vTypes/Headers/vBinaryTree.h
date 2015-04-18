//
// Created by Pablo Rodriguez Quesada on 3/30/15.
//

#include <vHeap/Headers/vRef.h>
#include <vheaplib.h>

#ifndef _VH2015_VBINARYTREE_H
#define _VH2015_VBINARYTREE_H


template<class T> class vNodeTree {
    T data;
    vRef<vNodeTree<T>> _left;
    vRef<vNodeTree<T>> _right;
public:
    vNodeTree(T);
    T getData();
    void insert(vRef<vNodeTree<T>>);
    void set_right(vRef<vNodeTree<T>>);
    void set_left(vRef<vNodeTree<T>>);
    vRef<vNodeTree<T>> getRight();
    vRef<vNodeTree<T>> getLeft();

};

/**
* Le asigna el padre a un nodo y l dato
*/
template<class T> vNodeTree<T>::vNodeTree(T pData) {
    data = pData;
    _left=0;
    _right=0;
}

template<class T> T vNodeTree<T>::getData() {
    return data;
}

/**
* Se inserta un dato en un nodo buscando los extremos y nodos
* inferiores
*/
template<class T> void vNodeTree<T>::insert(vRef<vNodeTree<T>> pData) {
    if ((*pData)->getData() >= data) {
        if (!_right == 0) {
            _right = pData;
        }
        else (*_right)->insert(pData);
    }
    else {
        if (!_left == 0) {
            _left = pData;
        }
        else (*_left)->insert(pData);
    }
}
template<class T> vRef<vNodeTree<T>> vNodeTree<T>::getRight() {
    return _right;
}
template<class T> vRef<vNodeTree<T>> vNodeTree<T>::getLeft() {
    return _left;
}
template<class T> void vNodeTree<T>::set_left(vRef<vNodeTree<T>> pleft) {
    _left = pleft;
}

template<class T> void vNodeTree<T>::set_right(vRef<vNodeTree<T>>  pright) {
    _right = pright;
}




//vBinaryTree


template<class T> class vBinaryTree {
    vRef<vNodeTree<T>> _root;
public:
    vBinaryTree();
    vBinaryTree(T);
    void insert(T pDato);
    vRef<T> find(T compare);
};


template<class T> vBinaryTree<T>::vBinaryTree(){
    _root = 0;
};

template<class T> vBinaryTree<T>::vBinaryTree(T rootParam){
    vNodeTree<T> root = vNodeTree<T>(rootParam);
    _root = vMalloc(sizeof(root));
    vPlacement(_root, root);
};

/**
* Inserta un dato en un arbol binario
*/
template<class T> void vBinaryTree<T>::insert(T pDato) {
    if(!_root != 0){
        vRef<vNodeTree<T>> newNodo = vMalloc(sizeof(vNodeTree<T>));
        vPlacement(newNodo,vNodeTree<T>(pDato));
        (*_root)->insert(newNodo);
    }else{
        std::cout<<"else"<<std::endl;
        _root = vMalloc(sizeof(vNodeTree<T>));
        std::cout<<"vM"<<std::endl;
        vPlacement(_root, vNodeTree<T>(pDato));
        std::cout<<"vP"<<std::endl;
    }
}

/**
* Busca un dato en un arbol binario y si existe lo devuelve o si no retorna nullptr
*/
template<class T> vRef<T> vBinaryTree<T>::find(T compare) {
    vRef<T> ret = 0;
    vRef<vNodeTree<T>> actualNode = _root;
    while (true) {
        if (!actualNode == 0){
            break;
        }else if (compare == (*actualNode)->getData()) {
            ret = actualNode;
            break;
        }else if (compare > (*actualNode)->getData()) {
            actualNode = (*actualNode)->getRight();
        }
        else if (*compare < (*actualNode)->getData()) {
            actualNode = (*actualNode)->getLeft();
        }

    }
    return ret;
}

#endif //_VH2015_VBINARYTREE_H