//
// Created by roberto on 03/04/15.
//

#include "vHeap/Headers/vDefragmenter.h"

vDefragmenter::vDefragmenter(void* iPos, void* fPos){
    initPos = iPos;
    finalPos = fPos;
    actualPos = iPos;
}

vDefragmenter::~vDefragmenter(){
    initPos = 0;
    finalPos = 0;
    actualPos = 0;
}

void vDefragmenter::vDefragment() {//T(3+11i)
    Tree<vEntry>* tree = vMetaData::getInstance()->getMemoryTree();
    for(int i=1; i<= tree->lenght(); i++){
        try{
            vEntry* tmp = static_cast<vEntry*>(tree->searchElement(i));
            if(tmp->getIdRef()!=0 && tmp->isOnHeap()){
                tmp->changeFlag();
                if(tmp->getOffSet() != actualPos){
                    tmp->setOffset(actualPos);
                }
                actualPos += tmp->getDataSize();
                tmp->changeFlag();
            }
        }catch(int e){
            std::cout << "Error " << e << std::endl;
            continue;
        }
    };
    actualPos=initPos;
}

void* vDefragmentThread(void* param){
    vDefragmenter* vDefrag = (static_cast<vDefragmenter*>(param));
    struct timespec o;
    o.tv_nsec = 0;
    o.tv_sec = Constants::defragmenterFrecuency;
    while (true) {
        nanosleep(&o,0);
        pthread_mutex_lock(vMetaData::getInstance()->getMutex());
        vDefrag->vDefragment();
        pthread_mutex_unlock(vMetaData::getInstance()->getMutex());
    };
    return 0;
}