//
// Created by pablo on 18/03/15.
//
#include "vHeap/Headers/vGarbageCollector.h"

/**
* Ejecuta vFree de un vRef sin uso
*/
void vGarbageCollector::deallocate(int idRef) {
    pthread_mutex_lock(vMetaData::getInstance()->getMutex());
    vMetaData::getInstance()->removeEntry(idRef);
    pthread_mutex_unlock(vMetaData::getInstance()->getMutex());
    pthread_cond_signal(vMetaData::getInstance()->getDefragmenterCond());
}

