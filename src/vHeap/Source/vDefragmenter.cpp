//
// Created by roberto on 03/04/15.
//

#include "vHeap/Headers/vDefragmenter.h"

vDefragmenter::vDefragmenter(void* iPos, void* fPos, vList<vEntry>* mem, pthread_cond_t* c, pthread_mutex_t* m){
    initPos = iPos;
    finalPos = fPos;
    actualPos = iPos;
    memoryT = mem;
    cond=c;
    mutex=m;
    active = static_cast<bool*>(malloc(sizeof(bool)));
    *active = true;
};

vDefragmenter::~vDefragmenter(){};

void vDefragmenter::vDefragment() {//T(3+11i)
    vListIterator<vEntry>* iter = memoryT->getIterator();
    while (iter->exists()) {
        vEntry* tmp = iter->next();
        if(tmp->isOnHeap()){
            tmp->changeFlag();
            if(&*tmp != actualPos){
                (*tmp)[actualPos];
            }
            actualPos+=tmp->getDataSize();
            tmp->changeFlag();
        }
    };
    actualPos=initPos;
};

pthread_mutex_t* vDefragmenter::getMutex(){
    return mutex;
};

pthread_cond_t* vDefragmenter::getCond(){
    return cond;
};

void* vDefragmentThread(void* param){
    vDefragmenter* vD = (static_cast<vDefragmenter*>(param));
    while (true) {//TODO-roberto flag
        pthread_mutex_lock(vD->getMutex());
        pthread_cond_wait(vD->getCond(), vD->getMutex());
        vD->vDefragment();
        pthread_mutex_unlock(vD->getMutex());
    };
    return 0;
};