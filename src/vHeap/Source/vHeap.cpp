//
// Created by alex on 20/03/15.
//

#include "vHeap/Headers/vHeap.h"

using namespace pugi;

vHeap::vHeap(int s, float o){
    overweight = static_cast<float*>(malloc(sizeof(float)));
    *overweight = o;
    vSize = static_cast<int*>(malloc(sizeof(int)));
    *vSize = s;
    mainChunk = malloc(s * 1024);
    actualPos = mainChunk;
    initPos = mainChunk;
    finalPos = initPos+s*1024;

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

unsigned int vHeap::vMalloc(int sz) {
    pthread_mutex_lock(memoryMutex);
    unsigned int id;
    if((*vSize)*(*overweight) > metaData->getHeapUse()){
        if(actualPos + sz < finalPos){
            id = metaData->addEntry(sz, actualPos);// add Entry devuelve una referencia
            std::cout<<"MALLOC4"<<std::endl;
            actualPos += sz;
            std::cout<<"MALLOC5"<<std::endl;
        }else{
            vEntry* toPage = metaData->searchToPage(sz);
            std::string downPath = pager->pageDown(&*toPage,!*toPage,toPage->getDataSize());
            void* pos = &*toPage;
            toPage->fileDown(downPath);
            id = metaData->addEntry(sz, pos);
        };
    }else{
        id=0;
        std::cout << "Error, vHeap lleno" << std::endl;
    };

    pthread_mutex_unlock(memoryMutex);

    return id;
};

vHeap* vHeap::vHeapSingleton = 0;

void vHeap::vFree(unsigned int idRef) {
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
        new(vHeapSingleton) vHeap(size, over);
    }
    return vHeapSingleton;
 }

void *vHeap::de_vReference(int id) {
   pthread_mutex_lock(memoryMutex);

    vListIterator<vEntry> *iter = (!*metaData)->getIterator();

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


int vHeap::removeVRef(int idRef) {
    metaData->decreaseReference(idRef);
}

int vHeap::addVRef(int idRef) {
    metaData->increaseReference(idRef);
}