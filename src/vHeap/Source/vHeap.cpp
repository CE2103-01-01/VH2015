//
// Created by alex on 20/03/15.
//

#include <thread>
#include "vHeap/Headers/vHeap.h"

using namespace pugi;

vHeap::vHeap(int s, float o){
    overweight=static_cast<float*>(malloc(sizeof(float)));
    *overweight=o;
    memoryMutex=PTHREAD_MUTEX_INITIALIZER;
    mainChunk = malloc(s * 1024);
    actualPos=mainChunk;
    initPos=mainChunk;
    finalPos = initPos+s*1024;
    metaData = new vMetaData();

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

    pthread_mutex_lock(&memoryMutex);

    vRef r= metaData->addEntry(sz,type,actualPos);// add Entry devuelve una referencia
    actualPos+=sz;
    metaData->printMetaData();


    pthread_mutex_unlock(&memoryMutex);

    return r;
};

void vHeap::vFree(vRef r){
    pthread_mutex_lock(&memoryMutex);
    metaData->removeEntry(!r);
    pthread_mutex_unlock(&memoryMutex);;
}


void vHeap::vFree(unsigned int idRef) {
    pthread_mutex_lock(&memoryMutex);
    metaData->removeEntry(idRef);
    pthread_mutex_unlock(&memoryMutex);;
}

vMetaData *vHeap::getMetaData() {
    return metaData;
}

 vHeap* vHeap::getInstance() {
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
Dump::Dump() {
    dumpping = true;
    frecuency = 2;
    counter = 0;
}
Dump::~Dump() {
}



std::string Dump::IntToStr(int n) {
    std::stringstream result;
        result << n;
        return result.str();
  
}
void Dump::saveDumpFile() {
        //startDump();
        std::string path(getenv("HOME"));
        std::stringstream ss;
        ss<<counter;
        std::string s1 = ss.str();
        path += "/Desktop/DumpFile"+s1+".txt";
        std::ofstream myfile(path);
    vListIterator<vEntry> *iter = vHeap::getInstance()->getMetaData()->getMemoryTable()->getIterator();
        xml_document doc;
        doc.load_file("vHeap.xml");
    std::cout<<doc.child("VH2015").child("vHeap").attribute("size").as_int()<<std::endl;
        myfile<< "Total size of Memory: "<<doc.child("VH2015").child("vHeap").attribute("size").as_int()<<std::endl;
        while(iter->exists()){

            vEntry *m = iter->next();
            if(m->getUseFlag()==0) {

                myfile << "Memory direction: " << m->getOffSet() << "\n";
                myfile << "Size of data containing: " << m->getDataSize() << "\n";
                myfile << "falg in use: " << true << "\n";
            }
        }



        Dump::counter++;
        myfile.close();
    }


void *vHeap::de_vReference(int id) {
   pthread_mutex_lock(&memoryMutex);

    vListIterator<vEntry> *iter = (!*metaData)->getIterator();

    while(iter->exists()){
        vEntry *entry = iter->next();
    if(!*entry==id){
            pthread_mutex_unlock(&memoryMutex);
            return &*entry;
        };
    };
    pthread_mutex_unlock(&memoryMutex);
    return 0;
};


int vHeap::removeVRef(int idRef) {
    metaData->decreaseReference(idRef);
}

int vHeap::addVRef(int idRef) {
    metaData->increaseReference(idRef);
}


