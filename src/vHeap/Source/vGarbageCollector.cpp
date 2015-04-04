//
// Created by pablo on 18/03/15.
//
#include "vHeap/Headers/vGarbageCollector.h"

/**
* Ejecuta vFree de un vRef sin uso
*/
void vGarbageCollector::deallocate(int idRef) {
    vHeap::getInstance()->vFree(idRef);
    startDump();
}

/**
* Inicia el dump cuando se ejecuta el deallocate
*/
/**
void vGarbageCollector::startDump() {
    vListIterator<vEntry> *iter= vHeap::getInstance()->getMetaData()->getMemoryTable()->getIterator();
    while(iter->exists()){

        vEntry *m = iter->next();
        vEntry *n = iter->next();
        int prev =*(int*)  m->getOffSet();
        int next = *(int*) n->getOffSet();
        if(!next==prev+m->getDataSize()){
            vEntry *temp = m;
            int distance = m->getDataSize()+1;
            while(n!=temp){
                temp+=distance;
                distance++;
            }
            *m[temp];  //set offset
        }

    }
}

*/