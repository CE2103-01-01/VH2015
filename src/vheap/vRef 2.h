#ifndef VREF_H_INCLUDED
#define VREF_H_INCLUDED

#include <stdlib.h>

class vRef{
    int* refNumber;
    public:
    vRef(int);
    ~vRef();
};

/** @brief Constructor
*
*/
vRef::vRef(int r){
    refNumber=static_cast<int*>(malloc(sizeof(int)));
    *refNumber=r;
};

/** @brief Destructor
*
*/
vRef::~vRef(){
    free(refNumber);
};

#endif // VREF_H_INCLUDED
