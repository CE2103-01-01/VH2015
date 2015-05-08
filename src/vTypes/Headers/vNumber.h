//
// Created by roberto on 08/05/15.
//

#ifndef VH2015_VNUMBER_H
#define VH2015_VNUMBER_H

#include "vHeap/Headers/vRef.h"
#include "../libs/vheaplib.h"

void vFree(int toFree);
unsigned int vMalloc(unsigned int);
template<class T> void vFree(vRef<T> toFree);
template<class T> int vPlacement(vRef<T> vR, T toPlace);

template <class NumericType> class vNumber {
    vRef<NumericType> data;
public:
    vNumber();
    vNumber(const vNumber&);
    vNumber(vNumber&&);
    vNumber(NumericType);
    ~vNumber();
    NumericType operator !();
    void operator --();
    void operator ++();
    vNumber<NumericType> operator +(vNumber<NumericType>);
    vNumber<NumericType> operator +(NumericType);
    vNumber<NumericType> operator -(vNumber<NumericType>);
    vNumber<NumericType> operator -(NumericType);
    vNumber<NumericType> operator *(vNumber<NumericType>);
    vNumber<NumericType> operator *(NumericType);
    vNumber<NumericType> operator /(vNumber<NumericType>);
    vNumber<NumericType> operator /(NumericType);
    void operator +=(vNumber<NumericType>);
    void operator +=(NumericType);
    void operator -=(vNumber<NumericType>);
    void operator -=(NumericType);
    void operator *=(vNumber<NumericType>);
    void operator *=(NumericType);
    void operator /=(vNumber<NumericType>);
    void operator /=(NumericType);
    void operator =(vNumber<NumericType>);
    void operator =(NumericType);
    bool operator <(vNumber<NumericType>);
    bool operator <(NumericType);
    bool operator <=(vNumber<NumericType>);
    bool operator <=(NumericType);
    bool operator >(vNumber<NumericType>);
    bool operator >(NumericType);
    bool operator >=(vNumber<NumericType>);
    bool operator >=(NumericType);
    bool operator ==(vNumber<NumericType>);
    bool operator ==(NumericType);
    bool operator !=(vNumber<NumericType>);
    bool operator !=(NumericType);
};

/**@brief Construye un vNumber<NumericType> inicializando su dato con un vMalloc y un vPlacement de 0.
 */
template<class NumericType> vNumber<NumericType>::vNumber(){
    data = vMalloc(sizeof(NumericType));
    vPlacement(data,(NumericType)0);
}

/**@brief Construye un vNumber<NumericType> inicializando su dato con un vMalloc y un vPlacement.
 */
template<class NumericType> vNumber<NumericType>::vNumber(const vNumber<NumericType>& other){
    data = vMalloc(sizeof(NumericType));
    vRef<NumericType> ref= other.data;
    vPlacement(data, **ref);
}

/**@brief Construye un vNumber<NumericType> inicializando su dato con un vMalloc y un vPlacement.
 */
template<class NumericType> vNumber<NumericType>::vNumber(vNumber<NumericType>&& other){
    data = vMalloc(sizeof(NumericType));
    vPlacement(data,**other.data);
}

/**@brief Crea un vNumber<NumericType> inicializando su dado con un vMalloc y un vPlacement del parametro recibido.
 * @param NumericType dataParam: dato a insertar
 */
template<class NumericType> vNumber<NumericType>::vNumber(NumericType dataParam){
    data = vMalloc(sizeof(NumericType));
    vPlacement(data,dataParam);
}

/**@brief Destructor.
 */
template<class NumericType> vNumber<NumericType>::~vNumber(){
    vFree(data);
}

/**@brief Devuelve el dato envuelto por la clase
* @return NumericType
*/
template<class NumericType> NumericType vNumber<NumericType>::operator !(){
    return (**data);
}

/**@brief Suma el parametro al dato contenido en la clase, devolviendola modificada
* @param vNumber<NumericType> param: dato a sumar
* @return vNumber<NumericType>: la clase con la suma
*/
template<class NumericType> vNumber<NumericType> vNumber<NumericType>::operator +(vNumber<NumericType> param){
    (**data) += !param;
    return *this;
}

