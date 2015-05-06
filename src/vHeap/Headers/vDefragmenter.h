//
// Created by roberto on 03/04/15.
//

#ifndef VH2015_VDEFRAGMENTER_H
#define VH2015_VDEFRAGMENTER_H

#include "vHeap.h"

class vEntry;

class vDefragmenter {
    void* initPos;
    void* finalPos;
    void* actualPos;
    bool* defragmenting;
    public:
        vDefragmenter(void*, void*);
        ~vDefragmenter();
        void vDefragment();

    bool getDefragmenterFlag();
};

void* vDefragmentThread(void*);

#endif //VH2015_VDEFRAGMENTER_H
