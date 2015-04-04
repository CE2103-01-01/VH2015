//
// Created by roberto on 03/04/15.
//

#ifndef VH2015_VDEFRAGMENTER_H
#define VH2015_VDEFRAGMENTER_H

#include "vEntry.h"
#include "vTypes/Headers/vList.h"

class vEntry;

class vDefragmenter {
    void* mainChunk;
    void* initPos;
    void* finalPos;
    void* actualPos;
    vList<vEntry>* memoryT;
    void finishDefragment(vListIterator<vEntry>*, int);

    public:
        vDefragmenter(void*, void*, void*, void*, int*, vListIterator<vEntry>*);
        ~vDefragmenter();
        void vDefragment();
};


#endif //VH2015_VDEFRAGMENTER_H
