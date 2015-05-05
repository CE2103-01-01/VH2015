//
// Created by roberto on 20/04/15.
//

#include "Leaf.h"

/** @brief crea una hoja con n-1 containers, tal que n=treeSize
 */
Leaf::Leaf(int treeSizeParam,int sizeofTypeParam){
    sizeofType = static_cast<int*>(malloc(sizeof(int)));
    *sizeofType = sizeofTypeParam;
    terminal = static_cast<bool*>(malloc(sizeof(bool)));
    *terminal = true;
    containers = malloc(treeSizeParam*sizeofTypeParam);
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
void Leaf::split(){
    sons = static_cast<Leaf*>(malloc(TREE_SIZE*sizeof(Leaf)));
    for(int i=0; i<TREE_SIZE; i++){
        new(sons+i) Leaf(TREE_SIZE, *sizeofType);
    }
    *terminal = false;
};

/** Retorna las hojas hijas
 * @return sons
 */
Leaf* Leaf::getSons(){
    return sons;
};

/** Retorna los contenedores
 * @return void*
 */
void* Leaf::getContainers(){
    return containers;
};