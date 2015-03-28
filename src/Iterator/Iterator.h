//
// Created by pablo on 28/03/15.
//

#ifndef VH2015_CONTAINER_H
#define VH2015_CONTAINER_H


template<class T> class Iterator
{
public:
    virtual bool hasNext();
    virtual T next();
};


#endif //VH2015_CONTAINER_H
