//
// Created by roberto on 02/04/15.
//

#ifndef VH2015_VHEAPOPTIONS_H
#define VH2015_VHEAPOPTIONS_H

#include <stdlib.h>
#include <iostream>

class vHeapOptions {
    std::string path;
    bool* active;
    int* size;
    float* overweight;

    public:
        static char const *const xmlPath = "vHeap.xml";
        vHeapOptions();
        ~vHeapOptions();
        int operator[](std::string);
        int operator[](bool*);
        int operator[](int*);
        int operator[](float*);
        int operator +(std::string);
        int operator +(bool);
        int operator +(int);
        int operator +(float);
};


#endif //VH2015_VHEAPOPTIONS_H
