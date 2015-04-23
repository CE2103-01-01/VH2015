//
// Created by roberto on 03/04/15.
//

#ifndef VH2015_VDEFRAGMENTER_H
#define VH2015_VDEFRAGMENTER_H

#include "vEntry.h"
#include "Constants.h"
#include "Tree/Tree.h"
#include "vHeap/Headers/vMetaData.h"
#include <pthread.h>
#include <cstdlib>

class vEntry;

class vDefragmenter {
    void* initPos;
    void* finalPos;
    void* actualPos;
    public:
        vDefragmenter(void*, void*);
        ~vDefragmenter();
        void vDefragment();
};

void* vDefragmentThread(void*);

#endif //VH2015_VDEFRAGMENTER_H
