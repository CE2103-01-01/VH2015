//
// Created by roberto on 20/04/15.
//

#ifndef VH2015_LEAF_H
#define VH2015_LEAF_H

#include "Container.h"
#include <cstdlib>

/** @brief miembro del arbol
 * Numero de hijos: n, tal que n=treeSize 
 * Numero de containers: n-1
 */
class Leaf{
    int* filledContainers;          //Numero de contenedores llenos
    int* filledSons;                //Numero de contenedores llenos
    void* containers;
    void* sons;
    Leaf* father;                   //Hoja padre
    bool* terminal;                 //Bandera que indica si es terminal: true=sin hijos
public:
    Leaf(Leaf*, int);
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
