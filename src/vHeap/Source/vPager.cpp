//
// Created by roberto on 04/04/15.
//


#include <sys/stat.h>
#include <Constants.h>
#include "vHeap/Headers/vPager.h"


vPager::vPager(){};

vPager::~vPager(){};

std::string vPager::pageDown(void *data, int id, int dSize) {//T(13+7i)
    std::string path = Constants::pagesPath;
    path.append(std::to_string(id));
    path.append(extension);

    std::ofstream outFile(path, std::ios::binary);

    for(int counter = 0; counter < dSize; counter++) {
        outFile.write(static_cast<const char *>(data + counter), 1);
    }
    return path;
};


void vPager::pageUp(std::string path, int retSize, void *ret) {//T(11+6i)
    try{
        std::ifstream inFile(path, std::ios::binary);
        inFile.read(static_cast<char*>(ret),inFile.precision());
        inFile.close();
    }catch(int e){
        std::cout<<"Error " << e <<" en vPager al abrir archivo con ruta "<<path<<std::endl;
    };
};