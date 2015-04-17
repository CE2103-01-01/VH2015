//
// Created by alex on 20/03/15.
//

#include <vheaplibpp.h>
#include "vHeap/Headers/vHeap.h"

using namespace pugi;

vHeap::vHeap(int s, float o, bool pDebug){
    overweight = static_cast<float*>(malloc(sizeof(float)));
    *overweight = o;
    vSize = static_cast<int*>(malloc(sizeof(int)));
    *vSize = s*1024*1024;
    vDebug = static_cast<bool*>(malloc(sizeof(bool)));
    *vDebug = pDebug;
    mainChunk = malloc(s*1024*1024);
    actualPos = mainChunk;
    initPos = mainChunk;
    finalPos = initPos+s*1024*1024;

    pager = static_cast<vPager*>(malloc(sizeof(vPager)));
    new(pager) vPager();

    metaData = vMetaData::getInstance();
    metaData->setPager(pager);
    memoryMutex = metaData->getMutex();

    dmp = malloc(sizeof(Dump));
    new(static_cast<Dump*>(dmp)) Dump();

    dfrag = malloc(sizeof(vDefragmenter));
    new(static_cast<vDefragmenter*>(dfrag)) vDefragmenter(initPos, finalPos, !(*metaData), metaData->getDefragmenterCond(), memoryMutex);

    pthread_create(&dumpThread,NULL,dump,dmp);

    pthread_create(&dfragThread,NULL,vDefragmentThread,dfrag);
    //vDebug=static_cast<bool*>(malloc(sizeof(bool)));
    //dumpFrecuency=static_cast<int*>(malloc(sizeof(int)));
};

vHeap::~vHeap(){
    free(dfrag);
    free(overweight);
    free(vDebug);
    free(mainChunk);
    free(dumpFrecuency);
};

unsigned int vHeap::vMalloc(int sz) {//Analisis de algoritmos 25T
    pthread_mutex_lock(memoryMutex);
    std::chrono::high_resolution_clock::time_point debug;
    if (vDebug) debug = startTime();
    if((*vSize)*(*overweight) > metaData->getHeapUse()){
        void* pos;
        if(actualPos + sz < finalPos){
            pos = actualPos;// add Entry devuelve una referencia
            actualPos += sz;
        }else{
            vEntry* toPage = metaData->searchToPage(sz);
            std::string downPath = pager->pageDown(&*toPage,!*toPage,toPage->getDataSize());
            pos = &*toPage;
            toPage->fileDown(downPath);
        };
        if (vDebug) printTime(debug, "vMalloc");
        pthread_mutex_unlock(memoryMutex);
        return metaData->addEntry(sz, pos);
    }else{
        std::cout << "Error, vHeap lleno" << std::endl;
        if (vDebug) printTime(debug, "vMalloc");
        pthread_mutex_unlock(memoryMutex);
        return 0;
    };
};

vHeap* vHeap::vHeapSingleton = 0;

void vHeap::vFree(unsigned int idRef) {//4T
    pthread_mutex_lock(memoryMutex);
    metaData->removeEntry(idRef);
    pthread_mutex_unlock(memoryMutex);;
}

vMetaData *vHeap::getMetaData() {
    return metaData;
}

vHeap *vHeap::getInstance() {
    if(!vHeapSingleton) {
        vHeapSingleton = static_cast<vHeap *>(malloc(sizeof(vHeap)));
        xml_document doc;
        doc.load_file("vHeap.xml");
        int size = doc.child("VH2015").child("vHeap").attribute("size").as_int();
        float over = doc.child("VH2015").child("vHeap").attribute("overweight").as_float();
        bool debug = doc.child("VH2015").child("vDebug").attribute("activo").as_bool();
        new(vHeapSingleton) vHeap(size, over, debug);
    }
    return vHeapSingleton;
 }

void *vHeap::de_vReference(int id) {//T(7+6i)
   pthread_mutex_lock(memoryMutex);
    std::chrono::high_resolution_clock::time_point debug;
    if (vDebug) debug = startTime();
    vListIterator<vEntry> *iter = (!*metaData)->getIterator();

    while(iter->exists()){
        vEntry* entry = iter->next();
    if(!*entry==id){
            pthread_mutex_unlock(memoryMutex);
            return &*entry;
        };
    };
    pthread_mutex_unlock(memoryMutex);
    if (vDebug) printTime(debug, "vdeReference");
    return 0;
};


int vHeap::removeVRef(int idRef) {
    metaData->decreaseReference(idRef);
};

int vHeap::addVRef(int idRef) {
    metaData->increaseReference(idRef);
};

bool vHeap::getVDebug() {
    return vDebug;
}
