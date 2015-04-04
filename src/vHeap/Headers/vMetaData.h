// Created by alex on 18/03/15.
//

#ifndef _VH2015_VMALLOCMETADATA_H_
#define _VH2015_VMALLOCMETADATA_H_

static const unsigned int initialId = 1;

#include "vEntry.h"

#include "vTypes/Headers/vList.h"
#include <iostream>
#include <typeinfo>
#include "vRef.h"

template <class T> class vRef;
class vEntry;

class vMetaData {
    unsigned int actualID;
    vList<vEntry> *memoryTable;
    vList<unsigned int> *deletedIDS;
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
    if(deletedIDS->len()==0){
        memoryTable->append(vEntry(actualID, size, actualPos));
        return vRef<T>(actualID++);
    }else{
        int id = *(deletedIDS->get(0));
        deletedIDS->deleteNode(0);
        memoryTable->append(vEntry(id, size, actualPos));
        return vRef<T>(id);
    };
}


#endif //_VH2015_VMALLOCMETADATA_H_



