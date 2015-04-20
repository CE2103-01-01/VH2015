//
// Created by roberto on 19/04/15.
//

#ifndef VH2015_TREE_H
#define VH2015_TREE_H

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
    data = dataParam;
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
    int* filledSons;                //Numero de contenedores llenos
    Container<T>* firstContainer;   //Primer contenedor
    Container<T>* lastContainer;    //Ultimo contenedor
    Leaf<T>* nextLeaf;              //Hoja hermana siguiente
    Leaf<T>* prevLeaf;              //Hoja hermana anterior
    Leaf<T>* firstSon;              //Primera hoja hija
    Leaf<T>* lastSon;               //Ultima hoja hija
    Leaf<T>* father;                //Hoja padre
    bool* terminal;                 //Bandera que indica si es terminal: true=sin hijos
    void createContainers();
    void createSons();
    void shortInsertion(T*);
    void longInsertion(T*);
    void continueInsertion(T*);
    void slowlyOpenSpace(T*);
    void quicklyOpenSpace(T*);
    public:
        Leaf(Leaf<T>*);
        ~Leaf();
        bool isTerminal();
        bool isFull();
        void split();
        void insert(T*);
        void openSpace(T*);
        void setNextLeaf(Leaf<T>*);
        void setPrevLeaf(Leaf<T>*);
        Leaf<T>* getNextLeaf();
        Leaf<T>* getPrevLeaf();
        Leaf<T>* getFirstSon();
        Leaf<T>* getLastSon();
        Container<T>* getFirstContainer();
        Container<T>* getLastContainer();
        void imFull();
        void imNotFull();
};

/** @brief crea una hoja con n-1 containers, tal que n=treeSize
 */
template <class T> Leaf<T>::Leaf(Leaf<T>* fatherParam){
    father = fatherParam;
    createContainers();
    firstSon = 0;
    lastSon = 0;
    filledContainers = static_cast<int*>(malloc(sizeof(int)));
    *filledContainers = 0;
    filledSons = static_cast<int*>(malloc(sizeof(int)));
    *filledSons = 0;
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
    new(firstContainer) Container<T>();
    lastContainer=firstContainer;
    for(int i=2; i < treeSize; i++){
        Container<T>* newContainer = static_cast<Container<T>*>(malloc(sizeof(Container<T>)));
        new(newContainer) Container<T>();
        newContainer->setPrev(lastContainer);
        lastContainer->setNext(newContainer);
        lastContainer = lastContainer->getNext();
    };
};


/** @brief crea n hojas hijas, tal que n=treeSize
 */
template <class T> void Leaf<T>::createSons(){
    *terminal = false;                                          //Coloca en false la bandera
    firstSon = (Leaf<T>*)(malloc(sizeof(Leaf<T>)));             //Reserva el primer hijo
    new(firstSon) Leaf(this);                                   //Toma el primer hijo
    lastSon=firstSon;
    for(int index=1; index<treeSize; index++){
        Leaf<T>* newLeaf = (Leaf<T>*)(malloc(sizeof(Leaf<T>))); //Reserva espacio para la nueva hoja
        new(newLeaf) Leaf(this);                                //Crea la nueva hoja
        newLeaf->setPrevLeaf(lastSon);                          //Introduce el ultimo antes del nuevo
        lastSon->setNextLeaf(newLeaf);                          //Introduce al nuevo antes del ultimo
        lastSon = lastSon->getNextLeaf();                       //Convierte al ultimo en el nuevo
    };
    for(Container<T>* tmp = firstContainer; tmp!=lastContainer ; tmp = tmp->getNext()){
        firstSon->insert(tmp->getData());                       //Inserta el contenedor en la primer hoja
        tmp->setData(0);                                        //Borra el contenido del contenedor
    };
    firstContainer->swap(lastContainer);                        //Cambia el primer contenedor con el ultimo
};

/** @brief crea n hojas hijas, tal que n=treeSize
 */
template <class T> bool Leaf<T>::isTerminal(){
    return *terminal;
};

/** @brief divide la hoja creando hijos
 */
