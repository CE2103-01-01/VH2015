//
// Created by roberto on 03/04/15.
//

#ifndef VH2015_VHEAPLIBPP_H
#define VH2015_VHEAPLIBPP_H

#include "../src/vHeap/Headers/vHeap.h"
#include <chrono>
using namespace std::chrono;
class vHeap;
bool vDebug();
int removeVRef(int);
int addVRef(int);
void* de_vReference(int);
high_resolution_clock::time_point startTime();
void printTime(high_resolution_clock::time_point sTime,std::string proceso);

#endif //VH2015_VHEAPLIBPP_H
