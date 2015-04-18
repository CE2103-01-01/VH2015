//
// Created by roberto on 30/03/15.
//

#include "vTypes/Headers/vFloat.h"

//brief Construye un vFloat inicializando su dado con un vMalloc y un vPlacement de 0.
vFloat::vFloat(){
    data = vMalloc(sizeof(float));
    vPlacement(data,(float)0);
};

//brief Crea un vFloat inicializando su dado con un vMalloc y un vPlacement del parametro recibido.
//param float dataParam: dato a insertar
vFloat::vFloat(float dataParam){
    data = vMalloc(sizeof(float));
    vPlacement(data,dataParam);
};

//brief Devuelve el dato envuelto por la clase
//return float
float vFloat::operator !(){
    return (**data);
};

//brief Suma el parametro al dato contenido en la clase, devolviendola modificada
//param vFloat param: dato a sumar
//return vFloat: la clase con la suma
vFloat vFloat::operator +(vFloat param){
    (**data) += !param;
    return *this;
};

//brief Suma al dato, el parametro recibido
//param vFloat pls: dato a sumar
void vFloat::operator +=(vFloat pls){
    (**data) += !pls;
};

//brief Asigna un nuevo valor al contenido de la clase
//param vFloat var: variable a sumar
void vFloat::operator =(vFloat var){
    (**data) = !var;
};

//brief Compara dos vFloat
//param vFloat other: numero a comparar
//return bool: true si la clase es menor que el parámetro
bool vFloat::operator <(vFloat other){
    return (**data) < (!other);
};

//brief Compara dos vFloat
//param vFloat other: numero a comparar
//return bool: true si la clase es menor o igual que el parámetro
bool vFloat::operator <=(vFloat other){
    return (**data) <= (!other);
};

//brief Compara dos vFloat
//param vFloat other: numero a comparar
//return bool: true si la clase es mayor que el parámetro
bool vFloat::operator >(vFloat other){
    return (**data) > (!other);
};

//brief Compara dos vFloat
//param vFloat other: numero a comparar
//return bool: true si la clase es mayor o igual que el parámetro
bool vFloat::operator >=(vFloat other){
    return (**data) >= (!other);
};

//brief Compara dos vFloat
//param vFloat other: numero a comparar
//return bool: true si la clase igual que el parámetro
bool vFloat::operator ==(vFloat other){
    return (**data) == (!other);
};


//brief Compara dos vFloat
//param vFloat other: numero a comparar
//return bool: true si la clase es diferente que el parámetro
bool vFloat::operator !=(vFloat other){
    return (**data) != (!other);
};

//brief Suma un float a la clase
//param float other: numero a sumar
//return vFloat: la clase modificada
vFloat vFloat::operator +(float param){
    (**data) += param;
    return *this;
};

//brief Suma un float a la clase
//param float other: numero a sumar
void vFloat::operator +=(float pls){
    (**data) += pls;
};

//brief Compara dos vFloat
//param vFloat other: numero a comparar
//return bool: true si la clase es igual que el parámetro
void vFloat::operator =(float var){
    (**data) = var;
};

//brief Compara dos vFloat
//param float other: numero a comparar
//return bool: true si la clase es menor que el parámetro
bool vFloat::operator <(float other){
    return (**data) < other;
};

//brief Compara dos vFloat
//param float other: numero a comparar
//return bool: true si la clase es menor o igual que el parámetro
bool vFloat::operator <=(float other){
    return (**data) <= other;
};

//brief Compara dos vFloat
//param float other: numero a comparar
//return bool: true si la clase es mayor que el parámetro
bool vFloat::operator >(float other){
    return (**data) > other;
};

//brief Compara dos vFloat
//param float other: numero a comparar
//return bool: true si la clase es mayor o igual que el parámetro
bool vFloat::operator >=(float other){
    return (**data) >= other;
};

//brief Compara dos vFloat
//param float other: numero a comparar
//return bool: true si la clase es igual que el parámetro
bool vFloat::operator ==(float other){
    return (**data) == other;
};

//brief Compara dos vFloat
//param float other: numero a comparar
//return bool: true si la clase es diferente que el parámetro
bool vFloat::operator !=(float other){
    return (**data) != other;
};

//brief resta una unidad al dato
void vFloat::operator --(){
    --(**data);
};

//brief suma una unidad al dato
void vFloat::operator ++(){
    ++(**data);
};