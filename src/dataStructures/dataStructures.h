#ifndef DATASTRUCTURES_H_INCLUDED
#define DATASTRUCTURES_H_INCLUDED

#include <iostream>
#include <stdlib.h>
#include <stdio.h>

template<class T> class Lista;

/** @brief Declaracion de la clase nodo
*
*/
template<class T> class Nodo{
    friend class Lista<T>;      //Clase amiga lista
    T *valor;                   //Valor almacenado en el nodo
    Nodo<T> *siguiente;         //Nodo siguiente
    Nodo<T> *anterior;          //Nodo anterior
    public:
        Nodo(T*);                       //Constructor
        Nodo(T);                        //Constructor
        ~Nodo();                        //Destructor
        T* obtenerDato();               //Devuelve el dato del objeto
        Nodo<T>* obtenerSiguiente();    //Accede al nodo siguiente
        Nodo<T>* obtenerAnterior();     //Accede al nodo anterior
        void insertarDespues(Nodo<T>*); //Inserta un nodo siguiente
        void insertarAntes(Nodo<T>*);   //Inserta un nodo anterior
        void vaciarDespues();           //Inserta un nodo siguiente
        void vaciarAntes();             //Inserta un nodo anterior
};

/** @brief Constructor
*
*/
template<class T> Nodo<T>::Nodo(T *v){
    anterior=0;
    siguiente=0;
    valor=static_cast<T*>(malloc(sizeof(v)));
    *valor=*v;
    free(v);
};

/** @brief Constructor
*
*/
template<class T> Nodo<T>::Nodo(T v){
    anterior=0;
    siguiente=0;
    valor=static_cast<T*>(malloc(sizeof(v)));
    new(valor) T(v);
};

/** @brief Destructor
*
*/
template<class T> Nodo<T>::~Nodo(){
    siguiente=0;
    anterior=0;
    free(valor);
};

/** @brief Devuelve el siguiente nodo
 *
 * @return Nodo<T>
 */
template<class T> Nodo<T>* Nodo<T>::obtenerSiguiente(){
    return siguiente;
};

/** @brief Devuelve el nodo anterior
 *
 * @return Nodo<T>
 */
template<class T> Nodo<T>* Nodo<T>::obtenerAnterior(){
    return anterior;
};

/** @brief Devuelve el dato contenido
 *
 * @return T
 */
template<class T> T* Nodo<T>::obtenerDato(){
    return valor;
};

/** @brief Inserta un nodo despues
 *
 * @param Nodo<T>*
 */
template<class T> void Nodo<T>::insertarDespues(Nodo<T>* n){
    if(siguiente!=0){
        Nodo<T>* tmp = siguiente;
        siguiente=n;
        siguiente->insertarDespues(tmp);
        if(siguiente->obtenerAnterior()!=this){
            siguiente->insertarAntes(this);
        };
    }else{
        siguiente=n;
        siguiente->insertarAntes(this);
    };
};

/** @brief Inserta un nodo antes
 *
 * @param Nodo<T>*
 */
template<class T> void Nodo<T>::insertarAntes(Nodo<T>* n){
    if(anterior!=0){
        Nodo<T>* tmp = anterior;
        anterior=n;
        anterior->insertarAntes(tmp);
        if(anterior->obtenerSiguiente()!=this){
            anterior->insertarDespues(this);
        };
    }else{
        anterior=n;
        anterior->insertarDespues(this);
    };
};

/** @brief Vacia nodo antes
 *
 */
template<class T> void Nodo<T>::vaciarAntes(){
    anterior=0;
};

/** @brief Vacia nodo despues
 *
 */
template<class T> void Nodo<T>::vaciarDespues(){
    siguiente=0;
};







/************************/




/** @brief Declaracion de la clase lista
 *
 */
template<class T> class Lista{
    Nodo<T>* primero;               //primer nodo
    Nodo<T>* ultimo;                //ultimo nodo
    int l;                          //longitud
    public:
        Lista();                        //Constructor
        ~Lista();                       //Destructor
        void insertarAlInicio(T);       //Inserta nodo al inicio
        void insertarAlFinal(T);        //Inserta nodo al final
        bool borrar(T);                 //Busca nodo y lo borra
        bool borrarPos(int);            //Busca nodo y lo borra
        void borrarTodo();              //Borra todo
        bool estaVacia();               //True=vacia
        Nodo<T> buscar(T);             //Busca dato T
        Nodo<T> posicion(int);         //Busca posicion
        T datoPosicion(int);           //Busca posicion
        int len();                      //Devuelve longtiud
        Lista<T>operator=(Lista<T>);    //Operador de asignacion
        void imprimir();                //Imprime en consola
};




/** @brief Construye la lista
 *
 */
template<class T> Lista<T>::Lista(){
    primero=static_cast<Nodo<T>*>(malloc(sizeof(Nodo<T>)));
    ultimo=static_cast<Nodo<T>*>(malloc(sizeof(Nodo<T>)));
    l=0;
};

/** @brief Destruye la lista
 *
 */
template<class T> Lista<T>::~Lista(){
    borrarTodo();
    free(&l);
};

/** @brief Inserta un nodo al inicio
 *
 * @param Nodo<T>*
 */
