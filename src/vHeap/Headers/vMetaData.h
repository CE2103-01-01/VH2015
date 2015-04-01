//
// Created by alex on 18/03/15.
//

#ifndef _VH2015_VMALLOCMETADATA_H_
#define _VH2015_VMALLOCMETADATA_H_

#include "vEntry.h"

#include "vTypes/Headers/vList.h"
#include <iostream>
#include <typeinfo>
#include "vRef.h"

class vEntry;
class vRef;

class vMetaData {
private:
    int actualID;
    vList<vEntry> *memoryTable;
public:
    vMetaData();

    ~vMetaData();

    vList<vEntry> *getMemoryTable();
    int len();

    void increaseReference(unsigned int idRef);

    void decreaseReference(unsigned int idRef);
    vRef addEntry(int,std::string,void*);

    void removeEntry(int idRef);
    void printMetaData();

    vList<vEntry> *operator!();
};


#endif //_VH2015_VMALLOCMETADATA_H_



