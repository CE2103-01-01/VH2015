//
// Created by pablo on 18/03/15.
//

#ifndef _VH2015_VGARBAGECOLLECTOR_H_
#define _VH2015_VGARBAGECOLLECTOR_H_


#include "vHeap/Headers/vMetaData.h"

class vMetaData;

class vGarbageCollector {
    public:
        static void deallocate(int idRef);
};

#endif //_VH2015_VGARBAGECOLLECTOR_H_
