//
// Created by alex on 18/03/15.
//

#ifndef _VH2015_VMALLOCMETADATA_H_
#define _VH2015_VMALLOCMETADATA_H_
#include "vRef.h"
#include "List.h"
#include <iostream>
class vMallocMDEntry;
class vMallocMetaData {
private:
    int counter = 0;
    int actualID = 0;
    List<vMallocMDEntry>* memoryTable;
public:
    vMallocMetaData();
    ~vMallocMetaData();
    int len();
    void increaseCounter();
    void decreaseCounter();
    vRef addEntry(int,std::string,void*);
    void printMetaData();
};

class vMallocMDEntry
{
private:
    int idRef =0;
    void* offset =0;
    int dataSize = 0;
    bool useFlag = false;
public:
    vMallocMDEntry(int, int, void*);
    int getIdRef();
    void* getOffSet();
    int getDataSize();
    bool getUseFlag();

};

#endif //_VH2015_VMALLOCMETADATA_H_



