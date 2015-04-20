//
// Created by roberto on 03/04/15.
//

#ifndef VH2015_VHEAPLIBPP_H
#define VH2015_VHEAPLIBPP_H

#include <Constants.h>
#include "../src/vHeap/Headers/vHeap.h"
#include <chrono>
#include <fstream>

using namespace std;
using namespace chrono;
class vHeap;
bool getVDebug();
int removeVRef(int);
int addVRef(int);
void* de_vReference(int);
high_resolution_clock::time_point startTime();
void logTime(high_resolution_clock::time_point sTime, std::string proceso);
void log(string str);
void printTime(high_resolution_clock::time_point sTime);

#endif //VH2015_VHEAPLIBPP_H
