//
// Created by alex on 18/03/15.
//

#ifndef _VH2015_VMALLOCMETADATA_H_
#define _VH2015_VMALLOCMETADATA_H_
#include "vRef.h"
#include "vTypes/Headers/vList.h"
#include <iostream>
#include <typeinfo>

class vMallocMDEntry;
class vRef;
class vMallocMetaData {
private:
    int counter = 0;
    int actualID = 0;
    vList <vMallocMDEntry>* memoryTable;
public:
    vMallocMetaData();
    ~vMallocMetaData();
    vList <vMallocMDEntry>* getMemoryTable();
    int len();
    void increaseCounter();
    void decreaseCounter();
    vRef addEntry(int,std::string,void*);
    void printMetaData();
    vList <vMallocMDEntry>* operator !();
};

class vMallocMDEntry
{
private:
    int idRef =0;
    void* offset =0;
    //std::type_info typeInfo;
    int dataSize = 0;
    bool useFlag = false;
public:
    vMallocMDEntry();
    vMallocMDEntry(int, int, void*);
    int getIdRef();
    void* getOffSet();
   // std::type_info getTypeInfo();
    int getDataSize();
    bool getUseFlag();

};

#endif //_VH2015_VMALLOCMETADATA_H_