/**@brief Resta el parametro al dato contenido en la clase, devolviendola modificada
* @param vNumber<NumericType> param: dato a restar
* @return vNumber<NumericType>: la clase con la resta
*/
template<class NumericType> vNumber<NumericType> vNumber<NumericType>::operator -(vNumber<NumericType> param){
    (**data) -= !param;
    return *this;
}

/**@brief Multiplica por el parametro al dato contenido en la clase, devolviendola modificada
* @param vNumber<NumericType> param: dato a multiplicar
* @return vNumber<NumericType>: la clase con la multiplicacion
*/
template<class NumericType> vNumber<NumericType> vNumber<NumericType>::operator *(vNumber<NumericType> param){
    (**data) *= !param;
    return *this;
}

/**@brief Divide por el parametro al dato contenido en la clase, devolviendola modificada
* @param vNumber<NumericType> param: dato a dividr
* @return vNumber<NumericType>: la clase con la division
*/
template<class NumericType> vNumber<NumericType> vNumber<NumericType>::operator /(vNumber<NumericType> param){
    (**data) /= !param;
    return *this;
}

/**@brief Suma al dato, el parametro recibido
* @param vNumber<NumericType> param: dato a sumar
*/
template<class NumericType> void vNumber<NumericType>::operator +=(vNumber<NumericType> param){
    (**data) += !param;
}

/**@brief Resta al dato, el parametro recibido
* @param vNumber<NumericType> param: dato a resar
*/
template<class NumericType> void vNumber<NumericType>::operator -=(vNumber<NumericType> param){
    (**data) -= !param;
}

/**@brief Multiplica al dato por el parametro recibido
* @param vNumber<NumericType> param: dato a multiplicar
*/
template<class NumericType> void vNumber<NumericType>::operator *=(vNumber<NumericType> param){
    (**data) *= !param;
}

/**@brief Divide al dato por el parametro recibido
* @param vNumber<NumericType> param: divisor
*/
template<class NumericType> void vNumber<NumericType>::operator /=(vNumber<NumericType> param){
    (**data) /= !param;
}

/**@brief Suma el parametro al dato contenido en la clase, devolviendola modificada
* @param NumericType param: dato a sumar
* @return NumericType: la clase con la suma
*/
template<class NumericType> vNumber<NumericType> vNumber<NumericType>::operator +(NumericType param){
    (**data) += param;
    return *this;
}

/**@brief Resta el parametro al dato contenido en la clase, devolviendola modificada
* @param NumericType param: dato a restar
* @return NumericType: la clase con la resta
*/
template<class NumericType> vNumber<NumericType> vNumber<NumericType>::operator -(NumericType param){
    (**data) -= param;
    return *this;
}

/**@brief Multiplica por el parametro al dato contenido en la clase, devolviendola modificada
* @param NumericType param: dato a multiplicar
* @return NumericType: la clase con la multiplicacion
*/
template<class NumericType> vNumber<NumericType> vNumber<NumericType>::operator *(NumericType param){
    (**data) *= param;
    return *this;
}

/**@brief Divide por el parametro al dato contenido en la clase, devolviendola modificada
* @param NumericType param: dato a dividr
* @return NumericType: la clase con la division
*/
template<class NumericType> vNumber<NumericType> vNumber<NumericType>::operator /(NumericType param){
    (**data) /= param;
    return *this;
}

/**@brief Suma al dato, el parametro recibido
* @param NumericType param: dato a sumar
*/
template<class NumericType> void vNumber<NumericType>::operator +=(NumericType param){
    (**data) += param;
}

/**@brief Resta al dato, el parametro recibido
* @param NumericType param: dato a resar
*/
template<class NumericType> void vNumber<NumericType>::operator -=(NumericType param){
    (**data) -= param;
}

/**@brief Multiplica al dato por el parametro recibido
* @param NumericType param: dato a multiplicar
*/
template<class NumericType> void vNumber<NumericType>::operator *=(NumericType param){
    (**data) *= param;
}

/**@brief Divide al dato por el parametro recibido
* @param NumericType param: divisor
*/
template<class NumericType> void vNumber<NumericType>::operator /=(NumericType param){
    (**data) /= param;
}

/**@brief Asigna un nuevo valor al contenido de la clase
* @param vNumber<NumericType> param: variable a sumar
*/
template<class NumericType> void vNumber<NumericType>::operator =(vNumber<NumericType> param){
    if((!data) != 0){
        vPlacement(data, !param);
    }else{
        data = vMalloc(sizeof(NumericType));
        vPlacement(data, !param);
    }
}

