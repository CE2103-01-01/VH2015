//
// Created by pablo on 28/03/15.
//

#include "vMallocMetaData.h"


vMallocMetaData::vMallocMetaData() {
    memoryTable=static_cast<List<vMallocMDEntry>*>(malloc(sizeof(List<vMallocMDEntry>)));
    new(memoryTable) List<vMallocMDEntry>();
}

vMallocMetaData::~vMallocMetaData()
{

}

int vMallocMetaData::len() {
    return counter;
}

void vMallocMetaData::increaseCounter() {
    counter++;
}
void vMallocMetaData::decreaseCounter() {
    counter--;
}

vRef vMallocMetaData::addEntry(int size, std::string type, void *actualPos) {

    memoryTable->append(vMallocMDEntry(actualID++,size,actualPos));
    counter++;
    return vRef(actualID);
}

vMallocMDEntry::vMallocMDEntry(int idRef, int dataSize, void *offset) : dataSize(dataSize),
                                                                                           idRef(idRef), offset(offset)
{



}

void vMallocMetaData::printMetaData() {
    ListIterator<vMallocMDEntry>* iter = memoryTable->getIterator();
    while(iter->exists()) {
        vMallocMDEntry *m = iter->next();
        std::cout <<
        "ID: " << m->getIdRef() <<
        "Size: " << m->getDataSize() <<
      //  "Type: " << m->getType() <<
        std::endl;
    }
}

int vMallocMDEntry::getIdRef() {
    return idRef;
}

void *vMallocMDEntry::getOffSet() {
    return offset;
}


int vMallocMDEntry::getDataSize() {
    return dataSize;
}

bool vMallocMDEntry::getUseFlag() {
    return useFlag;
}
