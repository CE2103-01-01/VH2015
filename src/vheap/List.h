//
// Created by alex on 19/03/15.
//
#ifndef _VH2015_LIST_H
#define _VH2015_LIST_H

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
template<class T> class List;
template<class T> class Node;
template <class T> class ListIterator{
private:
    int position;
    List<T>* myList;
    Node<T>* currentNode;
public:
    ListIterator(List<T>*);
    virtual bool exists();
    virtual T* next();

};


/** @brief Declaracion de la clase nodo
*
*/
template<class T> class Node{
    friend class List<T>; //Clase amiga lista
    T *data; //Valor almacenado en el nodo
    Node<T> *next; //Node next
    Node<T> *prev; //Node prev
public:
    Node(T*); //Constructor
    Node(T); //Constructor
    ~Node(); //Destructor
    T* getData(); //Devuelve el dato del objeto
    Node<T>* getNextNode(); //Accede al nodo next
    Node<T>* getPrevNode(); //Accede al nodo prev
    void append(Node<T>*); //Inserta un nodo next
    void add(Node<T>*); //Inserta un nodo prev
    void vaciarDespues(); //Inserta un nodo next
    void vaciarAntes(); //Inserta un nodo prev
};


/** @brief Declaracion de la clase nodo
*
*/
template<class T> class List
{
    Node<T>* _head; //primer nodo
    Node<T>* _tail; //_tail nodo
    int l = 0; //longitud
public:
    virtual void getIterator(ListIterator<T>*);
    List(); //Constructor
    ~List(); //Destructor
    void add(T); //Inserta nodo al inicio
    void append(T); //Inserta nodo al final
    bool deleteNode(T); //Busca nodo y lo borra
    bool deleteNode(int); //Busca nodo y lo borra
    void deleteAll(); //Borra all
    bool empty(); //True=vacia
    Node<T>* search(T); //Busca dato T
    Node<T>* getNode(int); //Busca getNode
    T get(int); //Busca getNode
    int len(); //Devuelve longtiud
    List<T>operator=(List<T>); //Operador de asignacion
    void print(); //Imprime en consola
};


