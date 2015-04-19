//
// Created by roberto on 19/04/15.
//

#ifndef VH2015_BTREE_H
#define VH2015_BTREE_H

#include <cstdlib>

/*************************************************************************************************
*****************************************CLASE Container******************************************
*************************************************************************************************/


/** @brief esta clase contendra un dato tipo T y estara contenida en una hoja
 */
template <class T> class Container{
    T* data;
    Container<T>* next;
    Container<T>* prev;
    public:
        Container();
        ~Container();
        void setData(T*);
        void swap(Container<T>*);
        void setNext(Container<T>*);
        void setPrev(Container<T>*);
        T* getData();
        Container<T>* getNext();
        Container<T>* getPrev();
};

/** @brief inicializa los datos con valor nulo
 */
template <class T> Container<T>::Container(){
    data=0;
    next=0;
    prev=0;
};

/** @brief hace un free sobre el dato
 */
template <class T> Container<T>::~Container(){
    free(data);
};

/** @brief asigna al dato el puntero de parametro
 * @param T* dataParam: nuevo dato
 */
template <class T> void Container<T>::setData(T* dataParam){
    if(!data){
        data = dataParam;
    }else{
        free(data);
        data = dataParam;
    }
};

/** @brief intercambia el dato con el del parametro.
 * @param Container<T>* toSwap: Container a intercambiar
 */
template <class T> void Container<T>::swap(Container<T>* toSwap){
    T* tmp = data;
    data = toSwap->getData();
    toSwap->setData(tmp);
};

/** @brief asigna un Container a la derecha
 * @param Container<T>* nextParam: Container a asignar
 */
template <class T> void Container<T>::setNext(Container<T>* nextParam){
    next = nextParam;
};

/** @brief asigna un Container a la izquierda
 * @param Container<T>* prevParam: Container a asignar
 */
template <class T> void Container<T>::setPrev(Container<T>* prevParam){
    prev = prevParam;
};

/** @brief devuelve un puntero al dato guardado
 * @return T*: dato guardado
 */
template <class T> T* Container<T>::getData(){
    return data;
};

/** @brief devuelve un puntero al Container siguiente
 * @return Container<T>*: contenedor siguiente
 */
template <class T> Container<T>* Container<T>::getNext(){
    return next;
};

/** @brief devuelve un puntero al Container anterior
 * @return Container<T>*: contenedor anterior
 */
template <class T> Container<T>* Container<T>::getPrev(){
    return prev;
};



/*************************************************************************************************
********************************************CLASE LEAF********************************************
*************************************************************************************************/


template <class T> class Leaf{
    int* numbOfConts;
    public:
        Leaf();
        ~Leaf();
        void* split;
};



/*************************************************************************************************
********************************************CLASE TREE********************************************
*************************************************************************************************/

template <class T> class bTree{
    Leaf<T>* root;
public:
    bTree();
    ~bTree();
};


#endif //VH2015_BTREE_H