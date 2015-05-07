//
// Created by roberto on 30/03/15.
//

#include "vTypes/Headers/vInt.h"

/**@brief Construye un vInt inicializando su dado con un vMalloc y un vPlacement de 0.
 */
vInt::vInt(){
    data = vMalloc(sizeof(int));
    vPlacement(data,(int)0);
}

/**@brief Crea un vInt inicializando su dado con un vMalloc y un vPlacement del parametro recibido.
 * @param int dataParam: dato a insertar
 */
vInt::vInt(int dataParam){
    data = vMalloc(sizeof(int));
    vPlacement(data,dataParam);
}

/**@brief Destructor.
 */
vInt::~vInt(){
    //vFree(data);
}

/**@brief Devuelve el dato envuelto por la clase
* @return int
*/
int vInt::operator !(){
    return (**data);
}

/**@brief Suma el parametro al dato contenido en la clase, devolviendola modificada
* @param vInt param: dato a sumar
* @return vInt: la clase con la suma
*/
vInt vInt::operator +(vInt param){
    (**data) += !param;
    return *this;
}

/**@brief Resta el parametro al dato contenido en la clase, devolviendola modificada
* @param vInt param: dato a restar
* @return vInt: la clase con la resta
*/
vInt vInt::operator -(vInt param){
    (**data) -= !param;
    return *this;
}

/**@brief Multiplica por el parametro al dato contenido en la clase, devolviendola modificada
* @param vInt param: dato a multiplicar
* @return vInt: la clase con la multiplicacion
*/
vInt vInt::operator *(vInt param){
    (**data) *= !param;
    return *this;
}

/**@brief Divide por el parametro al dato contenido en la clase, devolviendola modificada
* @param vInt param: dato a dividr
* @return vInt: la clase con la division
*/
vInt vInt::operator /(vInt param){
    (**data) /= !param;
    return *this;
}

/**@brief Suma al dato, el parametro recibido
* @param vInt param: dato a sumar
*/
void vInt::operator +=(vInt param){
    (**data) += !param;
}

/**@brief Resta al dato, el parametro recibido
* @param vInt param: dato a resar
*/
void vInt::operator -=(vInt param){
    (**data) -= !param;
}

/**@brief Multiplica al dato por el parametro recibido
* @param vInt param: dato a multiplicar
*/
void vInt::operator *=(vInt param){
    (**data) *= !param;
}

/**@brief Divide al dato por el parametro recibido
* @param vInt param: divisor
*/
void vInt::operator /=(vInt param){
    (**data) /= !param;
}

/**@brief Suma el parametro al dato contenido en la clase, devolviendola modificada
* @param int param: dato a sumar
* @return int: la clase con la suma
*/
vInt vInt::operator +(int param){
    (**data) += param;
    return *this;
}

/**@brief Resta el parametro al dato contenido en la clase, devolviendola modificada
* @param int param: dato a restar
* @return int: la clase con la resta
*/
vInt vInt::operator -(int param){
    (**data) -= param;
    return *this;
}

/**@brief Multiplica por el parametro al dato contenido en la clase, devolviendola modificada
* @param int param: dato a multiplicar
* @return int: la clase con la multiplicacion
*/
vInt vInt::operator *(int param){
    (**data) *= param;
    return *this;
}

/**@brief Divide por el parametro al dato contenido en la clase, devolviendola modificada
* @param int param: dato a dividr
* @return int: la clase con la division
*/
vInt vInt::operator /(int param){
    (**data) /= param;
    return *this;
}

/**@brief Suma al dato, el parametro recibido
* @param int param: dato a sumar
*/
void vInt::operator +=(int param){
    (**data) += param;
}

/**@brief Resta al dato, el parametro recibido
* @param int param: dato a resar
*/
void vInt::operator -=(int param){
    (**data) -= param;
}

/**@brief Multiplica al dato por el parametro recibido
* @param int param: dato a multiplicar
*/
void vInt::operator *=(int param){
    (**data) *= param;
}

/**@brief Divide al dato por el parametro recibido
* @param int param: divisor
*/
void vInt::operator /=(int param){
    (**data) /= param;
}

/**@brief Asigna un nuevo valor al contenido de la clase
* @param vInt param: variable a sumar
*/
void vInt::operator =(vInt param){
    if((!data) != 0){
        vPlacement(data, !param);
    }else{
        data = vMalloc(sizeof(int));
        vPlacement(data, !param);
    }
}

/**@brief Compara dos vInt
* @param vInt other: numero a comparar
* @return bool: true si la clase es menor que el parámetro
*/
bool vInt::operator <(vInt other){
    return (**data) < (!other);
}

/**@brief Compara dos vInt
* @param vInt other: numero a comparar
* @return bool: true si la clase es menor o igual que el parámetro
*/
bool vInt::operator <=(vInt other){
    return (**data) <= (!other);
}

/**@brief Compara dos vInt
* @param vInt other: numero a comparar
* @return bool: true si la clase es mayor que el parámetro
*/
bool vInt::operator >(vInt other){
    return (**data) > (!other);
}

/**@brief Compara dos vInt
* @param vInt other: numero a comparar
* @return bool: true si la clase es mayor o igual que el parámetro
*/
bool vInt::operator >=(vInt other){
    return (**data) >= (!other);
}

/**@brief Compara dos vInt
* @param vInt other: numero a comparar
* @return bool: true si la clase igual que el parámetro
*/
bool vInt::operator ==(vInt other){
    return (**data) == (!other);
}


/**@brief Compara dos vInt
* @param vInt other: numero a comparar
* @return bool: true si la clase es diferente que el parámetro
*/
bool vInt::operator !=(vInt other){
    return (**data) != (!other);
}

/**@brief Compara dos vInt
* @param vInt other: numero a comparar
* @return bool: true si la clase es igual que el parámetro
*/
void vInt::operator =(int param){
    (**data) = param;
}

/**@brief Compara dos vInt
* @param int other: numero a comparar
* @return bool: true si la clase es menor que el parámetro
*/
bool vInt::operator <(int other){
    return (**data) < other;
}

/**@brief Compara dos vInt
* @param int other: numero a comparar
* @return bool: true si la clase es menor o igual que el parámetro
*/
bool vInt::operator <=(int other){
    return (**data) <= other;
}

/**@brief Compara dos vInt
* @param int other: numero a comparar
* @return bool: true si la clase es mayor que el parámetro
*/
bool vInt::operator >(int other){
    return (**data) > other;
}

/**@brief Compara dos vInt
* @param int other: numero a comparar
* @return bool: true si la clase es mayor o igual que el parámetro
*/
bool vInt::operator >=(int other){
    return (**data) >= other;
}

/**@brief Compara dos vInt
* @param int other: numero a comparar
* @return bool: true si la clase es igual que el parámetro
*/
bool vInt::operator ==(int other){
    return (**data) == other;
}

/**@brief Compara dos vInt
* @param int other: numero a comparar
* @return bool: true si la clase es diferente que el parámetro
*/
bool vInt::operator !=(int other){
    return (**data) != other;
}

/**@brief resta una unidad al dato
*/
void vInt::operator --(){
    --(**data);
}

/**@brief suma una unidad al dato
*/
void vInt::operator ++(){
    ++(**data);
}