// Created by alex on 18/03/15.
//

#ifndef _VH2015_VMETADATA_H_
#define _VH2015_VMETADATA_H_

#include <iostream>
#include "Tree/Tree.h"
#include "vTypes/Headers/vList.h"
#include "vEntry.h"
#include "vPager.h"
#include <pthread.h>
#include <cstdlib>
#include <stdlib.h>
#include <stdio.h>

static const unsigned int initialId = 1;

class vEntry;

class vMetaData {
private:
    static vMetaData *vMDSingleton;
    long* vSize;
    unsigned int actualID;
    Tree<vEntry>* memoryTree;
    vList<unsigned int>* deletedIDS;
    pthread_mutex_t* memoryMutex;

public:
    static vMetaData *getInstance();
    vMetaData();
    ~vMetaData();
    Tree<vEntry>* getMemoryTree();
    void increaseReference(unsigned int idRef);
    void decreaseReference(unsigned int idRef);
    unsigned int addEntry(int, void*);
    void removeEntry(int idRef);
    void printMetaData();
    pthread_mutex_t* getMutex();
    void* de_vReference(int);
    vEntry* searchToPage(int);
    long getHeapUse();
    void setPager(vPager*);
    void cleanChunk(int, void*);
    int len();
};

#endif //_VH2015_VMETADATA_H_



