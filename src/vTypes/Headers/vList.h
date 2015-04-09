#ifndef _VH2015_LIST_H
#define _VH2015_LIST_H
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
template<class T>
class vList;
template<class T>
class vNode;
template<class T>
class vListIterator {
    unsigned long position = 0;
    vList<T> *myList = 0;
    vNode<T> *currentNode = 0;
    public:
        vListIterator(vList<T> *);
        bool exists();
        T* next();

    unsigned long getPosition();
};
/** @brief Declaracion de la clase nodo
*
*/
template<class T>
class vNode {
    friend class vList<T>; //Clase amiga lista
private:

    T* data; //Valor almacenado en el nodo
    vNode<T>* next; //vNode next
    vNode<T>* prev; //vNode prev
public:
    vNode(T *); //Constructor
    vNode(T); //Constructor
    ~vNode(); //Destructor
    T *getData(); //Devuelve el dato del objeto
    vNode<T> *getNextNode(); //Accede al nodo next
    vNode<T> *getPrevNode(); //Accede al nodo prev
    void insertAfter(vNode<T> *); //Inserta un nodo next
    void insertBefore(vNode<T> *); //Inserta un nodo prev
    void freeNext(); //Inserta un nodo next
    void freePrev(); //Inserta un nodo prev
};
/** @brief Declaracion de la clase nodo
*
*/
template<class T>
class vList {
private:
    vNode<T>* _head; //primer nodo
    vNode<T>* _tail; //_tail nodo
    unsigned long l = 0; //longitud
public:
    virtual vListIterator<T> *getIterator();

    vList(); //Constructor
    ~vList(); //Destructor
    void add(T); //Inserta nodo al inicio
    void append(T); //Inserta nodo al final
    void append(T*); //Inserta nodo al final
    bool deleteNodeByData(T); //Busca nodo y lo borra
    bool deleteNode(unsigned int); //Busca nodo y lo borra
    void deleteAll(); //Borra all
    bool empty(); //True=vacia
    bool swap(unsigned int i, unsigned int j);

    vNode<T> *search(T); //Busca dato T
    vNode<T> *getNode(int); //Busca getNode
    T* get(int); //Busca getNode
    unsigned long len(); //Devuelve longtiud
    vList<T>operator=(vList<T>); //Operador de asignacion
    void print(); //Imprime en consola
};


/** @brief Constructor
*
*/
template<class T>
vNode<T>::vNode(T* v) {
    std::cout<<"1"<<std::endl;
    data = static_cast<T*>(malloc(sizeof(T)));
    std::cout<<"1"<<std::endl;
    *data = *v;
    std::cout<<"1"<<std::endl;

    next = 0;
};
/** @brief Constructor
*
*/
template<class T>
vNode<T>::vNode(T v) {
    data = static_cast<T*>(malloc(sizeof(T)));
    *data = v;
    next = 0;
}
/** @brief Destructor
*
*/
template<class T>
vNode<T>::~vNode() {
    next = 0;
    prev = 0;
};
/** @brief Devuelve el next nodo
*
* @return vNode<T>
*/
template<class T>
vNode<T>* vNode<T>::getNextNode() {
    return next;
};
/** @brief Devuelve el nodo prev
*
* @return vNode<T>
*/
template<class T>
vNode<T>* vNode<T>::getPrevNode() {
    return prev;
};
/** @brief Devuelve el dato contenido
*
* @return T
*/
template<class T>
T* vNode<T>::getData() {
    return data;
};
/** @brief Inserta un nodo despues
*
* @param vNode<T>*
*/
template<class T>
void vNode<T>::insertAfter(vNode<T> *n) {
    if(next!=0){
        vNode<T> *tmp = next;
        next = n;
        next->insertAfter(tmp);
    }else{
        next=n;
    };
    if(next->getPrevNode()!=this){
        next->insertBefore(this);
    };
};
/** @brief Inserta un nodo antes
*
* @param vNode<T>*
*/
template<class T>
void vNode<T>::insertBefore(vNode<T> *n) {
    if(prev!=0){
        vNode<T> *tmp = prev;
        prev = n;
        prev->insertBefore(tmp);
    }else{
        prev=n;
    };
    if(prev->getNextNode()!=this){
        prev->insertAfter(this);
    }
};
/** @brief Vacia nodo antes
*
*/
template<class T>
void vNode<T>::freePrev() {
    prev = nullptr;
};
/** @brief Vacia nodo despues
*
*/
template<class T>
void vNode<T>::freeNext() {
    next = nullptr;
};
/** @brief Construye la lista
*
*/
template<class T>
vList<T>::vList() {
    _head=_tail=0;
};
/** @brief Destruye la lista
*
*/
template<class T>
vList<T>::~vList() {
    deleteAll();
    free(&l);
};
/** @brief Inserta un nodo al inicio
*
* @param vNode<T>*
*/
template<class T>
void vList<T>::add(T d) {
    vNode<T> *n = new vNode<T>(d);
    if(_head!=0){
        _head->insertBefore(n);
        _head=n;
    }else{
        _head = n;
        _tail = n;
    };
    l++;
};

/** @brief Inserta un nodo al final
*
* @param vNode<T>*
*/
template<class T>
void vList<T>::append(T* d) {
    std::cout<<"APPEND1"<<std::endl;
    vNode<T>* n = static_cast<vNode<T>*>(malloc(sizeof(vNode<T>)));
    std::cout<<"APPEND2"<<std::endl;
    new(n) vNode<T>(d);
    std::cout<<"APPEND3"<<std::endl;
    if(_tail!=0){
        std::cout<<"APPEND4"<<std::endl;
        _tail->insertAfter(n);
        std::cout<<"APPEND5"<<std::endl;
        _tail=n;
    }else{
        _head=n;
        _tail=n;
    };
    l++;
};

