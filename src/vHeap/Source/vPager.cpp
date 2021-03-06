//
// Created by roberto on 04/04/15.
//

#include "vHeap/Headers/vPager.h"

/** Pagina abajo
 * @param: void* data: dato a guardar
 * @param: int id: numero de pagina
 * @param: int dSize: tamaño del dato
 * @brief guarda una pagina formato ".celdmm"
 */
void vPager::pageDown(void *data, int id, int dSize) {
    std::string path = Constants::PAGES_PATH;
    path.append(std::to_string(id));
    path.append(Constants::PAGER_EXTENSION);
    std::ofstream outFile(path, std::ios::binary);
    for(int counter = 0; counter < dSize; counter++) {
        outFile.write(static_cast<const char *>(data + counter), 1);
    }
    outFile.close();
}

/** Pagina arriba
 * @param: void* ret: dato a cargar
 * @param: int id: numero de pagina
 * @param: int retSize: tamaño del dato
 * @brief carga una pagina formato ".celdmm"
 */
void vPager::pageUp(void *ret, int id) {//T(11+6i)
    std::string path = Constants::PAGES_PATH;
    path.append(std::to_string(id));
    path.append(Constants::PAGER_EXTENSION);
    std::ifstream inFile(path, std::ios::binary);
    inFile.read(static_cast<char*>(ret),inFile.precision());
    inFile.close();
}

/** Borra pagina
 * @param: int id: numero de pagina
 * @brief borra una pagina formato ".celdmm"
 */
void vPager::deletePage(int id){
    std::string path = Constants::PAGES_PATH;
    path.append(std::to_string(id));
    path.append(Constants::PAGER_EXTENSION);
    remove(path.c_str());
}