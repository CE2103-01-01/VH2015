//
// Created by pablo on 18/03/15.
//
#include "vHeap/Headers/vGarbageCollector.h"


void vGarbageCollector::deallocate(int idRef) {
    vHeap::getInstance()->vFree(idRef);
}
void vGarbageCollector::startDumop() {
    vListIterator<vMallocMDEntry> *iter= vHeap::getInstance()->getMetaData()->getMemoryTable()->getIterator();
    while(iter->exists()){

        vMallocMDEntry *m = iter->next();
        vMallocMDEntry *n = iter->next();
        int prev =*(int*)  m->getOffSet();
        int next = *(int*) n->getOffSet();
        if(!next==prev+m->getDataSize()){
            vMallocMDEntry *temp = m;
            int distance = m->getDataSize()+1;
            while(n!=temp){
                temp+=distance;
                distance++;
            }
            m->setOffset(temp);
        }

    }
}

