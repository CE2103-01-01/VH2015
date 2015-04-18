//
// Created by roberto on 05/04/15.
//

#ifndef VH2015_DUMP_H
#define VH2015_DUMP_H


#include "vMetaData.h"
#include "vTypes/Headers/vList.h"
#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <stdio.h>
#include <sstream>
#include <fstream>
#include <unistd.h>
#include "../libs/pugixml.hpp"

class Dump {
    int frecuency;
    int counter;
    std::string directory;
    bool dumpping;

    public:
        Dump();
        ~Dump();
        std::string IntToStr(int);
        void saveDumpFile();
        bool getDumppingState();
        int getFrecuency();

};

void* dump(void*);

#endif //VH2015_DUMP_H
