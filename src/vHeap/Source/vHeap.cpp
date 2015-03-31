//
// Created by alex on 20/03/15.
//

#include "vHeap/Headers/vHeap.h"

using namespace pugi;

vHeap::vHeap(int s, float o){
    overweight=static_cast<float*>(malloc(sizeof(float)));
    *overweight=o;

    mainChunk=malloc(s);
    actualPos=mainChunk;


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
    std::cout<<std::endl;
    std::cout<<"On vMalloc"<<std::endl;
    std::cout<<"memoryMutex.lock()"<<std::endl;
    memoryMutex.lock();

    std::cout<<"vRef r= metaData->addEntry(sz,type,actualPos)"<<std::endl;
    vRef r= metaData->addEntry(sz,type,actualPos);// add Entry devuelve una referencia
    std::cout<<"actualPos+=sz"<<std::endl;
    actualPos+=sz;
    std::cout<<"metaData->printMetaData()"<<std::endl;
    metaData->printMetaData();

    std::cout<<"memoryMutex.unlock()"<<std::endl;
    memoryMutex.unlock();

    std::cout<<"return r"<<std::endl;
    std::cout<<std::endl;
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
        new(vHeapSingleton) vHeap(size,over);
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
    std::cout<<std::endl;
    std::cout<<"On vPlacement"<<std::endl;

    std::cout<<"memoryMutex.lock();"<<std::endl;
    memoryMutex.lock();

    std::cout<<"vListIterator<vMallocMDEntry>* iter = (!(*metaData))->getIterator()"<<std::endl;
    vListIterator<vMallocMDEntry>* iter = (!(*metaData))->getIterator();

    std::cout<<"while(iter->exists())"<<std::endl;
    while(iter->exists()){
        std::cout<<"iter exists"<<std::endl;
        std::cout<<"vMallocMDEntry* entry = iter->next()"<<std::endl;
        vMallocMDEntry* entry = iter->next();

        if(entry->getIdRef()==!memory){
            std::cout<<"if(entry->getIdRef()==!memory)"<<std::endl;
            std::cout<<"*( static_cast<vObject*>(entry->getOffSet()) ) = *object"<<std::endl;
            *( static_cast<vObject*>(entry->getOffSet()) ) = *object;
            std::cout<<"memoryMutex.unlock()"<<std::endl;
            memoryMutex.unlock();
            std::cout<<"return 0"<<std::endl;
            std::cout<<std::endl;
            return 0;
        };
    };

    std::cout<<"memoryMutex.unlock()"<<std::endl;
    memoryMutex.unlock();
    std::cout<<"return 1"<<std::endl;
    std::cout<<std::endl;
    return 1;
};