//
// Created by roberto on 20/04/15.
//

#ifndef VH2015_CONTAINER_H
#define VH2015_CONTAINER_H

#include <cstdlib>

class Container{
    void* data;
public:
    Container();
    ~Container();
    void* getData();
    void setData(void*);
};

#endif //VH2015_CONTAINER_H
