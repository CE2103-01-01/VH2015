//
// Created by roberto on 06/04/15.
//

#ifndef VH2015_VARRAY_H
#define VH2015_VARRAY_H
#include "../libs/vheaplib.h"
#include "vHeap/Headers/vRef.h"
#include "vTypes/Headers/vNumber.h"

template <class T> class vArray {
    vRef<long> vSize;
    vRef<void> chunk;
    public:
        vArray(int,int);
        vArray(int);
        ~vArray();
        int operator =(vArray);
        bool operator ==(vArray);
        T* operator [](long);
        long len();
};

/**Constructor
 * @param int len: longitud del arreglo
 */
template <class T> vArray<T>::vArray(int len){
    vSize = vMalloc(sizeof(int));
    vPlacement(vSize, long(len));
    chunk = vMalloc((unsigned int) (sizeof(T) * len));
}

/**Destructor
 */
template <class T> vArray<T>::~vArray(){
    //vFree(chunk);
    //vFree(vSize);
}

/**Operador =
 * @brief Toma los elementos de otro arreglo
 * @return int
 */
template <class T> int vArray<T>::operator =(vArray<T> other){
    //Comprueba la longitud
    if(vSize == other.len()){
        //Itera sobre los elementos
        for(long i = 0; i < **vSize; i+=1){
            //Copia el elemento
            *static_cast<T*>(*chunk + (!i)*sizeof(T)) = *(other[(!i)]);
        }
    }
    //return 0 significa exitoso
    return 0;
}

/**Operador ==
 * @brief Compara con otro array
 * @return bool
 */
template <class T> bool vArray<T>::operator ==(vArray<T> other){
    //Comprueba la longitud
    if(vSize == other.len()){
        //Itera sobre los elementos
        for(long i = 0; i < **vSize; i+=1) {
            //Si un elemento es diferente, retorna falso
            if(!(*static_cast<T*>(*chunk + (!i)*sizeof(T)) == *(other[(!i)]))) return false;
        }
        //Si no encontro elementos diferentes retorna true
        return true;
    }
    return false;
}

/**Operador []: toma un elemento
 * @long pos: posicion a tomar
 */
template <class T> T* vArray<T>::operator [](long pos){
    //Comprueba el rango
    if(**vSize > pos){
        //Retorna el dato
       return  static_cast<T*>((*chunk) + pos*sizeof(T));
    }
    //Si esta fuera de rango aborta
    std::cout << "Error, posicion fuera de rango" << std::endl;
    abort();
}

/**Devuelve la longitud del arreglo
 * @return int
 */
template <class T> long vArray<T>::len(){
    return !**vSize;
}

/**Constructor para matriz i x j
 * @param int i: filas
 * @param int j: columnas
 */
template <class T>
vArray<T>::vArray(int i, int j) {
    vSize = vMalloc(sizeof(int));
    vPlacement(vSize, vInt(i));
    chunk = vMalloc((unsigned int) (sizeof(vArray<T>) * i));
    //Itera sobre los elemtos
    for (int k = 0; k < i; ++k) {
        //Construye los arrays
        vArray<T>* ptr = static_cast<vArray<T>*>((*chunk) + k*sizeof(T));
        new(ptr) vArray<T>(j);
    }
}


#endif //VH2015_VARRAY_H
