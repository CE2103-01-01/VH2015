//
// Created by alex on 20/03/15.
//

#include "vHeap/Headers/vHeap.h"

using namespace pugi;

vHeap::vHeap(int s, float o){
    overweight=static_cast<float*>(malloc(sizeof(float)));
    *overweight=o;

    mainChunk = malloc(s * 1024);
    actualPos=mainChunk;

    metaData = new vMallocMetaData();

    //vDebug=static_cast<bool*>(malloc(sizeof(bool)));
    //dumpFrecuency=static_cast<int*>(malloc(sizeof(int)));
};

vHeap::~vHeap(){
    free(overweight);
    free(vDebug);
    free(mainChunk);
    free(dumpFrecuency);
};

vHeap* vHeap::vHeapSingleton = 0;

vRef vHeap::vMalloc(int sz, std::string type){

    memoryMutex.lock();

    vRef r= metaData->addEntry(sz,type,actualPos);// add Entry devuelve una referencia
    actualPos+=sz;
    metaData->printMetaData();

    memoryMutex.unlock();

    return r;
};

void vHeap::vFree(vRef r){
    memoryMutex.lock();

    memoryMutex.unlock();
}

 vHeap* vHeap::getInstance() {
    if(!vHeapSingleton) {
        vHeapSingleton = static_cast<vHeap *>(malloc(sizeof(vHeap)));
        xml_document doc;
        doc.load_file("vHeap.xml");
        int size = doc.child("VH2015").child("vHeap").attribute("size").as_int();
        float over = doc.child("VH2015").child("vHeap").attribute("overweight").as_float();
        new(vHeapSingleton) vHeap(100, 100);
    }

    return vHeapSingleton;
 }

std::string Dump::IntToStr(int n) {
    std::stringstream result;
        result << n;
        return result.str();
  
}
void Dump::saveDumpFile() {
//    while(Dump::dumpping){
//        std::ofstream myfile(Dump::directory);
//        myfile.open("DumpFile"+IntToStr(Dump::counter)+".txt");
//        //falta escritura de los contenidos de heap
//        Dump::counter++;
//        myfile.close();
//        usleep(Dump::frecuency);
//    }
}

int vHeap::vPlacement(vRef memory, vObject* object){
    memoryMutex.lock();

    vListIterator<vMallocMDEntry>* iter = (!(*metaData))->getIterator();

    while(iter->exists()){
        vMallocMDEntry* entry = iter->next();

        if(entry->getIdRef()==!memory){
            *( static_cast<vObject*>(entry->getOffSet()) ) = *object;
            memoryMutex.unlock();
            return 0;
        };
    };

    memoryMutex.unlock();
    return 1;
};