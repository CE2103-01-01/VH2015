//
// Created by roberto on 03/04/15.
//

#include "vHeap/Headers/vDefragmenter.h"

/** Construye un defragmentador
 * @param void* initPosParam: posicion inicial del heap
 * @param void* finalPosParam: posicion final del heap
 */
vDefragmenter::vDefragmenter(void* initPosParam, void* finalPosParam){
    initPos = initPosParam;
    finalPos = finalPosParam;
    actualPos = initPos;
    defragmenting = static_cast<bool*>(malloc(sizeof(bool)));
    (*defragmenting) = true;
}

/** Libera la memoria utilizada y coloca punteros en 0
 */
vDefragmenter::~vDefragmenter(){
    initPos = 0;
    finalPos = 0;
    actualPos = 0;
    free(defragmenting);
}

/** Metodo que defragmeta el vHeap
 */
void vDefragmenter::vDefragment() {
    //Toma la memoria
    Tree<vEntry>* tree = vMetaData::getInstance()->getMemoryTree();
    //Recorre el arbol
    for(int i=1; i<= tree->lenght(); i++){
        try{
            //Toma un elemento
            vEntry* tmp = tree->searchElement(i);
            //Comprueba si existe y si esta en heap
            if(tmp!=0 && tmp->getIdRef()!=0 && tmp->isOnHeap()){
                //Si esta cambia la bandera de uso
                tmp->changeFlag();
                //Revisa si esta continuo o tiene espacio en medio
                if(tmp->getOffSet() != actualPos){
                    //Acomoda la memoria
                    tmp->setOffset(actualPos);
                }
                //Cambia la bandera y la posicion actual
                actualPos += tmp->getDataSize();
                tmp->changeFlag();
            }
        }catch(int e){
            std::cout << "Error " << e << std::endl;
            continue;
        }
    };
    //Cambia la posicion actual
    vHeap::getInstance()->setActualPos(actualPos);
    actualPos=initPos;
}

/** Devuelve una bandera que indica si el defragmentador esta activo
 * @return bool
 */
bool vDefragmenter::getDefragmenterFlag() {
    return defragmenting;
}

/**@brief metodo ejecutado por el pthread
 * @param void* defragmenterObjParam: defragmentador
 * @return void* 0
 */
void* vDefragmentThread(void* defragmenterObjParam){
    //Crea estructura de tiempo
    struct timespec timeController;
    timeController.tv_nsec = 0;
    timeController.tv_sec = Constants::DEFRAGMENTER_FRECUENCY;
    //Siempre que la bandera de defragmetar sea verdader
    while(static_cast<vDefragmenter*>(defragmenterObjParam)->getDefragmenterFlag()){
        //Espera
        nanosleep(&timeController,0);
        //Bloquea mutex
        pthread_mutex_lock(vMetaData::getInstance()->getMutex());
        //Llama al metodo que defragmenta
        static_cast<vDefragmenter*>(defragmenterObjParam)->vDefragment();
        //Desbloquea mutex
        pthread_mutex_unlock(vMetaData::getInstance()->getMutex());
    };
    return defragmenterObjParam;
}