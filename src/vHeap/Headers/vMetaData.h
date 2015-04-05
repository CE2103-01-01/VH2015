// Created by alex on 18/03/15.
//

#ifndef _VH2015_VMALLOCMETADATA_H_
#define _VH2015_VMALLOCMETADATA_H_

static const unsigned int initialId = 1;

#include <iostream>
#include <vTypes/Headers/vList.h>
#include "vEntry.h"
#include "vPager.h"
#include <pthread.h>
#include <cstdlib>
#include <stdlib.h>
#include <stdio.h>

class vMetaData {
    int vSize;
    unsigned int actualID = initialId;
    vList<vEntry>* memoryTable;
    vList<unsigned int>* deletedIDS;
    static vMetaData* single;
    static pthread_mutex_t* memoryMutex;
    static pthread_cond_t* dfragCond;
public:
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
    static vMetaData* getInstance();
    static pthread_mutex_t* getMutex();
    static pthread_cond_t* getDefragmenterCond();
    void* de_vReference(int, vPager*);
    vEntry* searchToPage(int);
    int getHeapUse();
};



#endif //_VH2015_VMALLOCMETADATA_H_