template<class T> void Lista<T>::insertarAlInicio(T d){
    Nodo<T> *n = static_cast<Nodo<T>*>(malloc(sizeof(Nodo<T>)));
    new (n) Nodo<T>(d);
    if(primero==0){
        primero = n;
    }else{
        n->insertarDespues(primero);
        primero=n;
    };
    l++;
};

/** @brief Inserta un nodo al final
 *
 * @param Nodo<T>*
 */
template<class T> void Lista<T>::insertarAlFinal(T d){
    Nodo<T> n = Nodo<T>(d);
    if(ultimo->obtenerDato()!=0){
        Nodo<T>* tmp = static_cast<Nodo<T>*>(malloc(sizeof(Nodo<T>)));
        *tmp=*ultimo;
        *ultimo=n;
        ultimo->insertarAntes(tmp);
    }else if(primero->obtenerDato()!=0){
        *ultimo = n;
        ultimo->insertarAntes(primero);
    }else{
        *primero = n;
    };
    l++;
};

/** @brief Borra el nodo que contiene el dato d
 *
 * @param T d
 */
template<class T> bool Lista<T>::borrar(T d){
    Nodo<T>* tmp=primero;
    for(int i=0; i<l; i++){
        if(*tmp->obtenerDato()==d){
            if(i<l-1){
                tmp->obtenerAnterior()->insertarDespues(tmp->obtenerSiguiente());
            }
            free(tmp);
            l--;
            return true;
        };
        tmp=tmp->obtenerSiguiente();
    };
    return false;
};

/** @brief Borra el nodo de la posicion d
 *
 * @param int d
 */
template<class T> bool Lista<T>::borrarPos(int d){
    if(d==0){

        primero=primero->obtenerSiguiente();
        primero->obtenerAnterior()->~Nodo();
        free(primero->obtenerAnterior());
        l--;
        return true;
    }else if(d==l-1){
        Nodo<T>* tmp=ultimo;
        ultimo=ultimo->obtenerAnterior();
        ultimo->obtenerSiguiente()->~Nodo();
        free(ultimo->obtenerSiguiente());
        l--;
        return true;
    }else if(d<l){
        Nodo<T>* tmp=primero;
        for(int i=0; i<d; i++){
            tmp=tmp->obtenerSiguiente();
        };
        Nodo<T>* ant=tmp->obtenerAnterior();
        Nodo<T>* sig=tmp->obtenerSiguiente();
        tmp->~Nodo();
        free(tmp);
        ant->vaciarDespues();
        sig->vaciarAntes();
        ant->insertarDespues(sig);
        l--;
        return true;
    }else{
        return false;
    };
};

/** @brief Borra todos los nodos
 *
 */
template<class T> void Lista<T>::borrarTodo(){
    for(int i=0; i<l; i++){
        Nodo<T> *tmp=primero;
        primero=primero->obtenerSiguiente();
        free(tmp);
    };
    l=0;
};

/** Revisa si la lista esta o no vacia
 *
 * @return bool
 */
template<class T> bool Lista<T>::estaVacia(){
    return (len()==0);
};

/** Busca un dato y devuelve el nodo que lo contiene
 *
 * @param T d, dato
 * @return Nodo<T>*
 */
template<class T> Nodo<T> Lista<T>::buscar(T d){
    Nodo<T>* tmp=primero;
    for(int i=0; i<l; i++){
        if(*tmp->obtenerDato()==d){
            return *tmp;
        };
        tmp=tmp->obtenerSiguiente();
    };
    return 0;
};

/** Devuelve el nodo en la posicion que se indique
 *
 * @param int n, posicion
 * @return Nodo<T>*
 */
template<class T> Nodo<T> Lista<T>::posicion(int n){
    if(n<l){
        if(n<l/2){
            Nodo<T>* tmp=primero;
            for(int i=0; i<n; i++){
                tmp=tmp->obtenerSiguiente();
            };
            return *tmp;
        }else{
            Nodo<T>* tmp=ultimo;
            for(int i=l-1; i>n; i--){
                tmp=tmp->obtenerAnterior();
            };
            return *tmp;
        };
    }else{
        return 0;
    };
};

/** Devuelve el dato en la posicion que se indique
 *
 * @param int n, posicion
 * @return T*
 */
template<class T> T Lista<T>::datoPosicion(int n){
    if(n<l){
        if(n<=l/2){
            Nodo<T>* tmp=primero;
            for(int i=0; i<n; i++){
                tmp=tmp->obtenerSiguiente();
            };
            return *(tmp->obtenerDato());
        }else{
            Nodo<T>* tmp=ultimo;
            for(int i=l-1; i>n; i--){
                tmp=tmp->obtenerAnterior();
            };
            return *(tmp->obtenerDato());
        };
    }else{
       // return 0;
    };
};

/** Devuelve la longitud
 *
 * @return int;
 */
template<class T> int Lista<T>::len(){
    return l;
};

/** @brief Imprime la lista
 *
 */
template<class T> void Lista<T>::imprimir(){
    if(len()>0){
        Nodo<T>* tmp=primero;
        for(int i=0; i<len(); i++){
            std::cout<<*(tmp->obtenerDato())<<std::endl;
            tmp=tmp->obtenerSiguiente();
        };
    }else{
        std::cout<<"La lista esta vacia"<<std::endl;
    };
};


#endif // DATASTRUCTURES_H_INCLUDED
