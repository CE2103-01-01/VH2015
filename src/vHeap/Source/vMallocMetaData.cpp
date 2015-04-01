//
// Created by pablo on 28/03/15.
//

#include <vTypes/Headers/vList.h>
#include "vHeap/Headers/vMallocMetaData.h"


vMallocMetaData::vMallocMetaData() {
    actualID = 0;
    memoryTable = static_cast<vList<vMallocMDEntry> *>(malloc(sizeof(vList<vMallocMDEntry>)));
    new(memoryTable) vList<vMallocMDEntry>();
}

vMallocMetaData::~vMallocMetaData()
{

}
vList <vMallocMDEntry>* vMallocMetaData::getMemoryTable() {
    return memoryTable;
}

int vMallocMetaData::len() {
    return actualID;
}

void vMallocMetaData::increaseCounter() {
    actualID++;
}
void vMallocMetaData::decreaseCounter() {
    actualID--;
}

vRef vMallocMetaData::addEntry(int size, std::string type, void *actualPos) {
    memoryTable->append(vMallocMDEntry(actualID,size,actualPos));
    return vRef(actualID++);
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
                " offset: "<<m->getOffSet() <<

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

vList <vMallocMDEntry>* vMallocMetaData::operator !(){
    return memoryTable;
};

void* vMallocMDEntry::operator &(){
    return offset;
};

int vMallocMDEntry::operator !(){
    return idRef;
};
void vMallocMDEntry::changeFlag() {
    if(useFlag){
        useFlag=false;
    }
    else{
        useFlag=true;
    }
}