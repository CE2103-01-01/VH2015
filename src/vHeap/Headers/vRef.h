//
// Created by alex on 18/03/15.
//

#ifndef _VH2015_VREF_H_
#define _VH2015_VREF_H_

#include "../libs/vheaplib.h"
#include "../libs/vheaplibpp.h"

template <class T> class vRef;
template <class T> class vRef {
        int referenceID;    //TODO: pasar a int*
    public:
        vRef();
        vRef(int);
        ~vRef();
        T operator *();
        int operator !();
        int operator =(int);
        int operator =(vRef<T>);
        int operator ++();
        int operator --();
};

template<class T> vRef<T>::vRef(int id){
    referenceID=id;
    addVRef(referenceID); // aumenta contador de referencias
};

template<class T> vRef<T>::vRef(){
    referenceID=0;
};

template<class T> vRef<T>::~vRef() {
    removeVRef(referenceID); // disminuye contador de referencias
};

template<class T>int vRef<T>::operator!() {
    return referenceID;
};

template<class T> T vRef<T>::operator*() {
    return *static_cast<T*>(de_vReference(referenceID));
};

template<class T>int vRef<T>::operator=(int id){
    referenceID=id;
    addVRef(referenceID); // aumenta contador de referencias
    return 0;
};

template<class T> int vRef<T>::operator=(vRef other){
    referenceID=!other;
    addVRef(referenceID); // aumenta contador de referencias
    return 0;
};

template<class T> int vRef<T>::operator ++(){
    referenceID++;
    return 0;
};

template<class T> int vRef<T>::operator --(){
    referenceID--;
    return 0;
};

#endif //_VH2015_VREF_H_