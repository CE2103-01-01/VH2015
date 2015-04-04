// Created by alex on 18/03/15.
//

#ifndef _VH2015_VMALLOCMETADATA_H_
#define _VH2015_VMALLOCMETADATA_H_

static const unsigned int initialId = 1;

#include "vEntry.h"

#include "vTypes/Headers/vList.h"
#include <iostream>
#include <typeinfo>


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

    unsigned int addEntry(int, void *);
    void removeEntry(int idRef);
    void printMetaData();
    vList<vEntry> *operator!();
};


/**
* en la tabla de memoria agrega una entrada y devuelve un int de la posicion
*/
unsigned int vMetaData::addEntry(int size, void *actualPos) {
    if(deletedIDS->len()==0){
        memoryTable->append(vEntry(actualID, size, actualPos));
        return actualID++;
    }else{
        int id = *(deletedIDS->get(0));
        deletedIDS->deleteNode(0);
        memoryTable->append(vEntry(id, size, actualPos));
        return id;
    };
}


#endif //_VH2015_VMALLOCMETADATA_H_



