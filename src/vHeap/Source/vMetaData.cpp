//
// Created by pablo on 28/03/15.
//


#include "vHeap/Headers/vMetaData.h"


vMetaData::vMetaData() {
    actualID = 0;
    memoryTable = static_cast<vList<vEntry> *>(malloc(sizeof(vList<vEntry>)));
    new(memoryTable) vList<vEntry>();
}

vMetaData::~vMetaData() {

}

vList<vEntry> *vMetaData::getMemoryTable() {
    return memoryTable;
}

int vMetaData::len() {
    return actualID;
}

void vMetaData::increaseReference(unsigned int idRef) {
    vListIterator<vEntry> *i = memoryTable->getIterator();
    while (i->exists()) {
        vEntry *next = i->next();
        if (next->getIdRef() == idRef) {
            next->increaseNumReferences();
            break;
        }
    }
}

void vMetaData::decreaseReference(unsigned int idRef) {
    vListIterator<vEntry> *i = memoryTable->getIterator();
    while (i->exists()) {
        vEntry *next = i->next();
        if (next->getIdRef() == idRef) {
            next->decreaseNumReferences();
            break;
        }
    }
}

vRef vMetaData::addEntry(int size, std::string type, void *actualPos) {
    memoryTable->append(vEntry(actualID, size, actualPos));
    return vRef(actualID++);
}


void vMetaData::printMetaData() {
    vListIterator<vEntry> *iter = memoryTable->getIterator();
    std::cout << "--Begin MetaData info--" << std::endl;
    while (iter->exists()) {
        vEntry *m = iter->next();
        std::cout <<
        "ID: " << m->getIdRef() <<
        " Size: " << m->getDataSize() <<
        " offset: " << m->getOffSet() <<

        std::endl;

    }
    std::cout << "---End MetaData info---" << std::endl;
}


vList<vEntry> *vMetaData::operator!() {
    return memoryTable;
};

void vMetaData::removeEntry(int idRef) {
    vListIterator<vEntry> *i = memoryTable->getIterator();
    while (i->exists()) {
        vEntry *next = i->next();
        if (next->getIdRef() == idRef) {
            memoryTable->deleteNode(i->getPosition() - 1);
            break;
        }
    }
}
