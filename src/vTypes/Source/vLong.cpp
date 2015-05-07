//
// Created by roberto on 30/03/15.
//

#include "vTypes/Headers/vLong.h"

/**@brief Construye un vLong inicializando su dado con un vMalloc y un vPlacement de 0.
 */
vLong::vLong(){
    data = vMalloc(sizeof(long));
    vPlacement(data,(long)0);
}

/**@brief Crea un vLong inicializando su dado con un vMalloc y un vPlacement del parametro recibido.
 * @param long dataParam: dato a insertar
 */
vLong::vLong(long dataParam){
    data = vMalloc(sizeof(long));
    vPlacement(data,dataParam);
}

/**@brief Destructor.
 */
vLong::~vLong(){
    //vFree(data);
}

/**@brief Devuelve el dato envuelto por la clase
* @return long
*/
long vLong::operator !(){
    return (**data);
}

/**@brief Suma el parametro al dato contenido en la clase, devolviendola modificada
* @param vLong param: dato a sumar
* @return vLong: la clase con la suma
*/
vLong vLong::operator +(vLong param){
    (**data) += !param;
    return *this;
}

/**@brief Resta el parametro al dato contenido en la clase, devolviendola modificada
* @param vLong param: dato a restar
* @return vLong: la clase con la resta
*/
vLong vLong::operator -(vLong param){
    (**data) -= !param;
    return *this;
}

/**@brief Multiplica por el parametro al dato contenido en la clase, devolviendola modificada
* @param vLong param: dato a multiplicar
* @return vLong: la clase con la multiplicacion
*/
vLong vLong::operator *(vLong param){
    (**data) *= !param;
    return *this;
}

/**@brief Divide por el parametro al dato contenido en la clase, devolviendola modificada
* @param vLong param: dato a dividr
* @return vLong: la clase con la division
*/
vLong vLong::operator /(vLong param){
    (**data) /= !param;
    return *this;
}

/**@brief Suma al dato, el parametro recibido
* @param vLong param: dato a sumar
*/
void vLong::operator +=(vLong param){
    (**data) += !param;
}

/**@brief Resta al dato, el parametro recibido
* @param vLong param: dato a resar
*/
void vLong::operator -=(vLong param){
    (**data) -= !param;
}

/**@brief Multiplica al dato por el parametro recibido
* @param vLong param: dato a multiplicar
*/
void vLong::operator *=(vLong param){
    (**data) *= !param;
}

/**@brief Divide al dato por el parametro recibido
* @param vLong param: divisor
*/
void vLong::operator /=(vLong param){
    (**data) /= !param;
}

/**@brief Suma el parametro al dato contenido en la clase, devolviendola modificada
* @param long param: dato a sumar
* @return long: la clase con la suma
*/
vLong vLong::operator +(long param){
    (**data) += param;
    return *this;
}

/**@brief Resta el parametro al dato contenido en la clase, devolviendola modificada
* @param long param: dato a restar
* @return long: la clase con la resta
*/
vLong vLong::operator -(long param){
    (**data) -= param;
    return *this;
}

/**@brief Multiplica por el parametro al dato contenido en la clase, devolviendola modificada
* @param long param: dato a multiplicar
* @return long: la clase con la multiplicacion
*/
vLong vLong::operator *(long param){
    (**data) *= param;
    return *this;
}

/**@brief Divide por el parametro al dato contenido en la clase, devolviendola modificada
* @param long param: dato a dividr
* @return long: la clase con la division
*/
vLong vLong::operator /(long param){
    (**data) /= param;
    return *this;
}

/**@brief Suma al dato, el parametro recibido
* @param long param: dato a sumar
*/
void vLong::operator +=(long param){
    (**data) += param;
}

/**@brief Resta al dato, el parametro recibido
* @param long param: dato a resar
*/
void vLong::operator -=(long param){
    (**data) -= param;
}

/**@brief Multiplica al dato por el parametro recibido
* @param long param: dato a multiplicar
*/
void vLong::operator *=(long param){
    (**data) *= param;
}

/**@brief Divide al dato por el parametro recibido
* @param long param: divisor
*/
void vLong::operator /=(long param){
    (**data) /= param;
}

/**@brief Asigna un nuevo valor al contenido de la clase
* @param vLong param: variable a sumar
*/
void vLong::operator =(vLong param){
    if((!data) != 0){
        vPlacement(data, !param);
    }else{
        data = vMalloc(sizeof(long));
        vPlacement(data, !param);
    }
}

/**@brief Compara dos vLong
* @param vLong other: numero a comparar
* @return bool: true si la clase es menor que el parámetro
*/
bool vLong::operator <(vLong other){
    return (**data) < (!other);
}

/**@brief Compara dos vLong
* @param vLong other: numero a comparar
* @return bool: true si la clase es menor o igual que el parámetro
*/
bool vLong::operator <=(vLong other){
    return (**data) <= (!other);
}

/**@brief Compara dos vLong
* @param vLong other: numero a comparar
* @return bool: true si la clase es mayor que el parámetro
*/
bool vLong::operator >(vLong other){
    return (**data) > (!other);
}

/**@brief Compara dos vLong
* @param vLong other: numero a comparar
* @return bool: true si la clase es mayor o igual que el parámetro
*/
bool vLong::operator >=(vLong other){
    return (**data) >= (!other);
}

/**@brief Compara dos vLong
* @param vLong other: numero a comparar
* @return bool: true si la clase igual que el parámetro
*/
bool vLong::operator ==(vLong other){
    return (**data) == (!other);
}


/**@brief Compara dos vLong
* @param vLong other: numero a comparar
* @return bool: true si la clase es diferente que el parámetro
*/
bool vLong::operator !=(vLong other){
    return (**data) != (!other);
}

/**@brief Compara dos vLong
* @param vLong other: numero a comparar
* @return bool: true si la clase es igual que el parámetro
*/
void vLong::operator =(long param){
    (**data) = param;
}

/**@brief Compara dos vLong
* @param long other: numero a comparar
* @return bool: true si la clase es menor que el parámetro
*/
bool vLong::operator <(long other){
    return (**data) < other;
}

/**@brief Compara dos vLong
* @param long other: numero a comparar
* @return bool: true si la clase es menor o igual que el parámetro
*/
bool vLong::operator <=(long other){
    return (**data) <= other;
}

/**@brief Compara dos vLong
* @param long other: numero a comparar
* @return bool: true si la clase es mayor que el parámetro
*/
bool vLong::operator >(long other){
    return (**data) > other;
}

/**@brief Compara dos vLong
* @param long other: numero a comparar
* @return bool: true si la clase es mayor o igual que el parámetro
*/
bool vLong::operator >=(long other){
    return (**data) >= other;
}

/**@brief Compara dos vLong
* @param long other: numero a comparar
* @return bool: true si la clase es igual que el parámetro
*/
bool vLong::operator ==(long other){
    return (**data) == other;
}

/**@brief Compara dos vLong
* @param long other: numero a comparar
* @return bool: true si la clase es diferente que el parámetro
*/
bool vLong::operator !=(long other){
    return (**data) != other;
}

/**@brief resta una unidad al dato
*/
void vLong::operator --(){
    --(**data);
}

/**@brief suma una unidad al dato
*/
void vLong::operator ++(){
    ++(**data);
}