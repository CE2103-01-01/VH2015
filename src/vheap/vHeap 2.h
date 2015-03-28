#ifndef VHEAP_H
#define VHEAP_H

#include <stdlib.h>
#include "Metadata.h"
#include "vRef.h"
#include "dataStructures.h"

class vHeap
{
    private:
        bool vDebug;
        int dumpFrecuency;
        static vHeap vHeapSingleton;
        int* overweight;
        void* mainChunk;
        void* actualDir;
        int* actualID;
        Lista<Metadata>* control;
    public:
        static vHeap getInstance();
        vHeap(int, int);
        virtual ~vHeap();
        vRef vMalloc(int,std::string);
        void vFree(vRef);
        bool makeDump();
        void printMetadata();
};




#endif // VHEAP_H
