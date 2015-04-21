//
// Created by roberto on 20/04/15.
//

#include "Leaf.h"

/** @brief crea una hoja con n-1 containers, tal que n=treeSize
 */
Leaf::Leaf(int treeSizeParam,int sizeofTypeParam){
    sizeofType = (int*)(malloc(sizeof(int)));
    *sizeofType = sizeofTypeParam;
    terminal = (bool*)(malloc(sizeof(bool)));
    *terminal = true;
    containers = malloc((treeSizeParam)*sizeof(sizeofType));
};

/** @brief recorre los containers eliminando cada uno
 */
Leaf::~Leaf(){
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
    sons = malloc((number)*sizeof(Leaf));
    for(int i=0; i<number; i++){
        new(static_cast<Leaf*>(sons+i*sizeof(Leaf))) Leaf(number, *sizeofType);
    }
    *terminal = false;
};

void* Leaf::getSons(){
    return sons;
};

void* Leaf::getContainers(){
    return containers;
};