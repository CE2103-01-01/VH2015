//
// Created by pablo on 28/03/15.
//


#include "vHeap/Headers/vMetaData.h"

/**
* inicializa valores y crea la lista
*/
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

/**
*Busca un id y aumenta num de Referencias
*/
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

/**
* Busca un id y disminuye num de referencias
*/
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

/**
* en la tabla de memoria agrega una entrada y devuelve una nuevca instancia de vRef
*/
vRef vMetaData::addEntry(int size, std::string type, void *actualPos) {
    memoryTable->append(vEntry(actualID, size, actualPos));
    return vRef(actualID++);
}

/**
* Imprime la metadata
*/
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

/**
* Devuelve la lista de la tabla de memoria
*/
vList<vEntry> *vMetaData::operator!() {
    return memoryTable;
};

/**
* Elimina una entrada de la tabla de momoria
*/
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
