//
// Created by pablo on 18/03/15.
//
#include "vHeap/Headers/vGarbageCollector.h"


void vGarbageCollector::deallocate(int idRef) {
    vHeap::getInstance()->vFree(idRef);
}
