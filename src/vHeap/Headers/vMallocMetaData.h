//
// Created by alex on 18/03/15.
//

#ifndef _VH2015_VMALLOCMETADATA_H_
#define _VH2015_VMALLOCMETADATA_H_

#include "vMallocMDEntry.h"

#include "vTypes/Headers/vList.h"
#include <iostream>
#include <typeinfo>
#include "vRef.h"

class vMallocMDEntry;
class vRef;
class vMallocMetaData {
private:
    int actualID;
    vList <vMallocMDEntry>* memoryTable;
public:
    vMallocMetaData();
    ~vMallocMetaData();
    vList <vMallocMDEntry>* getMemoryTable();
    int len();

    void increaseReference(unsigned int idRef);

    void decreaseReference(unsigned int idRef);
    vRef addEntry(int,std::string,void*);
    void printMetaData();
    vList <vMallocMDEntry>* operator !();
};


#endif //_VH2015_VMALLOCMETADATA_H_



