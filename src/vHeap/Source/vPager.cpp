//
// Created by roberto on 04/04/15.
//

#include "vHeap/Headers/vPager.h"

vPager::vPager(){};

vPager::~vPager(){};

std::string vPager::pageDown(void* data, int id, int dSize){
    int counter = 0;
    std::string path = std::to_string(id).append(".bin");
    std::ofstream ofile("Pages/"+path, std::ios::binary);
    do{
        const char* tmp = static_cast<const char*>(data + counter);
        ofile.write(tmp, sizeof(*tmp));
        counter++;
    }while(counter < dSize);
    return path;
};

void* vPager::pageUp(std::string path){};  //TODO: roberto: implementar
