//
// Created by roberto on 05/04/15.
//

#include <sys/stat.h>
#include <Constants.h>
#include "vHeap/Headers/Dump.h"
using namespace pugi;

Dump::Dump() {
    counter = static_cast<int*>(malloc(sizeof(int)));
    (*counter) = 0;
    frecuency = static_cast<int*>(malloc(sizeof(int)));
    (*frecuency) = 1;
    dumpping = static_cast<bool*>(malloc(sizeof(bool)));
    (*dumpping) = true;
}

Dump::~Dump() {
    free(counter);
    free(frecuency);
    free(dumpping);
}

bool Dump::getDumppingState(){
    return (*dumpping);
}

std::string Dump::IntToStr(int n) {
    std::stringstream result;
    result << n;
    return result.str();

}

void Dump::saveDumpFile() {//T(25+17i)
    std::string path = Constants::dumpsPath;
    path += "/DumpFile" + std::to_string((*counter)) + ".txt";//TODO-alex revisar
    std::ofstream myfile(path);

    Tree<vEntry> *tree = vMetaData::getInstance()->getMemoryTree();
    xml_document doc;
    doc.load_file("vHeap.xml");
    std::cout<<path<<std::endl;
    std::cout<<doc.child("VH2015").child("vHeap").attribute("size").as_int()<<std::endl;
    myfile<< "Total size of Memory: "<<doc.child("VH2015").child("vHeap").attribute("size").as_int()<<std::endl;
    for(int i=1; i<tree->max(); i++){
        try{
            vEntry *m = (static_cast<vEntry*>(tree->searchElement(i)));
            myfile << "Memory direction: " << "Hola" << "\n";
            if(m->getUseFlag()==0) {
                myfile << "Memory direction: " << m->getOffSet() << "\n";
                myfile << "Size of data containing: " << m->getDataSize() << "\n";
                myfile << "flag in use: " << true << "\n";
            }
        }catch(int e){
            continue;
        }
    }

    (*counter)++;
    myfile.close();
}


void* dump(void* d){
    struct timespec o;
    o.tv_nsec = 500;
    o.tv_sec = static_cast<Dump*>(d)->getFrecuency();
    while(true){
        nanosleep(&o,0);
        //static_cast<Dump*>(d)->saveDumpFile();
    }
    return 0;
}

int Dump::getFrecuency() {
    return (*frecuency);
}
