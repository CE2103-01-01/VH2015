//
// Created by roberto on 03/04/15.
//

#ifndef VH2015_VDEFRAGMENTER_H
#define VH2015_VDEFRAGMENTER_H

#include "vEntry.h"
#include "vTypes/Headers/vList.h"
#include <pthread.h>
#include <cstdlib>

class vEntry;

class vDefragmenter {
    pthread_cond_t* cond;
    pthread_mutex_t* mutex;
    bool* active;
    void* initPos;
    void* finalPos;
    void* actualPos;
    vList<vEntry>* memoryT;
    public:
        vDefragmenter(void*, void*, vList<vEntry>*, pthread_cond_t*, pthread_mutex_t*);
        ~vDefragmenter();
        void vDefragment();
        pthread_mutex_t* getMutex();
        pthread_cond_t* getCond();
};


void* vDefragmentThread(void*);

#endif //VH2015_VDEFRAGMENTER_H
