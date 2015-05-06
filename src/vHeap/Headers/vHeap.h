#ifndef _VH2015_VHEAP_H_
#define _VH2015_VHEAP_H_

#include <unistd.h>
#include "vDefragmenter.h"
#include "Dump.h"
#include <vheaplibpp.h>

template<class T> class vRef;
class vMetaData;

class vHeap{
    bool* vDebug;
    int* dumpFrecuency;
    static vHeap* vHeapSingleton;
    float* overweight;
    long* vSize;
    void* mainChunk;
    void* initPos;
    void* finalPos;
    void* actualPos;
    vMetaData* metaData;
    pthread_mutex_t* memoryMutex;
    void stopRunning(int);
public:
    long getSize();
    bool getVDebug();
    vHeap();
    ~vHeap();
    unsigned int vMalloc(int);
    unsigned int vCalloc(int);
    template <class T> void vFree(vRef<T>);
    void vFree(unsigned int);
    static vHeap* getInstance();
    int removeVRef(int);
    int addVRef(int);
    template <class T> int vPlacement(vRef<T>, T);
    void* de_vReference(int);
    long getUse();
    void setActualPos(void*);
    void* getInitPos();
    void* getFinalPos();
};
/**
 * Metodo para liberar memoria
 */
template<class T> void vHeap::vFree(vRef<T> r) {
    pthread_mutex_lock(memoryMutex);
    metaData->removeEntry(!r);
    pthread_mutex_unlock(memoryMutex);
};
/**
 * Se usa para poner un objeto en una vRef en memoria
 */
template<class T> int vHeap::vPlacement(vRef<T> memory, T object) {
    new(*memory) T(object);
    return 0;
};

#endif //_VH2015_VHEAP_H_



