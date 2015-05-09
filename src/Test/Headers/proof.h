//
// Created by roberto on 17/04/15.
//

#ifndef VH2015_PROOF_H
#define VH2015_PROOF_H

#include "../../vTypes/Headers/vArray.h"
#include "../../vHeap/Headers/vRef.h"
#include "../../vTypes/Headers/vString.h"
#include "../../vTypes/Headers/vSimpleList.h"
#include "../../vTypes/Headers/vDoubleList.h"
#include "../../vTypes/Headers/vNumber.h"
#include "../../vHeap/Headers/vPager.h"
#include "../../Tree/Tree.h"

#define SIZE_OF_ARRAY_AND_LIST 1000
#define SIZE_OF_CHAR_ARRAY 95
#define NULL_OFFSET 0
#define FLOAT_OFFSET 0.5
#define LONG_OFFSET 100000000
#define FIRST_ASCII_CHAR 32
#define NUMBER_OF_CONTAINERS_TO_FILL 10000

void pruebaTree();
void pruebaString();
template <class NumericType> void prueba_vNumber_con_vArray(int,float);
void begin();

#endif //VH2015_PROOF_H