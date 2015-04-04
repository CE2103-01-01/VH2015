#include "vHeap/Headers/vRef.h"

template<class T>
vRef<T>::vRef(int id) {
    referenceID = id;
    vHeap::getInstance()->addVRef(referenceID); // aumenta contador de referencias
};

template<class T>
vRef<T>::vRef() {
    referenceID = 0;
};

template<class T>
vRef<T>::~vRef() {
    vHeap::getInstance()->removeVRef(referenceID); // disminuye contador de referencias
};

template<class T>
int vRef<T>::operator!() {
    return referenceID;
};

template<class T>
T vRef<T>::operator*() {
    return *static_cast<T *>(vHeap::getInstance()->de_vReference(referenceID));
};

template<class T>
int vRef<T>::operator=(int id) {
    referenceID = id;
    vHeap::getInstance()->addVRef(referenceID); // aumenta contador de referencias
    return 0;
};

template<class T>
int vRef<T>::operator=(vRef other) {
    if (referenceID)vHeap::getInstance()->removeVRef(referenceID);
    referenceID = !other;
    vHeap::getInstance()->addVRef(referenceID); // aumenta contador de referencias
    return 0;
};

template<class T>
int vRef<T>::operator++() {
    if (referenceID)vHeap::getInstance()->removeVRef(referenceID);
    referenceID++;
    vHeap::getInstance()->addVRef(referenceID);
    return 0;
};

template<class T>
int vRef<T>::operator--() {
    if (referenceID) vHeap::getInstance()->removeVRef(referenceID);
    referenceID--;
    if (referenceID) vHeap::getInstance()->addVRef(referenceID);
    return 0;
};