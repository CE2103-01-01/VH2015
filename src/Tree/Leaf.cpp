//
// Created by roberto on 20/04/15.
//

#include "Leaf.h"

/** @brief crea una hoja con n-1 containers, tal que n=treeSize
 */
Leaf::Leaf(Leaf* fatherParam, int treeSizeParam){
    father = fatherParam;
    filledContainers = (int*)(malloc(sizeof(int)));
    *filledContainers = 0;
    filledSons = (int*)(malloc(sizeof(int)));
    *filledSons = 0;
    terminal = (bool*)(malloc(sizeof(bool)));
    *terminal = true;
    containers = malloc((treeSizeParam-1)*sizeof(Container));
};

/** @brief recorre los containers eliminando cada uno
 */
Leaf::~Leaf(){
    free(filledContainers);
    free(filledSons);
    free(terminal);
    free(sons);
    free(containers);
};

/** @brief crea n hojas hijas, tal que n=treeSize
 */
bool Leaf::isTerminal(){
    return *terminal;
};

/** @brief divide la hoja creando hijos
 */
void Leaf::split(int number){
    sons = malloc((number-1)*sizeof(Leaf));
    for(int i=0; i<number; i++){
        new((Leaf*)(sons+i*sizeof(Leaf))) Leaf(this,number);
    }
    *terminal = false;
};

/** @brief inserta un dato en el container indicado
 * @param bool: true si esta lleno
 */
bool Leaf::isFull(int treeSize){
    return (*filledContainers == treeSize-1) && (*filledSons == treeSize);
};

void* Leaf::getSons(){
    return sons;
};

void* Leaf::getContainers(){
    return containers;
};