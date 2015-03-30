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
private:
int position = 0;
vList<T> *myList = 0;
vNode<T> *currentNode = 0;
public:
vListIterator(vList<T> *);
bool exists();
T *next();
};
/** @brief Declaracion de la clase nodo
*
*/
template<class T>
class vNode {
friend class vList<T>; //Clase amiga lista
T data; //Valor almacenado en el nodo
vNode<T> *next; //vNode next
vNode<T> *prev; //vNode prev
public:
vNode(T *); //Constructor
vNode(T); //Constructor
~vNode(); //Destructor
T *getData(); //Devuelve el dato del objeto
vNode<T> *getNextNode(); //Accede al nodo next
vNode<T> *getPrevNode(); //Accede al nodo prev
void insertAfter(vNode<T> *); //Inserta un nodo next
void insertBefore(vNode<T> *); //Inserta un nodo prev
void vaciarDespues(); //Inserta un nodo next
void vaciarAntes(); //Inserta un nodo prev
};
/** @brief Declaracion de la clase nodo
*
*/
template<class T>
class vList
{
vNode<T> *_head; //primer nodo
vNode<T> *_tail; //_tail nodo
int l = 0; //longitud
public:
virtual vListIterator<T> *getIterator();
vList(); //Constructor
~vList(); //Destructor
void add(T); //Inserta nodo al inicio
void append(T); //Inserta nodo al final
bool deleteNodeByData(T); //Busca nodo y lo borra
bool deleteNode(int); //Busca nodo y lo borra
void deleteAll(); //Borra all
bool empty(); //True=vacia
vNode<T> *search(T); //Busca dato T
vNode<T> *getNode(int); //Busca getNode
T *get(int); //Busca getNode
int len(); //Devuelve longtiud
vList<T>operator=(vList<T>); //Operador de asignacion
void print(); //Imprime en consola
};
#endif