// Created by alex on 18/03/15.
//

#ifndef _VH2015_VMALLOCMETADATA_H_
#define _VH2015_VMALLOCMETADATA_H_

static const unsigned int initialId = 1;


#include "vEntry.h"


#include <iostream>
#include <vTypes/Headers/vList.h>


class vMetaData {
    unsigned int actualID = initialId;
    vList<vEntry> *memoryTable;
    vList<unsigned int> *deletedIDS;
public:
    vMetaData();
    ~vMetaData();
    vList<vEntry> *getMemoryTable();
    int len();
    void increaseReference(unsigned int idRef);
    void decreaseReference(unsigned int idRef);

    unsigned int addEntry(int, void *);
    void removeEntry(int idRef);
    void printMetaData();
    vList<vEntry> *operator!();
};



#endif //_VH2015_VMALLOCMETADATA_H_



