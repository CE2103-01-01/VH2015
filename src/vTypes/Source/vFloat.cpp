//
// Created by roberto on 30/03/15.
//

#include "vTypes/Headers/vFloat.h"
/**@brief Construye un vFloat inicializando su dado con un vMalloc y un vPlacement de 0.
 */
vFloat::vFloat(){
    data = vMalloc(sizeof(float));
    vPlacement(data,(float)0);
}

/**@brief Crea un vFloat inicializando su dado con un vMalloc y un vPlacement del parametro recibido.
 * @param float dataParam: dato a insertar
 */
vFloat::vFloat(float dataParam){
    data = vMalloc(sizeof(float));
    vPlacement(data,dataParam);
}

/**@brief Destructor.
 */
vFloat::~vFloat(){
    //vFree(data);
}

/**@brief Devuelve el dato envuelto por la clase
* @return float
*/
float vFloat::operator !(){
    return (**data);
}

/**@brief Suma el parametro al dato contenido en la clase, devolviendola modificada
* @param vFloat param: dato a sumar
* @return vFloat: la clase con la suma
*/
vFloat vFloat::operator +(vFloat param){
    (**data) += !param;
    return *this;
}

/**@brief Resta el parametro al dato contenido en la clase, devolviendola modificada
* @param vFloat param: dato a restar
* @return vFloat: la clase con la resta
*/
vFloat vFloat::operator -(vFloat param){
    (**data) -= !param;
    return *this;
}

/**@brief Multiplica por el parametro al dato contenido en la clase, devolviendola modificada
* @param vFloat param: dato a multiplicar
* @return vFloat: la clase con la multiplicacion
*/
vFloat vFloat::operator *(vFloat param){
    (**data) *= !param;
    return *this;
}

/**@brief Divide por el parametro al dato contenido en la clase, devolviendola modificada
* @param vFloat param: dato a dividr
* @return vFloat: la clase con la division
*/
vFloat vFloat::operator /(vFloat param){
    (**data) /= !param;
    return *this;
}

/**@brief Suma al dato, el parametro recibido
* @param vFloat param: dato a sumar
*/
void vFloat::operator +=(vFloat param){
    (**data) += !param;
}

/**@brief Resta al dato, el parametro recibido
* @param vFloat param: dato a resar
*/
void vFloat::operator -=(vFloat param){
    (**data) -= !param;
}

/**@brief Multiplica al dato por el parametro recibido
* @param vFloat param: dato a multiplicar
*/
void vFloat::operator *=(vFloat param){
    (**data) *= !param;
}

/**@brief Divide al dato por el parametro recibido
* @param vFloat param: divisor
*/
void vFloat::operator /=(vFloat param){
    (**data) /= !param;
}

/**@brief Suma el parametro al dato contenido en la clase, devolviendola modificada
* @param float param: dato a sumar
* @return float: la clase con la suma
*/
vFloat vFloat::operator +(float param){
    (**data) += param;
    return *this;
}

/**@brief Resta el parametro al dato contenido en la clase, devolviendola modificada
* @param float param: dato a restar
* @return float: la clase con la resta
*/
vFloat vFloat::operator -(float param){
    (**data) -= param;
    return *this;
}

/**@brief Multiplica por el parametro al dato contenido en la clase, devolviendola modificada
* @param float param: dato a multiplicar
* @return float: la clase con la multiplicacion
*/
vFloat vFloat::operator *(float param){
    (**data) *= param;
    return *this;
}

/**@brief Divide por el parametro al dato contenido en la clase, devolviendola modificada
* @param float param: dato a dividr
* @return float: la clase con la division
*/
vFloat vFloat::operator /(float param){
    (**data) /= param;
    return *this;
}

/**@brief Suma al dato, el parametro recibido
* @param float param: dato a sumar
*/
void vFloat::operator +=(float param){
    (**data) += param;
}

/**@brief Resta al dato, el parametro recibido
* @param float param: dato a resar
*/
void vFloat::operator -=(float param){
    (**data) -= param;
}

/**@brief Multiplica al dato por el parametro recibido
* @param float param: dato a multiplicar
*/
void vFloat::operator *=(float param){
    (**data) *= param;
}

/**@brief Divide al dato por el parametro recibido
* @param float param: divisor
*/
void vFloat::operator /=(float param){
    (**data) /= param;
}

/**@brief Asigna un nuevo valor al contenido de la clase
* @param vFloat param: variable a sumar
*/
void vFloat::operator =(vFloat param){
    if((!data) != 0){
        vPlacement(data, !param);
    }else{
        data = vMalloc(sizeof(float));
        vPlacement(data, !param);
    }
}

/**@brief Compara dos vFloat
* @param vFloat other: numero a comparar
* @return bool: true si la clase es menor que el parámetro
*/
bool vFloat::operator <(vFloat other){
    return (**data) < (!other);
}

/**@brief Compara dos vFloat
* @param vFloat other: numero a comparar
* @return bool: true si la clase es menor o igual que el parámetro
*/
bool vFloat::operator <=(vFloat other){
    return (**data) <= (!other);
}

/**@brief Compara dos vFloat
* @param vFloat other: numero a comparar
* @return bool: true si la clase es mayor que el parámetro
*/
bool vFloat::operator >(vFloat other){
    return (**data) > (!other);
}

/**@brief Compara dos vFloat
* @param vFloat other: numero a comparar
* @return bool: true si la clase es mayor o igual que el parámetro
*/
bool vFloat::operator >=(vFloat other){
    return (**data) >= (!other);
}

/**@brief Compara dos vFloat
* @param vFloat other: numero a comparar
* @return bool: true si la clase igual que el parámetro
*/
bool vFloat::operator ==(vFloat other){
    return (**data) == (!other);
}


/**@brief Compara dos vFloat
* @param vFloat other: numero a comparar
* @return bool: true si la clase es diferente que el parámetro
*/
bool vFloat::operator !=(vFloat other){
    return (**data) != (!other);
}

/**@brief Compara dos vFloat
* @param vFloat other: numero a comparar
* @return bool: true si la clase es igual que el parámetro
*/
void vFloat::operator =(float param){
    (**data) = param;
}

/**@brief Compara dos vFloat
* @param float other: numero a comparar
* @return bool: true si la clase es menor que el parámetro
*/
bool vFloat::operator <(float other){
    return (**data) < other;
}

/**@brief Compara dos vFloat
* @param float other: numero a comparar
* @return bool: true si la clase es menor o igual que el parámetro
*/
bool vFloat::operator <=(float other){
    return (**data) <= other;
}

/**@brief Compara dos vFloat
* @param float other: numero a comparar
* @return bool: true si la clase es mayor que el parámetro
*/
bool vFloat::operator >(float other){
    return (**data) > other;
}

/**@brief Compara dos vFloat
* @param float other: numero a comparar
* @return bool: true si la clase es mayor o igual que el parámetro
*/
bool vFloat::operator >=(float other){
    return (**data) >= other;
}

/**@brief Compara dos vFloat
* @param float other: numero a comparar
* @return bool: true si la clase es igual que el parámetro
*/
bool vFloat::operator ==(float other){
    return (**data) == other;
}

/**@brief Compara dos vFloat
* @param float other: numero a comparar
* @return bool: true si la clase es diferente que el parámetro
*/
bool vFloat::operator !=(float other){
    return (**data) != other;
}

/**@brief resta una unidad al dato
*/
void vFloat::operator --(){
    --(**data);
}

/**@brief suma una unidad al dato
*/
void vFloat::operator ++(){
    ++(**data);
}