/** @brief Inserta un nodo al final
*
* @param vNode<T>*
*/
template<class T>
void vList<T>::append(T d) {
    vNode<T>* n = static_cast<vNode<T>*>(malloc(sizeof(vNode<T>)));
    new(n) vNode<T>(d);
    if(_tail!=0){
        _tail->insertAfter(n);
        _tail=n;
    }else{
        _head=n;
        _tail=n;
    };
    l++;
};
/** @brief Borra el nodo que contiene el dato d
*
* @param T d
*/
template<class T>
bool vList<T>::deleteNodeByData(T d) {
    vNode<T> *tmp = _head;
    for(int i=0; i<l; i++){
        if(*tmp->getData()()==d){
            if(i<l-1){
                tmp->getPrevNode()->insertAfter(tmp->getNextNode());
            }
            free(tmp);
            l--;
            return true;
        };
        tmp=tmp->getNextNode();
    };
    return false;
};
/** @brief Borra el nodo de la getNode d
*
* @param int d
*/
template<class T>
bool vList<T>::deleteNode(unsigned int d) {
    if(d==0){
        _head=_head->getNextNode();
        (_head->getPrevNode())->~vNode();
        free(_head->getPrevNode());
        _head->freePrev();
        l--;
        return true;
    }else if(d==l-1){
        vNode<T> *tmp = _tail;
        _tail=_tail->getPrevNode();
        _tail->getNextNode()->~vNode();
        free(_tail->getNextNode());
        _tail->freeNext();
        l--;
        return true;
    }else if(d<l){
        vNode<T> *tmp = _head;
        for(int i=0; i<d; i++){
            tmp=tmp->getNextNode();
        };
        vNode<T> *ant = tmp->getPrevNode();
        vNode<T> *sig = tmp->getNextNode();
        tmp->~vNode();
        free(tmp);
        ant->freeNext();
        sig->freePrev();
        ant->insertAfter(sig);
        l--;
        return true;
    }else{
        return false;
    };
};
/** @brief Borra todos los nodos
*
*/
template<class T>
void vList<T>::deleteAll() {
    for(int i=0; i<l; i++){
        vNode<T> *tmp = _head;
        _head=_head->getNextNode();
        free(tmp);
    };
    l=0;
};
/** Revisa si la lista esta o no vacia
*
* @return bool
*/
template<class T>
bool vList<T>::empty() {
    return (len()==0);
};
/** Busca un dato y devuelve el nodo que lo contiene
*
* @param T d, dato
* @return vNode<T>*
*/
template<class T>
vNode<T> *vList<T>::search(T d) {
    vNode<T> *tmp = _head;
    for(int i=0; i<l; i++){
        if(*tmp->getData()()==d){
            return tmp;
        };
        tmp=tmp->getNextNode();
    };
    return 0;
};
/** Devuelve el nodo en la getNode que se indique
*
* @param int n, getNode
* @return vNode<T>*
*/
template<class T>
vNode<T> *vList<T>::getNode(int n) {
    if(n<l){
        if(n<l/2){
            vNode<T> *tmp = _head;
            for(int i=0; i<n; i++){
                tmp=tmp->getNextNode();
            };
            return tmp;
        }else{
            vNode<T> *tmp = _tail;
            for(int i=l-1; i>n; i--){
                tmp=tmp->getPrevNode();
            };
            return tmp;
        };
    }else{
        return 0;
    };
};
/** Devuelve el dato en la getNode que se indique
*
* @param int n, getNode
* @return T*
*/
template<class T>
T *vList<T>::get(int n) {
    if(n<l){
        if(n<l/2){
            vNode<T> *tmp = _head;
            for(int i=0; i<n; i++){
                tmp=tmp->getNextNode();
            };
            return (tmp->getData());
        }else{
            vNode<T> *tmp = _tail;
            for(int i=l-1; i>n; i--){
                tmp=tmp->getPrevNode();
            };
            return (tmp->getData());
        };
    }else{
    };
};
/** Devuelve la longitud
*
* @return int;
*/
template<class T>
unsigned long vList<T>::len() {
    return l;
};
/** @brief Imprime la lista
*
*/
template<class T>
void vList<T>::print() {
    if(len()>0){
        vNode<T> *tmp = _head;
        for(int i=0; i<len(); i++){
            std::cout << *(tmp->getData()()) << std::endl;
            tmp=tmp->getNextNode();
        };
    }else{
        std::cout<<"La lista esta vacia"<<std::endl;
    };
};
template <class T>
vListIterator<T> *vList<T>::getIterator() {
    return new vListIterator<T>(this);
}
template <class T>
bool vListIterator<T>::exists() {
    return position<myList->len();
}
template <class T>
T *vListIterator<T>::next() {
    if (!currentNode)
        currentNode = myList->getNode(0);
    else
        currentNode = currentNode->getNextNode();
    position++;
    return currentNode->getData();
}
template <class T>
vListIterator<T>::vListIterator(vList<T> *lista) {
    myList = lista;
}

template<class T>
unsigned long vListIterator<T>::getPosition() {
    return position;
}


template<class T>
bool vList<T>::swap(unsigned int i, unsigned int j) {
    if (j > l - 1 || i > l - 1 || i == j)
        return false;

    vNode<T> *iNode = getNode(i);
    vNode<T> *jNode = getNode(j);

    T *dataI = iNode->data;
    iNode->data = jNode->data;
    jNode->data = dataI;
    return true;


}

#endif
