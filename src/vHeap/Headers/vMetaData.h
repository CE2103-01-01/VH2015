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

class vMetaData {
    int actualID;
    vList<vEntry> *memoryTable;
public:
    vMetaData();
    ~vMetaData();
    vList<vEntry> *getMemoryTable();
    int len();
    void increaseReference(unsigned int idRef);
    void decreaseReference(unsigned int idRef);
    template <class T> vRef<T> addEntry(int,std::string,void*);
    void removeEntry(int idRef);
    void printMetaData();
    vList<vEntry> *operator!();
};


/**
* en la tabla de memoria agrega una entrada y devuelve una nuevca instancia de vRef
*/
template <class T> vRef<T> vMetaData::addEntry(int size, std::string type, void *actualPos) {
    memoryTable->append(vEntry(actualID, size, actualPos));
    return vRef<T>(actualID++);
}


#endif //_VH2015_VMALLOCMETADATA_H_



