//
// Created by pablo on 18/03/15.
//

#ifndef _VH2015_VGARBAGECOLLECTOR_H_
#define _VH2015_VGARBAGECOLLECTOR_H_


#include "vHeap.h"

class vGarbageCollector {
private:


public:
    static void deallocate(int idRef);
    static void startDumop();
};


#endif //_VH2015_VGARBAGECOLLECTOR_H_
