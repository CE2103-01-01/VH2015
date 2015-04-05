//
// Created by roberto on 05/04/15.
//

#include "vHeap/Headers/vRef.h"

vRef::vRef(int id) {
    referenceID = id;
    vMetaData::getInstance()->increaseReference(referenceID); // aumenta contador de referencias
};


 vRef::vRef() {
    referenceID = 0;
};


 vRef::~vRef() {
    vMetaData::getInstance()->decreaseReference(referenceID); // disminuye contador de referencias
};


int  vRef::operator!() {
    return referenceID;
};


vObject  vRef::operator*() {
    return *static_cast<vObject *>(vMetaData::getInstance()->de_vReference(referenceID));
};


int  vRef::operator=(int id) {
    if (referenceID)vMetaData::getInstance()->decreaseReference(referenceID);
    referenceID = id;
    vMetaData::getInstance()->increaseReference(referenceID); // aumenta contador de referencias
    return 0;
};


int  vRef::operator=(vRef other) {
    if (referenceID)vMetaData::getInstance()->decreaseReference(referenceID);
    referenceID = !other;
    vMetaData::getInstance()->increaseReference(referenceID); // aumenta contador de referencias
    return 0;
};


int  vRef::operator++() {
    if (referenceID)vMetaData::getInstance()->decreaseReference(referenceID);
    referenceID++;
    vMetaData::getInstance()->increaseReference(referenceID);
    return 0;
};


int  vRef::operator--() {
    if (referenceID) vMetaData::getInstance()->decreaseReference(referenceID);
    referenceID--;
    if (referenceID) vMetaData::getInstance()->increaseReference(referenceID);
    return 0;
};