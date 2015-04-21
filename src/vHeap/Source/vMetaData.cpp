//
// Created by pablo on 28/03/15.
//

#include <vheaplibpp.h>
#include "vHeap/Headers/vMetaData.h"

/**
* inicializa valores y crea el arbol
*/
vMetaData::vMetaData() {
    memoryMutex = static_cast<pthread_mutex_t*>(malloc(sizeof(pthread_mutex_t)));
    pthread_mutex_init(memoryMutex, 0);

    dfragCond = static_cast<pthread_cond_t*>(malloc(sizeof(pthread_cond_t)));
    pthread_cond_init(dfragCond, 0);

    actualID = initialId;

    memoryTree = static_cast<Tree<vEntry>*>(malloc(sizeof(Tree<vEntry>)));
    new(memoryTree) Tree<vEntry>();

    deletedIDS = static_cast<vList<unsigned int> *>(malloc(sizeof(vList<unsigned int>)));
    new(deletedIDS) vList<int>();

    vSize = 0;
}

/**
 * Desocupa el espacio
 */
vMetaData::~vMetaData() {
    free(memoryTree);
    free(deletedIDS);
}

/**
 * Devuelve el arbol de memoria
 */
Tree<vEntry>* vMetaData::getMemoryTree() {
    return memoryTree;
}

/**
 * Devuelve la cantidad de datos en heap
 */
int vMetaData::len() {
    return (int) (actualID - deletedIDS->len());
}

/**
*Busca un id y aumenta num de Referencias
*/
void vMetaData::increaseReference(unsigned int idRef) {
    (static_cast<vEntry*>(memoryTree->searchElement(idRef)))->increaseNumReferences();
}

/**
* Busca un id y disminuye num de referencias
*/
void vMetaData::decreaseReference(unsigned int idRef) {
    (static_cast<vEntry*>(memoryTree->searchElement(idRef)))->decreaseNumReferences();
}

/**
* Imprime la metadata
*/
void vMetaData::printMetaData() {
    std::cout << "--Begin MetaData info--" << std::endl;
    for(int i=0;i<actualID;i++){
        vEntry *m = static_cast<vEntry*>(memoryTree->searchElement(i));
        std::cout <<
        "ID: " << m->getIdRef() <<
        " Size: " << m->getDataSize() <<
        " offset: " << m->getOffSet() <<

        std::endl;

    }
    std::cout << "---End MetaData info---" << std::endl;
}

/**
* Elimina una entrada de la tabla de momoria
*/
void vMetaData::removeEntry(int idRef) {
    vEntry *entry = static_cast<vEntry*>(memoryTree->searchElement(idRef));
    vSize -= entry->getDataSize();
    memoryTree->deleteElement(idRef,setDefault);
    deletedIDS->append((unsigned int) idRef);
}

/**
* en la tabla de memoria agrega una entrada y devuelve un int de la posicion
*/
unsigned int vMetaData::addEntry(int dataSize, void *actualPos) {
    vSize+=dataSize;
    if (deletedIDS->len() == 0) {
        memoryTree->insertElement(vEntry(actualID, dataSize, actualPos),actualID);
        return actualID++;
    } else {
        int id = *(deletedIDS->get(0));
        deletedIDS->deleteNode(0);
        memoryTree->insertElement(vEntry(id, dataSize, actualPos),id);
        return (unsigned int) id;
    };
}

/**
 * Llena un chunk de memoria con ceros
 */
void vMetaData::cleanChunk(int chunkSize, void* chunk){
    int counter = 0;
    do{
        *static_cast<char*>(chunk + counter) = 0;
        counter++;
    }while(counter < chunkSize);
}

/** Singleton
 */
vMetaData *vMetaData::vMDSingleton = 0;

/**
 * Metodo singleton
 */
vMetaData* vMetaData::getInstance() {
    if (vMDSingleton == nullptr) {
        vMDSingleton = static_cast<vMetaData*>(malloc(sizeof(vMetaData)));
        new(vMDSingleton) vMetaData();
    }
    return vMDSingleton;
}

/**
 * Busca la entrada con el id indicado y extrae el dato, si esta paginada la sube
 */
void* vMetaData::de_vReference(int id) {
    std::chrono::high_resolution_clock::time_point debug;
    //cout<<"------------------"<<endl;
    if(getVDebug()) debug = startTime();
    //test = startTime();
    //printTime(test);
    std::chrono::high_resolution_clock::time_point test;

    pthread_mutex_lock(memoryMutex);
    printTime(test);
    test = startTime();
    vEntry* entry = (static_cast<vEntry*>(memoryTree->searchElement(id)));
    entry->changeFlag();
    if(!entry->isOnHeap()){
        vEntry* toPage = searchToPage(entry->getDataSize());
        vPager a;
        a.pageUp(toPage->getOffSet(),toPage->getIdRef(),toPage->getDataSize());
        void* content = toPage->getOffSet();
        toPage->fileDown();
        a.pageUp(content,toPage->getIdRef(),toPage->getDataSize());
        entry->fileUp(content);
    };
    pthread_mutex_unlock(memoryMutex);

    if(getVDebug()) logTime(debug, "deReference");
    return entry->getOffSet();
}

/** @return pthread_mutex_t*: variable mutex de memoria
 */
pthread_mutex_t* vMetaData::getMutex(){
    return memoryMutex;
}

/** @return pthread_cond_t*: variable de condicion de desfragmentador
 */
pthread_cond_t* vMetaData::getDefragmenterCond(){
    return dfragCond;
}

/* @brief busca una elemento para paginar
 * return vEntry*: el elemento
 */
vEntry* vMetaData::searchToPage(int s){
    pthread_mutex_lock(memoryMutex);
    for(int i=1; i<memoryTree->max(); i++){
        try{
            vEntry* entry = (static_cast<vEntry*>(memoryTree->searchElement(i)));
            if(!entry->getUseFlag() & entry->getDataSize()>s){
                pthread_mutex_unlock(memoryMutex);
                return entry;
            };
        }catch(int e){}
    }
    pthread_mutex_unlock(memoryMutex);
    return 0;
}

/** Uso de heap
 * return int: bytes en uso
 */
int vMetaData::getHeapUse(){
    return vSize;
}