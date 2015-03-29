//
// Created by alex on 18/03/15.
//

#ifndef _VH2015_VMALLOCMETADATA_H_
#define _VH2015_VMALLOCMETADATA_H_
#include "vRef.h"
#include <iostream>
class vMallocMetaData {
        int idRef;
        void* offset;
        std::string type;
        int dataSize;
        bool useFlag;
        int counter = 0;

    public:
        vMallocMetaData();
        vMallocMetaData(int,std::string, int, void*);
        ~vMallocMetaData();
        void setId(int id);
        int getId();
        void setOffset(void* offset);
        void* getOffset();
        void setType(std::string);
        std::string getType();
        void setSize(int);
        int getSize();
        void setFlag(bool);
        bool getUseFlag();
        int getCounter();
        void increaseCounter();
        void decreaseCounter();
};

#endif //_VH2015_VMALLOCMETADATA_H_


vMallocMetaData::vMallocMetaData(int dataSize, std::string type,int id,void* offset)
{
    dataSize = dataSize;
    type= type;
    idRef = id;
    offset = offset;
    useFlag = true;
    increaseCounter();
}
vMallocMetaData::vMallocMetaData() {
}

vMallocMetaData::~vMallocMetaData()
{
    decreaseCounter();
}
int vMallocMetaData::getCounter() {
    return counter;
}
void vMallocMetaData::increaseCounter() {
    counter++;
}
void vMallocMetaData::decreaseCounter() {
    counter--;
}
void vMallocMetaData::setId(int id) {
    idRef=id;
}
void vMallocMetaData::setOffset(void* offs) {
    offset=offs;
}
void vMallocMetaData::setSize(int size){
    dataSize= size;
}
void vMallocMetaData::setFlag(bool flag){
    useFlag= flag;
}
void vMallocMetaData::setType(std::string Type){
    type = Type;
}
int vMallocMetaData::getId(){
    return idRef;
}
void* vMallocMetaData::getOffset() {
    return offset;
}
int vMallocMetaData::getSize(){
    return dataSize;
}
bool vMallocMetaData::getUseFlag(){
    return useFlag;
}
std::string vMallocMetaData::getType(){
    return type;
}
