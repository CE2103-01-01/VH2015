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

void vDefragmenter::vDefragment(){
    vListIterator<vEntry>* iter = memoryT->getIterator();
    int counter = 1;
    while (iter->exists()) {
        vEntry* tmp = iter->next();
        if(tmp->getDataSize() + actualPos < finalPos){
            if(&*tmp != actualPos){
                (*tmp)[actualPos];
            }
            actualPos+=tmp->getDataSize();
            (*tmp)[counter];
        }else{
            finishDefragment(iter,counter);
            break;
        };
        counter++;
    };
    actualPos=initPos;
};

void vDefragmenter::finishDefragment(vListIterator<vEntry>* iter, int counter){
    while (iter->exists()) {
        (*(iter->next()))[counter++];
    };
};

pthread_cond_t* vDefragmenter::getCond(){
    return cond;
};
pthread_mutex_t* vDefragmenter::getMutex(){
    return mutex;
};

void* vDefragmentThread(void* p){
    vDefragmenter* vD = static_cast<vDefragmenter*>(p);
    while(true){
        pthread_cond_wait(vD->getCond(), vD->getMutex());
        pthread_mutex_lock(vD->getMutex());

        vD->vDefragment();

        pthread_mutex_unlock(vD->getMutex());
    };
};