/**@brief Compara dos vNumber<NumericType>
* @param vNumber<NumericType> other: numero a comparar
* @return bool: true si la clase es menor que el parámetro
*/
template<class NumericType> bool vNumber<NumericType>::operator <(vNumber<NumericType> other){
    return (**data) < (!other);
}

/**@brief Compara dos vNumber<NumericType>
* @param vNumber<NumericType> other: numero a comparar
* @return bool: true si la clase es menor o igual que el parámetro
*/
template<class NumericType> bool vNumber<NumericType>::operator <=(vNumber<NumericType> other){
    return (**data) <= (!other);
}

/**@brief Compara dos vNumber<NumericType>
* @param vNumber<NumericType> other: numero a comparar
* @return bool: true si la clase es mayor que el parámetro
*/
template<class NumericType> bool vNumber<NumericType>::operator >(vNumber<NumericType> other){
    return (**data) > (!other);
}

/**@brief Compara dos vNumber<NumericType>
* @param vNumber<NumericType> other: numero a comparar
* @return bool: true si la clase es mayor o igual que el parámetro
*/
template<class NumericType> bool vNumber<NumericType>::operator >=(vNumber<NumericType> other){
    return (**data) >= (!other);
}

/**@brief Compara dos vNumber<NumericType>
* @param vNumber<NumericType> other: numero a comparar
* @return bool: true si la clase igual que el parámetro
*/
template<class NumericType> bool vNumber<NumericType>::operator ==(vNumber<NumericType> other){
    return (**data) == (!other);
}


/**@brief Compara dos vNumber<NumericType>
* @param vNumber<NumericType> other: numero a comparar
* @return bool: true si la clase es diferente que el parámetro
*/
template<class NumericType> bool vNumber<NumericType>::operator !=(vNumber<NumericType> other){
    return (**data) != (!other);
}

/**@brief Compara dos vNumber<NumericType>
* @param vNumber<NumericType> other: numero a comparar
* @return bool: true si la clase es igual que el parámetro
*/
template<class NumericType> void vNumber<NumericType>::operator =(NumericType param){
    if((!data) != 0){
        vPlacement(data, param);
    }else{
        data = vMalloc(sizeof(NumericType));
        vPlacement(data, param);
    }
}

/**@brief Compara dos vNumber<NumericType>
* @param NumericType other: numero a comparar
* @return bool: true si la clase es menor que el parámetro
*/
template<class NumericType> bool vNumber<NumericType>::operator <(NumericType other){
    return (**data) < other;
}

/**@brief Compara dos vNumber<NumericType>
* @param NumericType other: numero a comparar
* @return bool: true si la clase es menor o igual que el parámetro
*/
template<class NumericType> bool vNumber<NumericType>::operator <=(NumericType other){
    return (**data) <= other;
}

/**@brief Compara dos vNumber<NumericType>
* @param NumericType other: numero a comparar
* @return bool: true si la clase es mayor que el parámetro
*/
template<class NumericType> bool vNumber<NumericType>::operator >(NumericType other){
    return (**data) > other;
}

/**@brief Compara dos vNumber<NumericType>
* @param NumericType other: numero a comparar
* @return bool: true si la clase es mayor o igual que el parámetro
*/
template<class NumericType> bool vNumber<NumericType>::operator >=(NumericType other){
    return (**data) >= other;
}

/**@brief Compara dos vNumber<NumericType>
* @param NumericType other: numero a comparar
* @return bool: true si la clase es igual que el parámetro
*/
template<class NumericType> bool vNumber<NumericType>::operator ==(NumericType other){
    return (**data) == other;
}

/**@brief Compara dos vNumber<NumericType>
* @param NumericType other: numero a comparar
* @return bool: true si la clase es diferente que el parámetro
*/
template<class NumericType> bool vNumber<NumericType>::operator !=(NumericType other){
    return (**data) != other;
}

/**@brief resta una unidad al dato
*/
template<class NumericType> void vNumber<NumericType>::operator --(){
    --(**data);
}

/**@brief suma una unidad al dato
*/
template<class NumericType> void vNumber<NumericType>::operator ++(){
    ++(**data);
}

#endif //VH2015_VNUMBER_H
