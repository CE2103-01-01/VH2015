//
// Created by roberto on 06/05/15.
//

#include "../Headers/vCleaner.h"

/** Borra los archivos de un directorio
 */
void vCleaner::clean(std::string folderPath){
    //Abre el folder
    DIR* folder = opendir(folderPath.c_str());
    struct dirent* nextFile;
    while(nextFile = readdir(folder)){
        //Crea un temporal
        char dataPath[256];
        //Toma la ruta
        sprintf(dataPath,"%s%s", folderPath.c_str(), nextFile->d_name);
        //Elimina el archivo
        remove(dataPath);
    }
}