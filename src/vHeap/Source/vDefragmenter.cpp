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

void* vDefragmenter::vDefragmentThread(void*){
    while(true){
        pthread_cond_wait(cond, mutex);
        pthread_mutex_lock(mutex);

        vDefragment();

        pthread_mutex_unlock(mutex);
    };
    return 0;
};