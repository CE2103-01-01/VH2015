//
// Created by alex on 20/03/15.
//

#include "vHeap.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <unistd.h>


vHeap::vHeap(int s, float o){
    overweight=static_cast<float*>(malloc(sizeof(float)));
    *overweight=o;

    actualID=static_cast<int*>(malloc(sizeof(int)));
    *actualID=0;

    mainChunk=malloc(s);
    actualPos=mainChunk;

    memoryTable=static_cast<List<vMallocMetaData>*>(malloc(sizeof(List<vMallocMetaData>)));
    new(memoryTable) List<vMallocMetaData>();

    vDebug=static_cast<bool*>(malloc(sizeof(bool)));
    dumpFrecuency;//solo hay que cargar desde xml
};

vHeap::~vHeap(){
    free(overweight);
    free(vDebug);
    free(memoryTable);
    free(mainChunk);

};
/*
vRef vHeap::vMalloc(int sz, std::string type){
   if(type=="string"){
        actualPos+=8;
    }
    else{
        actualPos+=4;
    }
    vRef r= vRef(*actualID);
    vMallocMetaData m = vMallocMetaData(sz,type,(*actualID)++,actualPos);
    memoryTable->insertar(m);


    return r;
};

void vHeap::printMetadata(){
    Nodo<vMallocMetaData>* n = memoryTable->obtenerPrimero();
    for(int i=0;i<memoryTable->len();i++){
        std::cout<<i<<std::endl;
        vMallocMetaData m = n->dato;
        std::cout<<
                "ID: "   << static_cast<vMallocMetaData>(n->obtenerDato()).getId()   <<
                "Size: " << static_cast<vMallocMetaData>(n->obtenerDato()).getSize() <<
                "Type: " << static_cast<vMallocMetaData>(n->obtenerDato()).getType() <<
                std::endl;
        n=n->obtenerSiguiente();
    };
};
 */vHeap* vHeap::getInstance() {
    if (!vHeapSingleton) {
        *vHeapSingleton = vHeap(0, 0);
        return vHeapSingleton;

    }
}
dump::dump() {
    //cargar directorio y frecuencia desde xml.
    dump::dumpping = true;
    dump::counter = 1;

}
std::string dump::IntToStr(int n) {
    std::stringstream result;
    result << n;
    return result.str();
}
void dump::saveDump() {
    int frecuency; //aqui se carga la frecuencia desde xml
    while(dump::dumpping){
        std::ofstream myfile(dump::directory);
        myfile.open ("MemoryDump"+IntToStr(dump::counter)+".txt");
        dump::counter++;
        //falta accesar al heap y escritura al arhivo txt
        myfile.close();

        usleep(frecuency);
    }

}


