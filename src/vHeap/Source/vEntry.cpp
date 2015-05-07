//
// Created by pablo on 31/03/15.
//

#include "vHeap/Headers/vEntry.h"


/** Constructor 
 * @brief pone en 1 el numero de referencias
*/
vEntry::vEntry() {
    idRef = 0;
    numReferences = 1;
    useFlag = false;
    onHeap = false;
    offset = 0;

}

/**Constructor
 * @brief inicializa las variables segun parametros
 * @param int pIdRef: id referencia
 * @param int pDataSize: tamano del dato
 * @param void *pOffset: direccion de memoria
 */
vEntry::vEntry(int pIdRef, int pDataSize, void *pOffset) {
    idRef = (unsigned int) pIdRef;
    dataSize = (unsigned int) pDataSize;
    offset = pOffset;
    onHeap = true;
    useFlag = false;
}

/**Constructor
 * @brief inicializa las variables segun parametros
 * @param int pIdRef: id referencia
 * @param int pDataSize: tamano del dato
 * @param void *pOffset: direccion de memoria
 * @param bool onHeapParam: bandera que indica si se encuentra en heap
 */
vEntry::vEntry(int pIdRef, int pDataSize, void *pOffset, bool onHeapParam) {
    idRef = (unsigned int) pIdRef;
    dataSize = (unsigned int) pDataSize;
    offset = pOffset;
    onHeap = onHeapParam;
    useFlag = false;
}

/**@brief metodo que se ejecuta cuando una entrada se baja a memoria, pone la bandera en falso y el offset en 0
 */
void vEntry::fileDown(){
    onHeap = false;
    offset = 0;
}

/**@brief metodo que se ejecuta cuando una entrada se sube a memoria
 * @param void* content: nueva direccion
 */
void vEntry::fileUp(void* content){
    onHeap = true;
    offset = content;
}

/**@brief Devuelve la direccion de memoria
 * @return void*
 */
void *vEntry::getOffSet() {
    return offset;
}

/**@brief Devuelve el tamano del dato guardado
 * @return int
 */
int vEntry::getDataSize() {
    return dataSize;
}

/**@brief Devuelve la bandera de uso
 * @return bool
 */
bool vEntry::getUseFlag() {
    return useFlag;
}

/**@brief Devuelve el numero de referencia
 * @return int
 */
int vEntry::getIdRef() {
    return idRef;
}

/**@brief cambia la bandera de uso
 */
void vEntry::changeFlag() {
    if(useFlag == false){
        useFlag = true;
    }else{
        useFlag = false;
    }
}

/**@brief Devuelve el numero de referencias
 * @return unsigned int
 */
unsigned int vEntry::getNumReferences() {
    return numReferences;
}

/** @brief Hace una disminucion en 1 al numero de referencias de una entrada
*           y llama al garbage collector si el numero es igual a 0.
*/
void vEntry::decreaseNumReferences() {
    numReferences--;
    if (numReferences == 0) {
        vGarbageCollector::deallocate(idRef);
    }
}

/** @brief Aumenta en 1 al numero de referencias de una entrada
*/
void vEntry::increaseNumReferences() {
    numReferences++;
}

/**@brief devuelve la bandera que indica si se encuentra en heap
 * @return  bool
 */
bool vEntry::isOnHeap(){
    return onHeap;
}

/**@brief cambia la difeccion de memoria segun el parametro
 * @oaram void* newOffsetParam: nueva direccion
 */
void vEntry::setOffset(void* newOffsetParam){
    if(offset != 0){
        //Si existia un offset previo copia lo que habia en el nuevo
        for(int i = 0; i<dataSize; i++){
            *static_cast<char*>(newOffsetParam+i) = *static_cast<char*>(offset+i);
        }
    }
    //Asigna el offset
    offset = newOffsetParam;
}

/**@brief cambia el numero de referencias
 * @param int numReferencesParam: nuevo numero de referencias
 */
void vEntry::setNumRef(int numReferencesParam){
    numReferences = numReferencesParam;
}

/**@brief cambia el id de referencia
 * @param int newIdRefParam: nuevo ID
 */
void vEntry::setID(int newIdRefParam){
    idRef=newIdRefParam;
}

/**@brief coloca la entrada en valor por defecto
 */
void vEntry::setDefault(){
    numReferences=0;
    onHeap=false;
}

/**@brief metodo que llama al metodo setDefault() de la clase vEntry
 *          se utiliza para la compatibilidad con el arbol
 */
void setDefault(vEntry* entry, void* param){
    entry->setDefault();
}