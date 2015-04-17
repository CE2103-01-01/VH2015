//
// Created by roberto on 05/04/15.
//

#include <sys/stat.h>
#include "vHeap/Headers/Dump.h"
using namespace pugi;

Dump::Dump() {//TODO-roberto revise los que estan en comentario,seg fault
    //dumpping = static_cast<bool*>(malloc(sizeof(bool)));
   // counter = static_cast<int*>(malloc(sizeof(int)));
    //frecuency = static_cast<int*>(malloc(sizeof(int)));
    bool dumpping = true;
    int frecuency = 2;
    int counter = 0;
};

Dump::~Dump() {
    /*
    free(dumpping);
    free(frecuency);
    free(counter);
     */
};

bool Dump::getDumppingState(){
    return *dumpping;
};

std::string Dump::IntToStr(int n) {
    std::stringstream result;
    result << n;
    return result.str();

};

void Dump::saveDumpFile() {//T(25+17i)
    std::string path(getenv("HOME"));
    std::stringstream ss;
    ss<<counter;
    std::string s1 = ss.str();
    path += "/DumpFile" + s1 + ".txt";//TODO-alex revisar
    std::ofstream myfile(path);
    vListIterator<vEntry> *iter = vMetaData::getInstance()->getMemoryTable()->getIterator();
    xml_document doc;
    doc.load_file("vHeap.xml");
    std::cout<<path<<std::endl;
    std::cout<<doc.child("VH2015").child("vHeap").attribute("size").as_int()<<std::endl;
    myfile<< "Total size of Memory: "<<doc.child("VH2015").child("vHeap").attribute("size").as_int()<<std::endl;
    while(iter->exists()){

        vEntry *m = iter->next();
        myfile << "Memory direction: " << "Hola" << "\n";
        if(m->getUseFlag()==0) {

            myfile << "Memory direction: " << m->getOffSet() << "\n";
            myfile << "Size of data containing: " << m->getDataSize() << "\n";
            myfile << "flag in use: " << true << "\n";
        }
    }

    Dump::counter++;
    myfile.close();
};

int                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 Dump::getFrecuency(){
    return *frecuency;
};

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
};