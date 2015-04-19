//
// Created by roberto on 19/04/15.
//

#ifndef VH2015_BTREE_H
#define VH2015_BTREE_H

#include <cstdlib>

int treeSize;

/*************************************************************************************************
*****************************************CLASE Container******************************************
*************************************************************************************************/


/** @brief esta clase contendra un dato tipo T y estara contenida en una hoja
 */
template <class T> class Container{
    T* data;                //Contenido
    Container<T>* next;     //Siguiente
    Container<T>* prev;     //Anterior
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


/** @brief miembro del arbol
 * Numero de hijos: n, tal que n=treeSize 
 * Numero de containers: n-1
 */
template <class T> class Leaf{
    int* filledContainers;          //Numero de contenedores llenos
    Container<T>* firstContainer;   //Primer contenedor
    Container<T>* lastContainer;    //Ultimo contenedor
    Leaf<T>* nextLeaf;              //Hoja hermana siguiente
    Leaf<T>* prevLeaf;              //Hoja hermana anterior
    Leaf<T>* firstSon;              //Primera hoja hija
    Leaf<T>* lastSon;               //Ultima hoja hija
    bool* terminal;                 //Bandera que indica si es terminal: true=sin hijos
    void createContainers();
    void createSons();
    void adjustContainers();
    public:
        Leaf();
        ~Leaf();
        bool isTerminal();
        void split();
        void insert(T*);
        void setNext(Leaf<T>*);
        void setPrev(Leaf<T>*);
        void setNextLeaf(Leaf<T>*);
        void setPrevLeaf(Leaf<T>*);
        Leaf<T>* getNextLeaf();
        Leaf<T>* getPrevLeaf();
        Leaf<T>* getFirstSon();
        Leaf<T>* getLastSon();
        Container<T>* getFirstContainer();
        Container<T>* getLastContainer();
};

/** @brief crea una hoja con n-1 containers, tal que n=treeSize
 */
template <class T> Leaf<T>::Leaf(){
    createContainers();
    firstSon = 0;
    lastSon = 0;
    filledContainers = static_cast<int*>(malloc(sizeof(int)));
    *filledContainers = 0;
    terminal = static_cast<bool*>(malloc(sizeof(bool)));
    *terminal = true;
};

/** @brief recorre los containers eliminando cada uno
 */
template <class T> Leaf<T>::~Leaf(){
    for(int i=1; i < treeSize; i++){
        Container<T>* tmp = firstContainer;
        firstContainer = firstContainer->getNext();
        free(tmp);
    };
};

/** @brief crea n-1 containers, tal que n=treeSize
 */
template <class T> void Leaf<T>::createContainers(){
    firstContainer = static_cast<Container<T>*>(malloc(sizeof(Container<T>)));
    lastContainer = static_cast<Container<T>*>(malloc(sizeof(Container<T>)));
    new(firstContainer) Container<T>();
    new(lastContainer) Container<T>();
    
    Container<T>* tmp=firstContainer;
    for(int i=3; i < treeSize; i++){
        Container<T>* newContainer = static_cast<Container<T>*>(malloc(sizeof(Container<T>)));
        new(newContainer) Container<T>();
        newContainer->setPrev(tmp);
        tmp->setNext(newContainer);
        tmp = tmp->getNext();
    };
    
    lastContainer->setPrev(tmp);
    tmp->setNext(lastContainer);
};


/** @brief crea n hojas hijas, tal que n=treeSize
 */
template <class T> void Leaf<T>::createSons(){    
    firstSon = static_cast<Leaf<T>*>(malloc(sizeof(Leaf<T>)));
    lastSon = static_cast<Leaf<T>*>(malloc(sizeof(Leaf<T>)));
    new(firstSon) Leaf<T>();
    new(lastSon) Leaf<T>();

    Leaf<T>* tmp=firstSon;
    for(int i=0; i < treeSize; i++){
        Leaf<T>* newLeaf = static_cast<Leaf<T>*>(malloc(sizeof(Leaf<T>)));
        new(newLeaf) Leaf<T>();
        newLeaf->setPrevLeaf(tmp);
        tmp->setNextLeaf(newLeaf);
        tmp = tmp->getNextLeaf();
    };

    lastSon->setPrevLeaf(tmp);
    tmp->setNextLeaf(lastSon);
};

/** @brief reparte los contenedores entre los hijos
 */
template <class T> void Leaf<T>::adjustContainers(){};          //TODO: implementar

/** @brief crea n hojas hijas, tal que n=treeSize
 */
template <class T> bool Leaf<T>::isTerminal(){
    return *terminal;
};

/** @brief divide la hoja creando hijos
 */
template <class T> void Leaf<T>::split(){
    createSons();
    adjustContainers();
};

/** @brief inserta una hoja como siguiente
 * @param Leaf<T>* next: hoja a insertar
 */
template <class T> void Leaf<T>::setNextLeaf(Leaf<T>* next){
    nextLeaf = next;
};

/** @brief inserta una hoja como anterior
 * @param Leaf<T>* prev: hoja a insertar
 */
template <class T> void Leaf<T>::setPrevLeaf(Leaf<T>* prev){
    prevLeaf = prev;
};

/** @brief devuelve el primer container
 * @return Container<T>*
 */
template <class T> Leaf<T>* Leaf<T>::getNextLeaf(){
    return nextLeaf;
};

/** @brief devuelve el primer container
 * @return Container<T>*
 */
template <class T> Leaf<T>* Leaf<T>::getPrevLeaf(){
    return prevLeaf;
};

/** @brief devuelve el primer container
 * @return Container<T>*
 */
template <class T> Container<T>* Leaf<T>::getFirstContainer(){
    return firstContainer;
};

/** @brief devuelve el ultimo container
 * @return Container<T>*
 */
template <class T> Container<T>* Leaf<T>::getLastContainer(){
    return lastContainer;
};

/** @brief devuelve el primer hijo
 * @return Leaf<T>*
 */
template <class T> Leaf<T>* Leaf<T>::getFirstSon(){
    return firstSon;
};

/** @brief devuelve el ultimo hijo
 * @return Leaf<T>*
 */
template <class T> Leaf<T>* Leaf<T>::getLastSon(){
    return lastSon;
};

/** @brief inserta un dato en el container indicado
 * @param T* newData: dato a insertar
 */
template <class T> void Leaf<T>::insert(T* newData){};          //TODO: implementar

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