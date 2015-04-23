//
// Created by roberto on 05/04/15.
//

#include <sys/stat.h>
#include <Constants.h>
#include "vHeap/Headers/Dump.h"
using namespace pugi;

Dump::Dump() {
    counter = 0;
    frecuency = 5;
    dumpping = true;
}

bool Dump::getDumppingState(){
    return dumpping;
}

std::string Dump::IntToStr(int n) {
    std::stringstream result;
    result << n;
    return result.str();

}

void Dump::saveDumpFile() {//T(25+17i)
    std::string path = Constants::dumpsPath;
    std::ofstream myfile(path);
    Tree<vEntry> *tree = vMetaData::getInstance()->getMemoryTree();
    xml_document doc;
    doc.load_file("vHeap.xml");
    myfile<< "Total size of Memory: "<<doc.child("VH2015").child("vHeap").attribute("size").as_int()<<std::endl;
    for(int i=1; i<tree->max(); i++){
        try{
            vEntry *m = (static_cast<vEntry*>(tree->searchElement(i)));
            if(m->getUseFlag()==0) {
                myfile << "Memory direction: " << m->getOffSet() << "\n";
                myfile << "Size of data containing: " << m->getDataSize() << "\n";
                myfile << "flag in use: " << true << "\n";
            }
        }catch(int e){
            continue;
        }
    }
    (Dump::counter)++;
    myfile.close();
}

int Dump::getFrecuency() {
    return frecuency;
}

void* dump(void* d){
    Dump* dmp = static_cast<Dump*>(d);
    struct timespec o;
    o.tv_nsec = 0;
    o.tv_sec = dmp->getFrecuency();
    while(true){
        nanosleep(&o,0);
        pthread_mutex_lock(vMetaData::getInstance()->getMutex());
        dmp->saveDumpFile();
        pthread_mutex_unlock(vMetaData::getInstance()->getMutex());
    }
    return 0;
}
