//
// Created by alex on 18/03/15.
//

#include "vMallocMetaData.h"

vMallocMetaData::vMallocMetaData(int dataSize, string type,vRef* id,vRef* offset)
{
    vMallocMetaData::dataSize = DataSize;
    vMallocMetaData::type= type;
    vMallocMetaData::idRef = id;
    vMallocMetaData::offset = offset;
    vMallocMetaData::useFlag = true;
    vMallocMetaData::counter = 1;
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
void vMallocMetaData::setId(vRef id){
    idRef = id;
}
void vMallocMetaData::setOffset(vRef Offset){
    offset = Offset;
}
void vMallocMetaData::setSize(int dataSize){
    DataSize= dataSize;
}
void vMallocMetaData::setFlag(bool flag){
    useFlag= flag;
}
void vMallocMetaData::setType(vType Type){
    type = Type;
}
int* vMallocMetaData::getId(){
    return idRef;
}
int* vMallocMetaData::getOffSet(){
    return offset;
}
int vMallocMetaData::getSize(){
    return dataSize;
}
bool vMallocMetaData::getUseFlag(){
    return useFlag;
}
vType vMallocMetaData::getType(){
    return type;
}


