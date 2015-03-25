#ifndef METADATA_H
#define METADATA_H

#include <stdlib.h>

class Metadata
{
    int* refID;
    int* refSize;
    void* refAdd;
    public:
        Metadata(int, int, void*);
        virtual ~Metadata();
        int getRefID();
        int getRefSize();
        void print();
};

Metadata::Metadata(int id, int s, void* add)
{
    refID=static_cast<int*>(malloc(sizeof(int)));
    *refID=id;
    refAdd=add;
    refSize=static_cast<int*>(malloc(sizeof(int)));
    *refSize=s;
};

Metadata::~Metadata()
{

};

int Metadata::getRefID() {
    return *refID;
};

int Metadata::getRefSize() {
    return *refSize;
};

void Metadata::print(){
    std::cout<<"ID: "<<*refID<<"Size: "<<*refSize<<"Address: "<<refAdd<<std::endl;
};

#endif // METADATA_H
