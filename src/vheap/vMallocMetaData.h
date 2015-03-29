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
    vRef addEntry(int sizes,std::string typei, void* actualPos);
    void printMetaData();
};

class vMallocMDEntry
{
private:
    int idRef;
    void* offset;
    std::string type;
    int dataSize;
    bool useFlag;
public:
    vMallocMDEntry(int idRef, std::string &type, int dataSize, void *offset);
    int getIdRef();
    void* getOffSet();
    std::string getType();
    int getDataSize();
    bool getUseFlag();

};

#endif //_VH2015_VMALLOCMETADATA_H_



