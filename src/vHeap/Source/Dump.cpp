//
// Created by roberto on 05/04/15.
//

#include <sys/stat.h>
#include <Constants.h>
#include "vHeap/Headers/Dump.h"
using namespace pugi;

/** Construye un objeto de dump
 * 
 */
Dump::Dump() {
    counter = static_cast<int*>(malloc(sizeof(int)));
    (*counter) = 0;
    frecuency = static_cast<int*>(malloc(sizeof(int)));
    (*frecuency) = 1;
    dumpping = static_cast<bool*>(malloc(sizeof(bool)));
    (*dumpping) = true;
}

/** Destruye un objeto de dump
 */
Dump::~Dump() {
    free(counter);
    free(frecuency);
    free(dumpping);
}

/** Devuelve el estado de dump
 * @return bool
 */
bool Dump::getDumppingState(){
    return (*dumpping);
}

/** Devuelve el estado de dump
 */
void Dump::changeDumppingState(){
    (*dumpping) = !(*dumpping);
}

/**Guarda un archivo de dump
 */
void Dump::saveDumpFile() {

    std::ofstream myfile(Constants::DUMPS_PATH + Constants::DUMP_FILE +std::to_string(*counter) + Constants::TXT);
    Tree<vEntry>* tree = vMetaData::getInstance()->getMemoryTree();
    xml_document doc;
    doc.load_file(Constants::xmlPath);
    myfile << "Total size of Memory: "
           <<doc.child(Constants::PROJECT_NAME).child(Constants::V_HEAP).attribute(Constants::SIZE_STR).as_int()
           <<std::endl;
    for(int i=1; i<tree->max(); i++){
        try{
            if(tree->searchElement(i)->getIdRef()!=0) {
                myfile << "The file is on heap: " << tree->searchElement(i)->isOnHeap() << "\n";
                myfile << "Memory direction: " << tree->searchElement(i)->getOffSet() << "\n";
                myfile << "Size of data containing: " << tree->searchElement(i)->getDataSize() << "\n";
                myfile << "flag in use: " << tree->searchElement(i)->getUseFlag() << "\n";
            }
        }catch(int e){
            continue;
        }
    }
    (*counter)++;
    myfile.close();
}

/** Devuelve la frecuencia de dump
 * @return int
 */
int Dump::getFrecuency() {
    return (*frecuency);
}

/** Metodo que llamara el pthread, llama al metodo saveDumpFile()
 * @return void*: 0
 */
void* dump(void* dumpObjParam){
    //Crea el controlador de tiempo
    struct timespec timeController;
    timeController.tv_nsec = 0;
    timeController.tv_sec = static_cast<Dump*>(dumpObjParam)->getFrecuency();
    //Realiza dumps mientras este activo
    while(static_cast<Dump*>(dumpObjParam)->getDumppingState()){
        //Espera
        nanosleep(&timeController,0);
        //Bloquea el mutex
        pthread_mutex_lock(vMetaData::getInstance()->getMutex());
        //Realiza un dump
        static_cast<Dump*>(dumpObjParam)->saveDumpFile();
        //Desbloquea el mutex
        pthread_mutex_unlock(vMetaData::getInstance()->getMutex());
    }
    return dumpObjParam;
}
