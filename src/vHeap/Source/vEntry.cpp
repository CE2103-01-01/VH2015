//
// Created by pablo on 31/03/15.
//

#include "vHeap/Headers/vEntry.h"


/**
* Constructor pone en 1 el numero de referencias
*/
vEntry::vEntry() {
    numReferences = 1;
}

vEntry::vEntry(int pIdRef, int pDataSize, void *pOffset) {
    idRef = (unsigned int) pIdRef;
    dataSize = (unsigned int) pDataSize;
    offset = pOffset;
    onHeap = true;
}

vEntry::vEntry(int pIdRef, int pDataSize, void *pOffset, bool oH) {
    idRef = (unsigned int) pIdRef;
    dataSize = (unsigned int) pDataSize;
    offset = pOffset;
    onHeap = oH;
}

void vEntry::fileDown(){
    onHeap = false;
    offset = 0;
};

void vEntry::fileUp(void* content){
    onHeap = true;
    offset = content;
};

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

void vEntry::changeFlag() {
    useFlag = !useFlag;
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
    }
}

/**
Aumenta en 1 al numero de referencias de una entrada
**/
void vEntry::increaseNumReferences() {
    numReferences++;
}

bool vEntry::isOnHeap(){
    return onHeap;
};

void vEntry::setOffset(void* p){
    for(int i = 0; i<dataSize; i++){
        *static_cast<char*>(p+i) = *static_cast<char*>(offset+i);
    }
    offset = p;
};

void vEntry::setNumRef(int p){
    numReferences=0;
};

void vEntry::setID(int p){
    idRef=p;
};

void vEntry::setDefault(){
    if(!(onHeap)){
        vPager a;
        a.deletePage(idRef);
    };
    idRef=0;
    numReferences=0;
    offset=0;
    onHeap=false;
};

void setDefault(vEntry* entry){
    entry->setDefault();
};