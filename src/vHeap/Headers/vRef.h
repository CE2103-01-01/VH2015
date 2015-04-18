//
// Created by alex on 18/03/15.
//

#ifndef _VH2015_VREF_H_
#define _VH2015_VREF_H_


#include "vMetaData.h"
#include <chrono>

template <class T> class vRef {
        int referenceID;
    public:
        vRef();

    vRef(const vRef<T> &obj);
        vRef(int);
        ~vRef();
        T* operator *();
        int operator !();
        int operator =(int);
        int operator =(vRef<T>);
        bool operator ==(vRef<T>);
        int operator ++();
        int operator --();
};

template<class T>
vRef<T>::vRef(const vRef<T> &obj) {
    referenceID = obj.referenceID;
    vMetaData::getInstance()->increaseReference((unsigned int) obj.referenceID);
}

template<class T>
vRef<T>::vRef(int id) {
    referenceID = id;
    vMetaData::getInstance()->increaseReference((unsigned int) referenceID); // aumenta contador de referencias
};

template<class T>
vRef<T>::vRef() {
    referenceID = 0;

};

template<class T>
vRef<T>::~vRef() {
    vMetaData::getInstance()->decreaseReference((unsigned int) referenceID); // disminuye contador de referencias
};

template<class T>
int vRef<T>::operator!() {
    return referenceID;
};

template<class T>
T* vRef<T>::operator*() {

    return static_cast<T *>(vMetaData::getInstance()->de_vReference(referenceID));
};

template<class T>
int vRef<T>::operator=(int id) {
    if (referenceID)vMetaData::getInstance()->decreaseReference((unsigned int) referenceID);
    referenceID = id;
    vMetaData::getInstance()->increaseReference((unsigned int) referenceID); // aumenta contador de referencias
    return 0;
};

template<class T>
int vRef<T>::operator=(vRef other) {
    if (referenceID)vMetaData::getInstance()->decreaseReference((unsigned int) referenceID);
    referenceID = !other;
    vMetaData::getInstance()->increaseReference((unsigned int) referenceID); // aumenta contador de referencias
    return 0;
};

template<class T>
bool vRef<T>::operator==(vRef other) {
    return referenceID == !other;
};

template<class T>
int vRef<T>::operator++() {
    if (referenceID)vMetaData::getInstance()->decreaseReference((unsigned int) referenceID);
    referenceID++;
    vMetaData::getInstance()->increaseReference((unsigned int) referenceID);
    return 0;
};

template<class T>
int vRef<T>::operator--() {
    if (referenceID) vMetaData::getInstance()->decreaseReference((unsigned int) referenceID);
    referenceID--;
    if (referenceID) vMetaData::getInstance()->increaseReference((unsigned int) referenceID);
    return 0;
};

#endif //_VH2015_VREF_H_vRef::vRef(const vRef& obj){




