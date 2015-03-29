//
// Created by pablo on 28/03/15.
//

#include "vMallocMetaData.h"

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
