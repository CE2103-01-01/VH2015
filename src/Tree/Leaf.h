//
// Created by roberto on 20/04/15.
//

#ifndef VH2015_LEAF_H
#define VH2015_LEAF_H

#include <malloc.h>
#include "Constants.h"
#include <iostream>

/** @brief miembro del arbol
 * Numero de hijos: n, tal que n=treeSize 
 * Numero de containers: n-1
 */
class Leaf{
    int* sizeofType;
    void* containers;
    Leaf* sons;
    bool* terminal;                 //Bandera que indica si es terminal: true=sin hijos
public:
    Leaf(int, int);
    ~Leaf();
    Leaf* getSons();
    void* getContainers();
    bool isTerminal();
    void split();
};

#endif //VH2015_LEAF_H
