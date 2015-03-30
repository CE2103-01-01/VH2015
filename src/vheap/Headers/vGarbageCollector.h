//
// Created by pablo on 18/03/15.
//

#ifndef _VH2015_VGARBAGECOLLECTOR_H_
#define _VH2015_VGARBAGECOLLECTOR_H_


#include "vHeap.h"

class vGarbageCollector {
private:
    vHeap* myHeap;
    int frequency;
    bool on;
    void checkForGarbage();
public:
    vGarbageCollector(vHeap *pHeap, int frequency);
};


#endif //_VH2015_VGARBAGECOLLECTOR_H_
