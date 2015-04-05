//
// Created by pablo on 28/03/15.
//


#include "vHeap/Headers/vMetaData.h"

/**
* inicializa valores y crea la lista
*/
vMetaData::vMetaData() {
    pthread_mutex_init(memoryMutex,0);
    actualID = initialId;
    memoryTable = static_cast<vList<vEntry>*>(malloc(sizeof(vList<vEntry>)));
    new(memoryTable) vList<vEntry>();
    deletedIDS = static_cast<vList<unsigned int> *>(malloc(sizeof(vList<unsigned int>)));
    new(deletedIDS) vList<int>();
}

vMetaData::~vMetaData() {

}

vList<vEntry> *vMetaData::getMemoryTable() {
    return memoryTable;
}

int vMetaData::len() {
    return actualID - deletedIDS->len();
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
            deletedIDS->append(idRef);
            break;
        }
    }
}

/**
* en la tabla de memoria agrega una entrada y devuelve un int de la posicion
*/
unsigned int vMetaData::addEntry(int size, void *actualPos) {
    if (deletedIDS->len() == 0) {
        vEntry e = vEntry(actualID, size, actualPos);
        memoryTable->append(e);
        return actualID++;
    } else {
        int id = *(deletedIDS->get(0));
        deletedIDS->deleteNode(0);
        vEntry e = vEntry(id, size, actualPos);
        memoryTable->append(e);
        return id;
    };
}

vMetaData* vMetaData::getInstance() {
    if(!single) {
        single = static_cast<vMetaData*>(malloc(sizeof(vMetaData)));
        new(single) vMetaData();
    }
    return single;
}

void* vMetaData::de_vReference(int id) {
    pthread_mutex_lock(memoryMutex);

    vListIterator<vEntry> *iter = memoryTable->getIterator();

    while(iter->exists()){
        vEntry* entry = iter->next();
        if(!*entry==id){
            pthread_mutex_unlock(memoryMutex);
            return &*entry;
        };
    };
    pthread_mutex_unlock(memoryMutex);
    return 0;
};

pthread_mutex_t* vMetaData::getMutex(){
    return memoryMutex;
};