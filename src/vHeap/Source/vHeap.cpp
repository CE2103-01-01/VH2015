//
// Created by alex on 20/03/15.
//


#include "vHeap/Headers/vHeap.h"

using namespace pugi;
/**
 * Constructor reserva espacios de memoria
 */
vHeap::vHeap(){
    std::chrono::high_resolution_clock::time_point debug;
    xml_document doc;
    doc.load_file(Constants::xmlPath);
    overweight = static_cast<float*>(malloc(sizeof(float)));
    *overweight = doc.child(Constants::PROJECT_NAME).child(Constants::V_HEAP).attribute("overweight").as_float();
    vSize = static_cast<long*>(malloc(sizeof(long)));
    *vSize = doc.child(Constants::PROJECT_NAME).child(Constants::V_HEAP).attribute("size").as_int()*1024*1024;
    vDebug = static_cast<bool*>(malloc(sizeof(bool)));
    *vDebug = doc.child(Constants::PROJECT_NAME).child("vDebug").attribute("activo").as_bool();
    mainChunk = malloc(*vSize);
    actualPos = mainChunk;
    initPos = mainChunk;
    finalPos = initPos+*vSize;
    if(getVDebug()) logTime(debug, "Constructor vHeap");
}

/**
 * Libera el espacio ocupado
 */
vHeap::~vHeap(){
    free(vSize);
    free(overweight);
    free(mainChunk);
}

/**
 * Reservar un espacio en memoria, devuelve el int de referencia
 */
unsigned int vHeap::vMalloc(int neededSize) {//Analisis de algoritmos 25T
    //Bloquea memoria
    pthread_mutex_lock(vMetaData::getInstance()->getMutex());
    std::chrono::high_resolution_clock::time_point debug;
    if(getVDebug()) debug = startTime();
    //Revisa si se dispone del espacio requerido
    if((*vSize)+(*vSize)*(*overweight) > (neededSize + vMetaData::getInstance()->getHeapUse())){
        void* positionToUse;
        if(((actualPos + neededSize) < finalPos)){
            //Si el dato cabe en mainChunk, asigna una posicion
            positionToUse = actualPos;
            actualPos += neededSize;
        }else{
            //Si el dato no cabe en mainChunk lo pagina
            vEntry* toPage = vMetaData::getInstance()->searchToPage(neededSize);
            vPager tmp;
            //Baja el dato, notifica a la entrada y toma la posicion
            tmp.pageDown(toPage->getOffSet(),toPage->getIdRef(),toPage->getDataSize());
            positionToUse = toPage->getOffSet();
            toPage->fileDown();
        };
        if(getVDebug()) logTime(debug, "vMalloc");
        //Desbloquea mutex
        pthread_mutex_unlock(vMetaData::getInstance()->getMutex());
        //addEntry devuelve un numero de referencia
        return vMetaData::getInstance()->addEntry(neededSize, positionToUse);
    }else{
        stopRunning(neededSize);
    };
}

/**
 * Reserva y limpia un espacio en memoria, devuelve el int de referencia
 */
unsigned int vHeap::vCalloc(int neededSize) {
    //Realiza un vMalloc
    unsigned int idToReturn = vMalloc(neededSize);
    //Limpia la memoria
    vMetaData::getInstance()->cleanChunk(neededSize,vMetaData::getInstance()->de_vReference(idToReturn));
    //Retorna el id
    return idToReturn;
}


vHeap* vHeap::vHeapSingleton = 0;

/**
 * Se libera la memoria
 */
void vHeap::vFree(unsigned int idRef) {//4T
    pthread_mutex_lock(vMetaData::getInstance()->getMutex());
    vMetaData::getInstance()->removeEntry(idRef);
    pthread_mutex_unlock(vMetaData::getInstance()->getMutex());;
}

/**
 * Singleton para obtener el heap
 */
vHeap *vHeap::getInstance() {
    if(!vHeapSingleton) {
        vHeapSingleton = static_cast<vHeap *>(malloc(sizeof(vHeap)));
        new(vHeapSingleton) vHeap();
    }
    return vHeapSingleton;
 }
/**
 * Se desreferencia un valor y se devuelve el dato
 */
void* vHeap::de_vReference(int id) {//T(7+6i)
    //Llama al metodo de desreferenciar de metadata, el cual devuelve void*
    return vMetaData::getInstance()->de_vReference(id);
}

/**
 * Se disminuye el numer de referencias de un vRef
 */
int vHeap::removeVRef(int idRef) {
    vMetaData::getInstance()->decreaseReference((unsigned int) idRef);
    return 0;
}

/**
 * Aumenta el numero de referencias de un vRef
 */
int vHeap::addVRef(int idRef) {
    vMetaData::getInstance()->increaseReference((unsigned int) idRef);
    return 0;
}

/**
 * Devuelve bandera de debugger
 */
bool vHeap::getVDebug() {
    return *vDebug;
}

/** Devuelve los bytes utilizados
 * return long
 */
long vHeap::getUse(){
    return vMetaData::getInstance()->getHeapUse();
}

/** Cambia la posicion actual
 * @param void* newPos: nueva posicion
 */
void vHeap::setActualPos(void* newPos){
    actualPos = newPos;
}

/** Devuelve el tamano maximo del heap
 * @return int
 */
long vHeap::getSize() {
    return *vSize;
}

/**Devuelve la posicion inicial del main chunk
 * @return void*
 */
void* vHeap::getInitPos(){
    return initPos;
}

/**Devuelve la posicion final del main chunk
 * @return void*
 */
void* vHeap::getFinalPos(){
    return finalPos;
}

/** Detiene la ejecucion si vHeap no tiene espacio
 * @param int neededSize: tamano requerido
 */
void vHeap::stopRunning(int neededSize) {
    std::cout << "vHeap esta lleno" << std::endl;
    std::cout << "Capacidad maxima en Bytes: "<< (*vSize) + (*vSize)*(*overweight) <<std::endl;
    std::cout << "Capacidad utilizada en Bytes: "<< vMetaData::getInstance()->getHeapUse()  << std::endl;
    std::cout << "Capacidad solicitada en Bytes: "<< neededSize << std::endl;
    std::cout << "Se abortara el programa"<< std::endl;
    abort();
}
