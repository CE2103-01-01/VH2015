//
// Created by roberto on 20/04/15.
//

#ifndef VH2015_LEAF_H
#define VH2015_LEAF_H

#include <cstdlib>
#include <iostream>

/** @brief miembro del arbol
 * Numero de hijos: n, tal que n=treeSize 
 * Numero de containers: n-1
 */
class Leaf{
    int* sizeofType;
    void* containers;
    void* sons;
    bool* terminal;                 //Bandera que indica si es terminal: true=sin hijos
public:
    Leaf(int, int);
    ~Leaf();
    void* getSons();
    void* getContainers();
    bool isTerminal();
    bool isFull(int);
    void split(int);
    Leaf* getFather();
    int len();
};

#endif //VH2015_LEAF_H
