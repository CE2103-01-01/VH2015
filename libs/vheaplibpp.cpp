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

void logTime(high_resolution_clock::time_point sTime, std::string proceso) {
    high_resolution_clock::time_point finish = high_resolution_clock::now();
    ofstream log(Constants::logFilePath, ios_base::out | ios_base::app );
    log << "Time elapsed for "<<proceso +" : "<< duration_cast<nanoseconds>(finish-sTime).count()
    << "ns"<<endl;
}

void log(string str)
{
    ofstream log(Constants::logFilePath, ios_base::out | ios_base::app );
    log<<str<<endl;
}

void printTime(high_resolution_clock::time_point sTime){
cout<<"Time elapsed: "<< duration_cast<nanoseconds>(high_resolution_clock::now()-sTime).count()
<< "ns"<<endl;
};

bool getVDebug() {
    return vHeap::getInstance()->getVDebug();
}
