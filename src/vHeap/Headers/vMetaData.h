// Created by alex on 18/03/15.
//

#ifndef _VH2015_VMETADATA_H_
#define _VH2015_VMETADATA_H_

#include <iostream>
#include <vTypes/Headers/vList.h>
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
    int vSize;
    unsigned int actualID;
    vList<vEntry>* memoryTable;
    vList<unsigned int>* deletedIDS;
    pthread_mutex_t* memoryMutex;
    pthread_cond_t* dfragCond;
    vPager* pager;

public:
    static vMetaData *getInstance();
    vMetaData();
    ~vMetaData();
    vList<vEntry>* getMemoryTable();
    int len();
    void increaseReference(unsigned int idRef);
    void decreaseReference(unsigned int idRef);
    unsigned int addEntry(int, void *);
    void removeEntry(int idRef);
    void printMetaData();
    vList<vEntry>* operator!();
    pthread_mutex_t* getMutex();
    pthread_cond_t* getDefragmenterCond();
    void* de_vReference(int);
    vEntry* searchToPage(int);
    int getHeapUse();
    void setPager(vPager*);
    void cleanChunk(int, void*);
};

#endif //_VH2015_VMETADATA_H_



