//
// Created by pablo on 28/03/15.
//

#include "vHeap/Headers/vMetaData.h"

/**
* inicializa valores y crea la lista
*/
vMetaData::vMetaData() {
    memoryMutex = static_cast<pthread_mutex_t*>(malloc(sizeof(pthread_mutex_t)));
    pthread_mutex_init(memoryMutex, 0);

    dfragCond = static_cast<pthread_cond_t*>(malloc(sizeof(pthread_cond_t)));
    pthread_cond_init(dfragCond, 0);

    actualID = initialId;

    memoryTable = static_cast<vList<vEntry>*>(malloc(sizeof(vList<vEntry>)));
    new(memoryTable) vList<vEntry>();

    deletedIDS = static_cast<vList<unsigned int> *>(malloc(sizeof(vList<unsigned int>)));
    new(deletedIDS) vList<int>();

    vSize = 0;
}

vMetaData::~vMetaData() {

}

vList<vEntry> *vMetaData::getMemoryTable() {
    return memoryTable;
}

int vMetaData::len() {
    return actualID - deletedIDS->len();
};

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
};

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
};

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
};

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
        vEntry *actual = i->next();
        if (actual->getIdRef() == idRef) {
            vSize -= actual->getDataSize();
            if(actual->isOnHeap()==false){  //Dato paginado
                std::string path = actual->getPath();
                int l = path.length();
                char* arr = static_cast<char*>(malloc(sizeof(char) * l));
                for(int i=0; i<l; i++){
                    *(arr+i) = static_cast<char>(path[i]);
                };
                const char* cArr = arr;
                remove(cArr);
            }else{
                cleanChunk(actual->getDataSize(),&*actual);
            };
            memoryTable->deleteNode(i->getPosition() - 1);
            deletedIDS->append(idRef);
            break;
        }
    }
    pthread_cond_signal(dfragCond);
};

/**
* en la tabla de memoria agrega una entrada y devuelve un int de la posicion
*/
unsigned int vMetaData::addEntry(int dataSize, void *actualPos) {
    if(actualPos!=0){
        cleanChunk(dataSize,actualPos);
    };
    vSize+=dataSize;
    if (deletedIDS->len() == 0) {
        vEntry* e = static_cast<vEntry*>(malloc(sizeof(vEntry)));
        new (e) vEntry(actualID, dataSize, actualPos);
        memoryTable->append(e);
        return actualID++;
    } else {
        int id = *(deletedIDS->get(0));
        deletedIDS->deleteNode(0);
        vEntry e = vEntry(id, dataSize, actualPos);
        memoryTable->append(e);
        return id;
    };
};

void vMetaData::cleanChunk(int chunkSize, void* chunk){
    int counter = 0;
    do{
        *static_cast<char*>(chunk + counter) = 0;
        counter++;
    }while(counter < chunkSize);
};
vMetaData *vMetaData::vMDSingleton = 0;
vMetaData* vMetaData::getInstance() {
    if (vMDSingleton == nullptr) {
        vMDSingleton = static_cast<vMetaData*>(malloc(sizeof(vMetaData)));
        new(vMDSingleton) vMetaData();
    }
    return vMDSingleton;
};

void* vMetaData::de_vReference(int id) {
    pthread_mutex_lock(memoryMutex);
    vListIterator<vEntry> *iter = memoryTable->getIterator();

    while(iter->exists()){
        vEntry* entry = iter->next();
        std::cout<<"ID metadato "<<!*entry<<"  ID buscado "<<id<<std::endl;
        if(!*entry==id){
            std::cout<<"Se encuentra"<<std::endl;
            entry->changeFlag();
            if(entry->isOnHeap() == false){
                vEntry* toPage = searchToPage(entry->getDataSize());
                std::string downPath = pager->pageDown(&*toPage,!*toPage,toPage->getDataSize());
                void* content = &*toPage;
                toPage->fileDown(downPath);
                pager->pageUp(entry->getPath(),entry->getDataSize(),content);
                entry->fileUp(content);
            };
            pthread_mutex_unlock(memoryMutex);
            return entry->getOffSet();
        };
    };
    std::cout<<"No se encuentra"<<std::endl;
    pthread_mutex_unlock(memoryMutex);
    return 0;
};

pthread_mutex_t* vMetaData::getMutex(){
    return memoryMutex;
};

pthread_cond_t* vMetaData::getDefragmenterCond(){
    return dfragCond;
};

vEntry* vMetaData::searchToPage(int s){
    pthread_mutex_lock(memoryMutex);

    vListIterator<vEntry> *iter = memoryTable->getIterator();

    while(iter->exists()){
        vEntry* entry = iter->next();
        if(entry->getUseFlag()==false & entry->getDataSize()>s){
            pthread_mutex_unlock(memoryMutex);
            return entry;
        };
    };
    pthread_mutex_unlock(memoryMutex);
    return 0;
};

int vMetaData::getHeapUse(){
    return vSize;
};

void vMetaData::setPager(vPager* p){
    pager=p;
};