/** @brief Constructor
*
*/
template<class T> Node<T>::Node(T *v){
    data=static_cast<T*>(malloc(sizeof(v)));
    *data=*v;
    free(v);
};
/** @brief Constructor
*
*/
template<class T> Node<T>::Node(T v){
    data=static_cast<T*>(malloc(sizeof(v)));
    new(data) T(v);
};
/** @brief Destructor
*
*/
template<class T> Node<T>::~Node(){
    next=0;
    prev=0;
    free(data);
};
/** @brief Devuelve el next nodo
*
* @return Node<T>
*/
template<class T> Node<T>* Node<T>::getNextNode(){
    return next;
};
/** @brief Devuelve el nodo prev
*
* @return Node<T>
*/
template<class T> Node<T>* Node<T>::getPrevNode(){
    return prev;
};
/** @brief Devuelve el dato contenido
*
* @return T
*/
template<class T> T* Node<T>::getData(){
    return data;
};
/** @brief Inserta un nodo despues
*
* @param Node<T>*
*/
template<class T> void Node<T>::append(Node<T>* n){
    if(next!=0){
        next->add(n);
    };
    next=n;
    if(n->getPrevNode()!=this){
        n->add(this);
    };
};
/** @brief Inserta un nodo antes
*
* @param Node<T>*
*/
template<class T> void Node<T>::add(Node<T>* n){
    if(prev!=0){
        prev->append(n);
    };
    prev=n;
    if(n->getNextNode()!=this){
        n->append(this);
    };
};
/** @brief Vacia nodo antes
*
*/
template<class T> void Node<T>::vaciarAntes(){
    prev=0;
};
/** @brief Vacia nodo despues
*
*/
template<class T> void Node<T>::vaciarDespues(){
    next=0;
};
/** @brief Construye la lista
*
*/
template<class T> List<T>::List(){
    _head=_tail=0;
};
/** @brief Destruye la lista
*
*/
template<class T> List<T>::~List(){
    deleteAll();
    free(&l);
};
/** @brief Inserta un nodo al inicio
*
* @param Node<T>*
*/
template<class T> void List<T>::add(T d){
    Node<T> *n = static_cast<Node<T>*>(malloc(sizeof(Node<T>)));
    new (n) Node<T>(d);
    if(_head==0){
        _head = n;
        _tail = n;
    }else{
        n->append(_head);
        _head=n;
    };
    l++;
};
/** @brief Inserta un nodo al final
*
* @param Node<T>*
*/
template<class T> void List<T>::append(T d){
    Node<T> *n = static_cast<Node<T>*>(malloc(sizeof(Node<T>)));
    new (n) Node<T>(d);
    if(_head==0){
        _head=n;
        _tail=n;
    }else{
        n->add(_tail);
        _tail=n;
    };
    l++;
};
/** @brief Borra el nodo que contiene el dato d
*
* @param T d
*/
template<class T> bool List<T>::deleteNode(T d){
    Node<T>* tmp=_head;
    for(int i=0; i<l; i++){
        if(*tmp->getData()()==d){
            if(i<l-1){
                tmp->getPrevNode()->append(tmp->getNextNode());
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
template<class T> bool List<T>::deleteNode(int d){
    if(d==0){
        _head=_head->getNextNode();
        _head->getPrevNode()->~Node();
        free(_head->getPrevNode());
        l--;
        return true;
    }else if(d==l-1){
        Node<T>* tmp=_tail;
        _tail=_tail->getPrevNode();
        _tail->getNextNode()->~Node();
        free(_tail->getNextNode());
        l--;
        return true;
    }else if(d<l){
        Node<T>* tmp=_head;
        for(int i=0; i<d; i++){
            tmp=tmp->getNextNode();
        };
        Node<T>* ant=tmp->getPrevNode();
        Node<T>* sig=tmp->getNextNode();
        tmp->~Node();
        free(tmp);
        ant->vaciarDespues();
        sig->vaciarAntes();
        ant->append(sig);
        l--;
        return true;
    }else{
        return false;
    };
};
/** @brief Borra todos los nodos
*
*/
template<class T> void List<T>::deleteAll(){
    for(int i=0; i<l; i++){
        Node<T> *tmp=_head;
        _head=_head->getNextNode();
        free(tmp);
    };
    l=0;
};
/** Revisa si la lista esta o no vacia
*
* @return bool
*/
template<class T> bool List<T>::empty(){
    return (len()==0);
};
/** Busca un dato y devuelve el nodo que lo contiene
*
* @param T d, dato
* @return Node<T>*
*/
template<class T> Node<T>* List<T>::search(T d){
    Node<T>* tmp=_head;
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
* @return Node<T>*
*/
template<class T> Node<T>* List<T>::getNode(int n){
    if(n<l){
        if(n<l/2){
            Node<T>* tmp=_head;
            for(int i=0; i<n; i++){
                tmp=tmp->getNextNode();
            };
            return tmp;
        }else{
            Node<T>* tmp=_tail;
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
template<class T> T List<T>::get(int n){
    if(n<l){
        if(n<l/2){
            Node<T>* tmp=_head;
            for(int i=0; i<n; i++){
                tmp=tmp->getNextNode();
            };
            return *(tmp->getData()());
        }else{
            Node<T>* tmp=_tail;
            for(int i=l-1; i>n; i--){
                tmp=tmp->getPrevNode();
            };
            return *(tmp->getData()());
        };
    }else{
// return 0;
    };
};
/** Devuelve la longitud
*
* @return int;
*/
template<class T> int List<T>::len(){
    return l;
};
/** @brief Imprime la lista
*
*/
template<class T> void List<T>::print(){
    if(len()>0){
        Node<T>* tmp=_head;
        for(int i=0; i<len(); i++){
            std::cout<<*(tmp->getData()())<<std::endl;
            tmp=tmp->getNextNode();
        };
    }else{
        std::cout<<"La lista esta vacia"<<std::endl;
    };
};


template <class T>
void List<T>::getIterator(ListIterator<T> *temp) {
    new(temp) ListIterator<T>(this);

}
template <class T>
bool ListIterator<T>::exists() {
    return position<myList->len();
}

template <class T>
T* ListIterator<T>::next() {
    if (!currentNode)
        currentNode =  myList->getNode(0);
    else
        currentNode->getNextNode();
    position++;
    return currentNode->getData();
}

template <class T>
ListIterator<T>::ListIterator(List<T>* lista) {
    myList = lista;
}

#endif //_VH2015_LIST
