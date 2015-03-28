//
// Created by alex on 18/03/15.
//

#include "vMallocMetaData.h"

vMallocMetaData::vMallocMetaData(int dataSize, std::string type,int id,int offset)
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
    if(vMallocMetaData::counter==0){
        delete this;
    }
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
void vMallocMetaData::setOffset(int Offset) {
    offset=Offset;
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
int vMallocMetaData::getOffset() {
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