template <class T> void Leaf<T>::split(){
    createSons();
    father->imNotFull();
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

/** @brief abre un espacio en el padre e inserta el dato
 * @param T* newData: dato a insertar
 */
template <class T> void Leaf<T>::openSpace(T* newData){
    if(!isFull()){
        quicklyOpenSpace(newData);
    }else{
        slowlyOpenSpace(newData);
    }
};

/** @brief abre un espacio e inserta el dato sabiendo que no hay campo
 * @param T* newData: dato a insertar
 */
template <class T> void Leaf<T>::slowlyOpenSpace(T* newData){
    Container<T>* tmpContainer = firstContainer;
    for(Leaf<T>* tmpSon = firstSon->getNextLeaf(); tmpContainer!=0; tmpSon=tmpSon->getNextLeaf()){
        if(*(tmpContainer->getData()) > *newData){
            T* tmpData = tmpContainer->getData();
            tmpContainer->setData(newData);
            newData = tmpData;
            if(!(tmpSon->isFull())){
                tmpSon->insert(newData);
                newData=0;
                break;
            }
        tmpContainer=tmpContainer->getNext();
        }
    }
    if(newData!=0 && father!=0){
        father->openSpace(newData);
    }
};

/** @brief abre un espacio e inserta el dato sabiendo que hay campo
 * @param T* newData: dato a insertar
 */
template <class T> void Leaf<T>::quicklyOpenSpace(T* newData){
    for(Container<T>* tmp = firstContainer; tmp!=0; tmp=tmp->getNext()){
        if(tmp->getData() == 0){
            tmp->setData(newData);
        }else if(*(tmp->getData()) > *newData){
            T* out=tmp->getData();
            tmp->setData(newData);
            newData=out;
        }
    }
};

/** @brief busca la hoja correcta para insertar
 * @param T* newData: dato a insertar
 */
template <class T> void Leaf<T>::insert(T* newData){
    if(!isTerminal()){
        continueInsertion(newData);
    }else{
        if(!(isFull())){
            shortInsertion(newData);
            (*filledContainers)++;
            if(isFull()){
                father->imFull();
            }
        }else{
            longInsertion(newData);
        }
    }
};


/** @brief continua localizando la hoja correcta
 * @param T* newData: dato a insertar
 */
template <class T> void Leaf<T>::continueInsertion(T* newData){
    Container<T>* tmpContainer = firstContainer;
    for(Leaf<T>* tmpSon = firstSon; tmpContainer!=0; tmpSon=tmpSon->getNextLeaf()){
        if(tmpContainer->getData() == 0){
            tmpContainer->setData(newData);
        }else if(*(tmpContainer->getData()) > *newData){
            tmpSon->insert(newData);
            break;
        }else{
            tmpContainer=tmpContainer->getNext();
        }
    }
    if(tmpContainer==0){
        lastSon->insert(newData);
    }
}

/** @brief cuando se ha localizado la hoja correcta, se introduce el dato
 * @param T* newData: dato a insertar
 */
template <class T> void Leaf<T>::shortInsertion(T* newData){
    for(Container<T>* tmp = firstContainer; tmp!=0; tmp=tmp->getNext()){
        if(tmp->getData() == 0){
            tmp->setData(newData);
        }else if(*(tmp->getData()) > *newData){
            Container<T>* out = tmp->getData();
            tmp->setData(newData);
            newData=out;
        }
    } 
};

/** @brief hace el reacomodo necesario e introduce el dato
 * @param T* newData: dato a insertar
 */
template <class T> void Leaf<T>::longInsertion(T* newData){
    if(*newData < *(lastContainer->getData())){
        father->openSpace(lastContainer->getData());
        lastContainer->setData(0);
        shortInsertion(newData);
    }else{
        father->openSpace(lastContainer->getData());
    }
}

/** @brief inserta un dato en el container indicado
 * @param bool: true si esta lleno
 */
template <class T> bool Leaf<T>::isFull(){
    return (*filledContainers == treeSize-1) && (*filledSons == treeSize);
};

/** @brief notificacion del hijo para indicar que no posee espacio
*/
template <class T> void Leaf<T>::imFull(){
    (*filledSons)++;
};

/** @brief notificacion del hijo para indicar que posee espacio
*/
template <class T> void Leaf<T>::imNotFull(){
    (*filledSons)--;
};


/*************************************************************************************************
********************************************CLASE TREE********************************************
*************************************************************************************************/

template <class T> class Tree{
    Leaf<T>* root;
public:
    Tree();
    ~Tree();
};


#endif //VH2015_TREE_H