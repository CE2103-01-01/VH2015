//
// Created by roberto on 03/04/15.
//


#include "vheaplibpp.h"

int removeVRef(int id){
    return vHeap::getInstance()->addVRef(id);
};

int addVRef(int id){
    return vHeap::getInstance()->removeVRef(id);
};

void* de_vReference(int id){
    return vHeap::getInstance()->de_vReference(id);
};

high_resolution_clock::time_point startTime() {
    return high_resolution_clock::now();

}

void printTime(high_resolution_clock::time_point sTime,std::string proceso) {
    high_resolution_clock::time_point finish = high_resolution_clock::now();
    std::ofstream log(Constants::logFilePath, std::ios_base::out | std::ios_base::app );
    log << "Time elapsed for "<<proceso +" : "<< std::chrono::duration_cast<std::chrono::nanoseconds>(finish-sTime).count()
    << "ns"<<endl;
}

bool getVDebug() {
    return vHeap::getInstance()->getVDebug();
}
