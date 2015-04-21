//
// Created by roberto on 20/04/15.
//

#include "Container.h"

/** Inicializa el dato en 0
 */
Container::Container(){
    data = 0;
};

/** Libera el dato
 */
Container::~Container(){
    free(data);
};

/** @brief accede al dato
 * @return void*
 */
void* Container::getData(){
    return data;
};

/** Inserta el dato del parametro
 * @param void*
 */
void Container::setData(void* dataParam){
    data = dataParam;
};