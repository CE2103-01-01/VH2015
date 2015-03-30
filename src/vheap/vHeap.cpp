//
// Created by alex on 20/03/15.
//

#include <fstream>
#include <unistd.h>
#include "vHeap.h"
#include "XML/xmlReader.h"

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
    vRef r= metaData.addEntry(sz,type,actualPos);// add Entry devuelve una referencia
    actualPos+=sz;
    return r;
};

 vHeap* vHeap::getInstance() {
    if(!vHeapSingleton) {
        vHeapSingleton = static_cast<vHeap *>(malloc(sizeof(vHeap)));
        xmlReader xml;
        Opciones datos = xml.vHeapOptions();
        new(vHeapSingleton) vHeap(datos.size,datos.overweight);
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
