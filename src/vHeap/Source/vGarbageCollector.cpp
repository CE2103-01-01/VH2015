//
// Created by pablo on 18/03/15.
//
#include <vheaplibpp.h>
#include "vHeap/Headers/vGarbageCollector.h"

/**
* Ejecuta vFree de un vRef sin uso
*/
void vGarbageCollector::deallocate(int idRef) {
    std::chrono::high_resolution_clock::time_point debug;
    //Bloquea mutex
    pthread_mutex_lock(vMetaData::getInstance()->getMutex());
    //Remueve la referencia
    vMetaData::getInstance()->removeEntry(idRef);
    //Desbloquea mutex
    pthread_mutex_unlock(vMetaData::getInstance()->getMutex());
    if(getVDebug()) logTime(debug, "GC deallocate");
}

