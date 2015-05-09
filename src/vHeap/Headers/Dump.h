//
// Created by roberto on 05/04/15.
//

#ifndef VH2015_DUMP_H
#define VH2015_DUMP_H

#include "../libs/pugixml.hpp"
#include "vMetaData.h"
#include <sstream>
#include <sys/stat.h>
#include <Constants.h>

class Dump {
    int* frecuency;
    int* counter;
    bool* dumpping;
    public:
        Dump();
        ~Dump();
        void changeDumppingState();
        void saveDumpFile();
        bool getDumppingState();
        int getFrecuency();

};

void* dump(void*);

#endif //VH2015_DUMP_H
