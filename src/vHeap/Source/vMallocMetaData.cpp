//
// Created by pablo on 28/03/15.
//


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

void vMallocMetaData::increaseReference(unsigned int idRef) {
    vListIterator<vMallocMDEntry> *i = memoryTable->getIterator();
    while (i->exists()) {
        if (i->next()->getIdRef() == idRef) {
            i->next()->increaseNumReferences();
            break;
        }
    }
}

void vMallocMetaData::decreaseReference(unsigned int idRef) {
    vListIterator<vMallocMDEntry> *i = memoryTable->getIterator();
    while (i->exists()) {
        if (i->next()->getIdRef() == idRef) {
            i->next()->decreaseNumReferences();
            break;
        }
    }
}

vRef vMallocMetaData::addEntry(int size, std::string type, void *actualPos) {
    memoryTable->append(vMallocMDEntry(actualID,size,actualPos));
    return vRef(actualID++);
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




vList <vMallocMDEntry>* vMallocMetaData::operator !(){
    return memoryTable;
};
