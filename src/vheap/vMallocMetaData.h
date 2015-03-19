//
// Created by alex on 18/03/15.
//

#ifndef _VH2015_VMALLOCMETADATA_H_
#define _VH2015_VMALLOCMETADATA_H_
#include <string>
#include "vRef.h"
#include <iostream>
using namespace std;

class vMallocMetaData {
public:
    vMallocMetaData();
    vMallocMetaData(int size,string type, int* id, int* offset);
    ~vMallocMetaData();
    void setId(int* id);
    int* getId();
    void setOffset(int* offset);
    int* getOffset();
    void setType(string type);
    string getType();
    void setSize(int datSize);
    int getSize();
    void setFlag(bool flag);
    bool getUseFlag();
    int getCounter();
    void increaseCounter();
    void decreaseCounter();

private:
    int* idRef;
    int* offset;
    string type;
    int dataSize;
    bool useFlag;
    int counter = 0;

};


#endif //_VH2015_VMALLOCMETADATA_H_
