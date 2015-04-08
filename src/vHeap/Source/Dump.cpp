//
// Created by roberto on 05/04/15.
//

#include "vHeap/Headers/Dump.h"
using namespace pugi;

Dump::Dump() {
    *dumpping = true;
    *frecuency = 2;
    *counter = 0;
};

Dump::~Dump() {
    free(dumpping);
    free(frecuency);
    free(counter);
};

bool Dump::getDumppingState(){
    return *dumpping;
};

std::string Dump::IntToStr(int n) {
    std::stringstream result;
    result << n;
    return result.str();

};

void Dump::saveDumpFile() {
    //startDump();
    std::string path(getenv("HOME"));
    std::stringstream ss;
    ss<<counter;
    std::string s1 = ss.str();
    path += "/Desktop/DumpFile"+s1+".txt";
    std::ofstream myfile(path);
    vListIterator<vEntry> *iter = vMetaData::getInstance()->getMemoryTable()->getIterator();
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
};

int                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 Dump::getFrecuency(){
    return *frecuency;
};
/*
void* dump(void* d){
    struct timespec o;
    o.tv_nsec = 0;
    o.tv_sec = static_cast<Dump*>(d)->getFrecuency();
    while(true){
        nanosleep(&o, NULL);
        pthread_mutex_lock(vMetaData::getInstance()->getMutex());
        static_cast<Dump*>(d)->saveDumpFile();
        pthread_mutex_unlock(vMetaData::getInstance()->getMutex());
    };
};*/