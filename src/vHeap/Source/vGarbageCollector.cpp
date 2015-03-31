//
// Created by pablo on 18/03/15.
//
#include "vHeap/Headers/vGarbageCollector.h"
#include <unistd.h>


vGarbageCollector::vGarbageCollector(vHeap *pHeap, int freq) {
    myHeap = pHeap;
    frequency = freq;
    on = true;
    pthread_t myThread;
    int iRetT;
    //iRetT = pthread_create(&myThread, NULL, checkForGarbage, NULL);
}

void vGarbageCollector::checkForGarbage() {
    while(on)
    {
        //myHeap->memoryTable;
        usleep(1/frequency);
    }
}
