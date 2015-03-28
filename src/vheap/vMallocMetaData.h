//
// Created by alex on 18/03/15.
//

#ifndef _VH2015_VMALLOCMETADATA_H_
#define _VH2015_VMALLOCMETADATA_H_
#include "vRef.h"
#include <iostream>
class vMallocMetaData {
        int idRef;
        int offset;
        std::string type;
        int dataSize;
        bool useFlag;
        int counter = 0;

    public:
        vMallocMetaData();
        vMallocMetaData(int,std::string, int, int);
        ~vMallocMetaData();
        void setId(int id);
        int getId();
        void setOffset(int offset);
        int getOffset();
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
