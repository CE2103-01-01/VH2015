//
// Created by pablo on 28/03/15.
//

#include <vheaplibpp.h>
#include "vHeap/Headers/vMetaData.h"

/**
* inicializa valores y crea el arbol
*/
vMetaData::vMetaData() {
    //Inicializa mutex
    memoryMutex = static_cast<pthread_mutex_t*>(malloc(sizeof(pthread_mutex_t)));
    pthread_mutex_init(memoryMutex, 0);
    //Inicializa id
    actualID = static_cast<unsigned int*>(malloc(sizeof(unsigned int)));
    (*actualID) = initialId;
    //Inicializa arbol de memoria
    memoryTree = static_cast<Tree<vEntry>*>(malloc(sizeof(Tree<vEntry>)));
    new(memoryTree) Tree<vEntry>();
    //Inicializa lista de borrados
    deletedIDS = static_cast<vList<unsigned int> *>(malloc(sizeof(vList<unsigned int>)));
    new(deletedIDS) vList<int>();
    //Inicializa tamano
    vSize = static_cast<long*>(malloc(sizeof(long)));
    (*vSize) = 0;
}

/**
 * Desocupa el espacio
 */
vMetaData::~vMetaData() {
    free(memoryMutex);
    free(memoryTree);
    free(deletedIDS);
    free(vSize);
    free(actualID);
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
    return (int) (*actualID - deletedIDS->len());
}

/**
*Busca un id y aumenta num de Referencias
*/
void vMetaData::increaseReference(unsigned int idRef) {
    try{
        memoryTree->searchElement(idRef)->increaseNumReferences();
    }catch(int e){
        std::cout<< "Error " << e <<std::endl;
    }
}

/**
* Busca un id y disminuye num de referencias
*/
void vMetaData::decreaseReference(unsigned int idRef) {
    try{
        memoryTree->searchElement(idRef)->decreaseNumReferences();
    }catch(int e){
        std::cout<< "Error " << e <<std::endl;
    }
}

/**
* Imprime la metadata
*/
void vMetaData::printMetaData() {
    std::cout << "--Begin MetaData info--" << std::endl;
    for(int i=0; i < *actualID; i++){
        vEntry *m = memoryTree->searchElement(i);
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
    try{
        vEntry *entry = memoryTree->searchElement(idRef);
        (*vSize) -= entry->getDataSize();
        memoryTree->deleteElement(idRef,setDefault,0);
        deletedIDS->append((unsigned int) idRef);
    }catch(int e){
        std::cout<< "Error " << e <<std::endl;
    }
}

/**
* en la tabla de memoria agrega una entrada y devuelve un int de la posicion
*/
unsigned int vMetaData::addEntry(int dataSize, void *actualPos) {
    try{
        (*vSize)+=dataSize;
        if (deletedIDS->len() == 0) {
            //Si no hay ids reutilizables utiliza el actual y lo retorna
            memoryTree->insertElement(vEntry((*actualID), dataSize, actualPos),(*actualID));
            return (*actualID)++;
        } else {
            //Si hay ids reutilizables lo utiliza utiliza el primero de la lista de borrados
            int id = *(deletedIDS->get(0));
            //Actualiza la lista
            deletedIDS->deleteNode(0);
            //Inserta la entrada y retorna el nuevo id
            memoryTree->insertElement(vEntry(id, dataSize, actualPos),id);
            return (unsigned int) id;
        }
    }catch(int e){
        std::cout<< "Error " << e <<std::endl;
    }
}

/**
 * Llena un chunk de memoria con ceros
 */
void vMetaData::cleanChunk(int chunkSize, void* chunk){
    try{
        //Bloquea el mutex
        pthread_mutex_lock(memoryMutex);
        //Itera byte a byte y lo coloca en 0
        for(int i = 0; i < chunkSize; i++) *static_cast<unsigned char*>(chunk + i) = 0;
        //Desbloquea el mutex
        pthread_mutex_unlock(memoryMutex);
    }catch(int e){
        std::cout<< "Error " << e <<std::endl;
    }
}

/** Singleton
 */
vMetaData *vMetaData::vMDSingleton = 0;

/**
 * Metodo singleton
 */
vMetaData* vMetaData::getInstance() {
    try{
        if (vMDSingleton == 0) {
            vMDSingleton = static_cast<vMetaData*>(malloc(sizeof(vMetaData)));
            new(vMDSingleton) vMetaData();
        }
        return vMDSingleton;
    }catch(int e){
        std::cout<< "Error " << e <<std::endl;
        abort();
    }
}

/**
 * Busca la entrada con el id indicado y extrae el dato, si esta paginada la sube
 */
void* vMetaData::de_vReference(int id) {
    try{
        std::chrono::high_resolution_clock::time_point debug;
        if(getVDebug()) debug = startTime();
        std::chrono::high_resolution_clock::time_point test;
        //Bloquea la memoria
        pthread_mutex_lock(memoryMutex);
        //Busca la entrada
        vEntry* entry = memoryTree->searchElement(id);
        //cambia si bandera de uso
        entry->changeFlag();
        if(!(entry->isOnHeap())){
            //Si el dato esta paginado busca una pagina adecuada
            int sizeOfEntry = entry->getDataSize();
            vEntry* toPage = searchToPage(sizeOfEntry);
            //Pagina la pagina adecuada y se toma su direccion
            vPager tmp;
            tmp.pageDown(toPage->getOffSet(),toPage->getIdRef(),toPage->getDataSize());
            void* content = toPage->getOffSet();
            //Notifica a la entrada que se bajo la pagina
            toPage->fileDown();
            //Se sube la pagina y se notifica a la entrada
            tmp.pageUp(content,toPage->getIdRef());
            entry->fileUp(content);
        };
        //Desbloquea el mutex
        pthread_mutex_unlock(memoryMutex);
        entry->changeFlag();
        if(getVDebug()) logTime(debug, "deReference");
        //Evita error
        if(entry->getOffSet() == 0){
            std::cout << "Error, ha desreferenciado un dato nulo" << std::endl;
            abort();
        }
        //Se obtiene la direccion de memoria y se retorna
        return entry->getOffSet();
    }catch(int e){
        std::cout<< "Error " << e <<std::endl;
        abort();
    }
}

/** @return pthread_mutex_t*: variable mutex de memoria
 */
pthread_mutex_t* vMetaData::getMutex(){
    return memoryMutex;
}

/* @brief busca una elemento para paginar
 * return vEntry*: el elemento
 */
vEntry* vMetaData::searchToPage(int sizeParam){
    //Itera sobre los elementos del arbol
    for(int i=1; i<memoryTree->max(); i++){
        try{
            //Busca una entrada
            vEntry* entry = memoryTree->searchElement(i);
            //Comprueba si existe y el tamano es adecuado
            if(entry->getOffSet()!=0 && entry->getDataSize() >= sizeParam){
                return entry;
            }
        }catch(int e){
            //Si ocurre un error continua
            std::cout << "Error " << e << " en paginacion"<< std::endl;
            continue;
        }
    }
    std::cout << "Error en paginacion, no hay datos en memoria con tamano adecuado para subir el requerido"<< std::endl;
    std::cout << "Se abortara el programa"<< std::endl;
    abort();
}

/** Uso de heap
 * return int: bytes en uso
 */
long vMetaData::getHeapUse(){
    return *vSize;
}