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
    *overweight = doc.child("VH2015").child("vHeap").attribute("overweight").as_float();
    vSize = static_cast<int*>(malloc(sizeof(int)));
    *vSize = doc.child("VH2015").child("vHeap").attribute("size").as_int() *1024*1024;
    vDebug = static_cast<bool*>(malloc(sizeof(bool)));
    *vDebug = doc.child("VH2015").child("vDebug").attribute("activo").as_bool();
    mainChunk = malloc((size_t) (*vSize));
    actualPos = mainChunk;
    initPos = mainChunk;
    finalPos = initPos+*vSize;

    metaData = vMetaData::getInstance();
    memoryMutex = metaData->getMutex();

    dmp = malloc(sizeof(Dump));
    new(static_cast<Dump*>(dmp)) Dump();
    pthread_create(&dumpThread,NULL,dump,dmp);

    if(getVDebug()) logTime(debug, "Constructor vHeap");
};

/**
 * Libera el espacio ocupado
 */
vHeap::~vHeap(){
    free(dfrag);
    free(vDebug);
    free(overweight);
    free(mainChunk);
    free(dumpFrecuency);
};

/**
 * Reservar un espacio en memoria, devuelve el int de referencia
 */
unsigned int vHeap::vMalloc(int sz) {//Analisis de algoritmos 25T
    pthread_mutex_lock(memoryMutex);
    std::chrono::high_resolution_clock::time_point debug;
    if(getVDebug()) debug = startTime();
    if((*vSize)*(*overweight) > metaData->getHeapUse()){
        void* pos;
        if(actualPos + sz < finalPos){
            pos = actualPos;
            actualPos += sz;
        }else{
            vEntry* toPage = metaData->searchToPage(sz);
            vPager a;
            a.pageDown(toPage->getOffSet(),toPage->getIdRef(),toPage->getDataSize());
            pos = toPage->getOffSet();
            toPage->fileDown();
        };
        if(getVDebug()) logTime(debug, "vMalloc");
        pthread_mutex_unlock(memoryMutex);
        return metaData->addEntry(sz, pos); //addEntry devuelve un numero de referencia
    }else{
        std::cout << "Error, vHeap lleno" << std::endl;
        if(getVDebug()) logTime(debug, "vMalloc");
        pthread_mutex_unlock(memoryMutex);
        return 0;
    };
};

vHeap* vHeap::vHeapSingleton = 0;

/**
 * Se libera la memoria
 */
void vHeap::vFree(unsigned int idRef) {//4T
    pthread_mutex_lock(memoryMutex);
    metaData->removeEntry(idRef);
    pthread_mutex_unlock(memoryMutex);;
}

/**
 * Accede a la metadada
 */
vMetaData *vHeap::getMetaData() {
    return metaData;
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
void *vHeap::de_vReference(int id) {//T(7+6i)
   pthread_mutex_lock(memoryMutex);
    std::chrono::high_resolution_clock::time_point debug;
    if(getVDebug()) debug = startTime();
    metaData->de_vReference(id);
    pthread_mutex_unlock(memoryMutex);
    if(getVDebug()) logTime(debug, "vdeReference");
    return 0;
};

/**
 * Se disminuye el numer de referencias de un vRef
 */
int vHeap::removeVRef(int idRef) {
    metaData->decreaseReference((unsigned int) idRef);
    return 0;
};

/**
 * Aumenta el numero de referencias de un vRef
 */
int vHeap::addVRef(int idRef) {
    metaData->increaseReference((unsigned int) idRef);
    return 0;
};

/**
 * Devuelve bandera de debugger
 */
bool vHeap::getVDebug() {
    return *vDebug;
}
