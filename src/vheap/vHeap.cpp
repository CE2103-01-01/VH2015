//
// Created by alex on 20/03/15.
//

#include <fstream>
#include <unistd.h>
#include "vHeap.h"


vHeap::vHeap(int s, float o){
    overweight=static_cast<float*>(malloc(sizeof(float)));
    *overweight=o;

    actualID=static_cast<int*>(malloc(sizeof(int)));
    *actualID=0;

    mainChunk=malloc(s);
    actualPos=mainChunk;

    memoryTable=static_cast<List<vMallocMetaData>*>(malloc(sizeof(List<vMallocMetaData>)));
    new(memoryTable) List<vMallocMetaData>();

    //vDebug=static_cast<bool*>(malloc(sizeof(bool)));
    //dumpFrecuency=static_cast<int*>(malloc(sizeof(int)));
};

vHeap::~vHeap(){
    free(overweight);
    free(vDebug);
    free(memoryTable);
    free(mainChunk);
    free(dumpFrecuency);
};
vHeap* vHeap::vHeapSingleton = 0;
vRef vHeap::vMalloc(int sz, std::string type){
    vRef r= vRef(*actualID);
    vMallocMetaData m = vMallocMetaData(sz,type,(*actualID)++,actualPos);
    memoryTable->append(m);
    actualPos+=sz;

    return r;
};

void vHeap::printMetadata(){
    ListIterator<vMallocMetaData>* iter = memoryTable->getIterator();
    while(iter->exists()){
        vMallocMetaData* m = iter->next();
        std::cout<<
        "ID: "   << m->getId()   <<
        "Size: " << m->getSize() <<
        "Type: " << m->getType() <<
        std::endl;
    };
};
 vHeap* vHeap::getInstance() {
    if(!vHeapSingleton) {
        vHeapSingleton = static_cast<vHeap *>(malloc(sizeof(vHeap)));//TODO-ernesto datos provienen del xml
        new(vHeapSingleton) vHeap(100,100);
    }

    return vHeapSingleton;

}
std::string Dump::IntToStr(int n) {


    std::stringstream result;
        result << n;
        return result.str();
  
}
void Dump::saveDumpFile() {
    while(Dump::dumpping){
        std::ofstream myfile(Dump::directory);
        myfile.open("DumpFile"+IntToStr(Dump::counter)+".txt");
        //falta escritura de los contenidos de heap
        Dump::counter++;
        myfile.close();
        usleep(Dump::frecuency);
    }
}
