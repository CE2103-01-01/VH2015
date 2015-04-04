//
// Created by pablo on 31/03/15.
//

#include "vHeap/Headers/vEntry.h"

vEntry::vEntry(int pIdRef, int pDataSize, void *pOffset) {
    idRef = pIdRef;
    dataSize = pDataSize;
    offset = pOffset;
}

void *vEntry::getOffSet() {
    return offset;
}

int vEntry::getDataSize() {
    return dataSize;
}

bool vEntry::getUseFlag() {
    return useFlag;
}

int vEntry::getIdRef() {
    return idRef;
}

/**
* Constructor pone en 1 el numero de referencias
*/
vEntry::vEntry() {
    numReferences = 1;
}

void *vEntry::operator&() {
    return offset;
};

int vEntry::operator!() {
    return idRef;
};

void vEntry::changeFlag() {
    if (useFlag) {
        useFlag = false;
    }
    else {
        useFlag = true;
    }
}

unsigned int vEntry::getNumReferences() {
    return numReferences;
}

/**
* Hace una disminucion en 1 al numero de referencias de una entrada
* LLama al garbage collector si el numero es igual a 0.
*/
void vEntry::decreaseNumReferences() {
    numReferences--;
    if (numReferences == 0) {
        vGarbageCollector::deallocate(idRef);
        vGarbageCollector::startDump();
    }
}

/**
Aumenta en 1 al numero de referencias de una entrada
**/
void vEntry::increaseNumReferences() {
    numReferences++;
}

int vEntry::operator[](int var){
    idRef = var;
    return 0;
};

int vEntry::operator[](void* var){
    var=realloc(var,dataSize);
    var=memcpy(var,offset,dataSize);
    offset=var;
    return 0;
};