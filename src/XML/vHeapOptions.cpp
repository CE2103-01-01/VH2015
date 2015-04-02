//
// Created by roberto on 02/04/15.
//

#include "vHeapOptions.h"

vHeapOptions::vHeapOptions(){
    active = static_cast<bool*>(malloc(sizeof(bool)));
    size = static_cast<int*>(malloc(sizeof(int)));
    overweight = static_cast<float*>(malloc(sizeof(float)));
};

vHeapOptions::~vHeapOptions(){
    free(active);
    free(size);
    free(overweight);
};

int vHeapOptions::operator[](std::string var){
    var=path;
};

int vHeapOptions::operator[](bool* var){
    *var=*active;
};

int vHeapOptions::operator[](int* var){
    *var=*size;
};

int vHeapOptions::operator[](float* var){
    *var=*overweight;
};

int vHeapOptions::operator+(std::string var){
    path=var;
};

int vHeapOptions::operator+(bool var){
    *active=var;
};

int vHeapOptions::operator+(int var){
    *size=var;
};

int vHeapOptions::operator+(float var){
    *overweight=var;
};