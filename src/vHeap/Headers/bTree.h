//
// Created by roberto on 19/04/15.
//

#ifndef VH2015_BTREE_H
#define VH2015_BTREE_H


/*************************************************************************************************
*****************************************CLASE DataContainer******************************************
*************************************************************************************************/


/** @brief esta clase contendra un dato tipo T y estara contenida en una hoja
 */
template <class T> class DataContainer{
    T* data;
    DataContainer<T>* next;
    DataContainer<T>* prev;
    public:
        DataContainer();
        ~DataContainer();
        void setData(T*);
        void swap(DataContainer<T>*);
        void setNext(DataContainer<T>*);
        void setPrev(DataContainer<T>*);
        T* getData();
        DataContainer<T>* getNext();
        DataContainer<T>* getPrev();
};

/** @brief inicializa los datos con valor nulo
 */
template <class T> DataContainer<T>::DataContainer(){
    data=0;
    next=0;
    prev=0;
};

/** @brief hace un free sobre el dato
 */
template <class T> DataContainer<T>::~DataContainer(){
    free(data);
};

/** @brief asigna al dato el puntero de parametro
 * @param T* dataParam: nuevo dato
 */
void template <class T> DataContainer<T>::setData(T* dataParam){
    if(!data){
        data = dataParam;
    }else{
        free(data);
        data = dataParam;
    }
};

/** @brief intercambia el dato con el del parametro
 * @param DataContainer<T>* toSwap: DataContainer a intercambiar
 */
void template <class T> DataContainer<T>::swap(DataContainer<T>* toSwap){
    T* tmp = data;
    data = toSwap->getData();
    toSwap->setData(tmp);
};

/** @brief asigna un DataContainer a la derecha
 * @param DataContainer<T>* nextParam: DataContainer a asignar
 */
void template <class T> DataContainer<T>::setNext(DataContainer<T>* nextParam){
    next = nextParam;
};

/** @brief asigna un DataContainer a la izquierda
 * @param DataContainer<T>* prevParam: DataContainer a asignar
 */
void template <class T> DataContainer<T>::::setPrev(DataContainer<T>* prevParam){
    prev = prevParam;
};

/** @brief devuelve un puntero al dato guardado
 * @return T*: dato guardado
 */
T* template <class T> DataContainer<T>::getData(){
    return data;
};

/** @brief devuelve un puntero al DataContainer siguiente
 * @return DataContainer<T>*: contenedor siguiente
 */
DataContainer<T>* template <class T> DataContainer<T>::getNext(){
    return next;
};

/** @brief devuelve un puntero al DataContainer anterior
 * @return DataContainer<T>*: contenedor anterior
 */
DataContainer<T>* template <class T> DataContainer<T>::getPrev(){
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