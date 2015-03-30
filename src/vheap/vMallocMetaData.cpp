//
// Created by pablo on 28/03/15.
//

#include <vTypes/vList.h>
#include "vMallocMetaData.h"


vMallocMetaData::vMallocMetaData() {
    memoryTable = static_cast<vList<vMallocMDEntry> *>(malloc(sizeof(vList<vMallocMDEntry>)));
    new(memoryTable) vList<vMallocMDEntry>();
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

vMallocMDEntry::vMallocMDEntry(int pIdRef, int pDataSize, void *pOffset)
{
    idRef = pIdRef;
    size_t a = typeid(1).hash_code();

    dataSize = pDataSize;
    offset = pOffset;
}

void vMallocMetaData::printMetaData() {
    vListIterator<vMallocMDEntry> *iter = memoryTable->getIterator();
    std::cout <<"--Begin MetaData info--"<<std::endl;
    while(iter->exists()) {
        vMallocMDEntry *m = iter->next();
        std::cout <<
                "ID: " << m->getIdRef() <<
                " Size: " << m->getDataSize() <<

        std::endl;

    }
    std::cout <<"---End MetaData info---"<<std::endl;
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

int vMallocMDEntry::getIdRef() {
    return idRef;
}

vMallocMDEntry::vMallocMDEntry() {

}
