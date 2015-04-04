//
// Created by roberto on 04/04/15.
//

#include "vHeap/Headers/vPager.h"


vPager::vPager(){};

vPager::~vPager(){};

std::string vPager::pageDown(void* data, int id, int dSize){
    std::string path = "../res/vPages/";
    path.append(std::to_string(id));
    path.append(".celdmm");

    std::ofstream outFile(path, std::ios::binary);

    int counter = 0;
    do{
        const char* tmp = static_cast<const char*>(data + counter);
        outFile.write(tmp, sizeof(*tmp));
        counter++;
    }while(counter < dSize);

    return path;
};


void vPager::pageUp(std::string path, int s, void* ret){
    try{
        std::ifstream inFile(path, std::ios::binary);
        char* buf = static_cast<char*>(malloc(s * sizeof(char)));
        inFile.read(buf,inFile.precision());

        int counter = 0;
        do{
            *static_cast<char*>(ret+counter) = *buf;
            buf++;
            counter++;
        }while(counter < s);
        inFile.close();
    }catch(int e){
        //TODO: implementar excepcion de ruta no existente
    };
};