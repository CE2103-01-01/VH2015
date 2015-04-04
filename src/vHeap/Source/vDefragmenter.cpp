//
// Created by roberto on 03/04/15.
//

#include "vHeap/Headers/vDefragmenter.h"

vDefragmenter::vDefragmenter(void* mChunk, void* iPos, void* fPos, void* aPos, vList<vEntry>* mem){
    mainChunk = mChunk;
    initPos = iPos;
    finalPos = fPos;
    actualPos = aPos;
    memoryT = mem;
};

vDefragmenter::~vDefragmenter(){};

void vDefragmenter::vDefragment(){
    vListIterator<vEntry>* iter = memoryT->getIterator();
    int counter = 1;
    while(iter->exists){
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
};

void vDefragmenter::finishDefragment(vListIterator<vEntry>* iter, int counter){
    while (iter->exists()) {
        (*(iter->next()))[counter++];
    };
};