//
// Created by roberto on 30/03/15.
//

#include "vTypes/Headers/vChar.h"

/**@brief Construye un vChar inicializando su dado con un vMalloc y un vPlacement de 0.
 */
vChar::vChar(){
    data = vMalloc(sizeof(char));
    vPlacement(data,(char)0);
}

/**@brief Crea un vChar inicializando su dado con un vMalloc y un vPlacement del parametro recibido.
 * @param char dataParam: dato a insertar
 */
vChar::vChar(char dataParam){
    data = vMalloc(sizeof(char));
    vPlacement(data,dataParam);
}

/**@brief Destructor.
 */
vChar::~vChar(){
    //vFree(data);
}

/**@brief Devuelve el dato envuelto por la clase
* @return char
*/
char vChar::operator !(){
    return (**data);
}

/**@brief Suma el parametro al dato contenido en la clase, devolviendola modificada
* @param vChar param: dato a sumar
* @return vChar: la clase con la suma
*/
vChar vChar::operator +(vChar param){
    (**data) += !param;
    return *this;
}

/**@brief Resta el parametro al dato contenido en la clase, devolviendola modificada
* @param vChar param: dato a restar
* @return vChar: la clase con la resta
*/
vChar vChar::operator -(vChar param){
    (**data) -= !param;
    return *this;
}

/**@brief Multiplica por el parametro al dato contenido en la clase, devolviendola modificada
* @param vChar param: dato a multiplicar
* @return vChar: la clase con la multiplicacion
*/
vChar vChar::operator *(vChar param){
    (**data) *= !param;
    return *this;
}

/**@brief Divide por el parametro al dato contenido en la clase, devolviendola modificada
* @param vChar param: dato a dividr
* @return vChar: la clase con la division
*/
vChar vChar::operator /(vChar param){
    (**data) /= !param;
    return *this;
}

/**@brief Suma al dato, el parametro recibido
* @param vChar param: dato a sumar
*/
void vChar::operator +=(vChar param){
    (**data) += !param;
}

/**@brief Resta al dato, el parametro recibido
* @param vChar param: dato a resar
*/
void vChar::operator -=(vChar param){
    (**data) -= !param;
}

/**@brief Multiplica al dato por el parametro recibido
* @param vChar param: dato a multiplicar
*/
void vChar::operator *=(vChar param){
    (**data) *= !param;
}

/**@brief Divide al dato por el parametro recibido
* @param vChar param: divisor
*/
void vChar::operator /=(vChar param){
    (**data) /= !param;
}

/**@brief Suma el parametro al dato contenido en la clase, devolviendola modificada
* @param char param: dato a sumar
* @return char: la clase con la suma
*/
vChar vChar::operator +(char param){
    (**data) += param;
    return *this;
}

/**@brief Resta el parametro al dato contenido en la clase, devolviendola modificada
* @param char param: dato a restar
* @return char: la clase con la resta
*/
vChar vChar::operator -(char param){
    (**data) -= param;
    return *this;
}

/**@brief Multiplica por el parametro al dato contenido en la clase, devolviendola modificada
* @param char param: dato a multiplicar
* @return char: la clase con la multiplicacion
*/
vChar vChar::operator *(char param){
    (**data) *= param;
    return *this;
}

/**@brief Divide por el parametro al dato contenido en la clase, devolviendola modificada
* @param char param: dato a dividr
* @return char: la clase con la division
*/
vChar vChar::operator /(char param){
    (**data) /= param;
    return *this;
}

/**@brief Suma al dato, el parametro recibido
* @param char param: dato a sumar
*/
void vChar::operator +=(char param){
    (**data) += param;
}

/**@brief Resta al dato, el parametro recibido
* @param char param: dato a resar
*/
void vChar::operator -=(char param){
    (**data) -= param;
}

/**@brief Multiplica al dato por el parametro recibido
* @param char param: dato a multiplicar
*/
void vChar::operator *=(char param){
    (**data) *= param;
}

/**@brief Divide al dato por el parametro recibido
* @param char param: divisor
*/
void vChar::operator /=(char param){
    (**data) /= param;
}

/**@brief Asigna un nuevo valor al contenido de la clase
* @param vChar param: variable a sumar
*/
void vChar::operator =(vChar param){
    if((!data) != 0){
        vPlacement(data, !param);
    }else{
        data = vMalloc(sizeof(char));
        vPlacement(data, !param);
    }
}

/**@brief Compara dos vChar
* @param vChar other: numero a comparar
* @return bool: true si la clase es menor que el parámetro
*/
bool vChar::operator <(vChar other){
    return (**data) < (!other);
}

/**@brief Compara dos vChar
* @param vChar other: numero a comparar
* @return bool: true si la clase es menor o igual que el parámetro
*/
bool vChar::operator <=(vChar other){
    return (**data) <= (!other);
}

/**@brief Compara dos vChar
* @param vChar other: numero a comparar
* @return bool: true si la clase es mayor que el parámetro
*/
bool vChar::operator >(vChar other){
    return (**data) > (!other);
}

/**@brief Compara dos vChar
* @param vChar other: numero a comparar
* @return bool: true si la clase es mayor o igual que el parámetro
*/
bool vChar::operator >=(vChar other){
    return (**data) >= (!other);
}

/**@brief Compara dos vChar
* @param vChar other: numero a comparar
* @return bool: true si la clase igual que el parámetro
*/
bool vChar::operator ==(vChar other){
    return (**data) == (!other);
}


/**@brief Compara dos vChar
* @param vChar other: numero a comparar
* @return bool: true si la clase es diferente que el parámetro
*/
bool vChar::operator !=(vChar other){
    return (**data) != (!other);
}

/**@brief Compara dos vChar
* @param vChar other: numero a comparar
* @return bool: true si la clase es igual que el parámetro
*/
void vChar::operator =(char param){
    (**data) = param;
}

/**@brief Compara dos vChar
* @param char other: numero a comparar
* @return bool: true si la clase es menor que el parámetro
*/
bool vChar::operator <(char other){
    return (**data) < other;
}

/**@brief Compara dos vChar
* @param char other: numero a comparar
* @return bool: true si la clase es menor o igual que el parámetro
*/
bool vChar::operator <=(char other){
    return (**data) <= other;
}

/**@brief Compara dos vChar
* @param char other: numero a comparar
* @return bool: true si la clase es mayor que el parámetro
*/
bool vChar::operator >(char other){
    return (**data) > other;
}

/**@brief Compara dos vChar
* @param char other: numero a comparar
* @return bool: true si la clase es mayor o igual que el parámetro
*/
bool vChar::operator >=(char other){
    return (**data) >= other;
}

/**@brief Compara dos vChar
* @param char other: numero a comparar
* @return bool: true si la clase es igual que el parámetro
*/
bool vChar::operator ==(char other){
    return (**data) == other;
}

/**@brief Compara dos vChar
* @param char other: numero a comparar
* @return bool: true si la clase es diferente que el parámetro
*/
bool vChar::operator !=(char other){
    return (**data) != other;
}

/**@brief resta una unidad al dato
*/
void vChar::operator --(){
    --(**data);
}

/**@brief suma una unidad al dato
*/
void vChar::operator ++(){
    ++(**data);
}