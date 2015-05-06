//
// Created by roberto on 30/03/15.
//

#include "vTypes/Headers/vChar.h"

//brief Construye un vChar inicializando su dado con un vMalloc y un vPlacement de 0.
vChar::vChar(){
    data = vMalloc(sizeof(char));
    vPlacement(data,(char)0);
}

//brief Crea un vChar inicializando su dado con un vMalloc y un vPlacement del parametro recibido.
//param char dataParam: dato a insertar
vChar::vChar(char dataParam){
    data = vMalloc(sizeof(char));
    vPlacement(data,dataParam);
}


//borra el dato
vChar::~vChar(){
//    vFree(data);
}


//brief Devuelve el dato envuelto por la clase
//return char
char vChar::operator !(){
    return (**data);
}

//brief Suma el parametro al dato contenido en la clase, devolviendola modificada
//param vChar param: dato a sumar
//return vChar: la clase con la suma
vChar vChar::operator +(vChar param){
    (**data) += !param;
    return *this;
}

//brief Suma al dato, el parametro recibido
//param vChar pls: dato a sumar
void vChar::operator +=(vChar pls){
    (**data) += !pls;
}

//brief Asigna un nuevo valor al contenido de la clase
//param vChar var: variable a sumar
void vChar::operator =(vChar var){
    if((!data) != 0){
        vPlacement(data, !var);
    }else{
        data = vMalloc(sizeof(long));
        vPlacement(data, !var);
    }
}

//brief Compara dos vChar
//param vChar other: numero a comparar
//return bool: true si la clase es menor que el parámetro
bool vChar::operator <(vChar other){
    return (**data) < (!other);
}

//brief Compara dos vChar
//param vChar other: numero a comparar
//return bool: true si la clase es menor o igual que el parámetro
bool vChar::operator <=(vChar other){
    return (**data) <= (!other);
}

//brief Compara dos vChar
//param vChar other: numero a comparar
//return bool: true si la clase es mayor que el parámetro
bool vChar::operator >(vChar other){
    return (**data) > (!other);
}

//brief Compara dos vChar
//param vChar other: numero a comparar
//return bool: true si la clase es mayor o igual que el parámetro
bool vChar::operator >=(vChar other){
    return (**data) >= (!other);
}

//brief Compara dos vChar
//param vChar other: numero a comparar
//return bool: true si la clase igual que el parámetro
bool vChar::operator ==(vChar other){
    return (**data) == (!other);
}


//brief Compara dos vChar
//param vChar other: numero a comparar
//return bool: true si la clase es diferente que el parámetro
bool vChar::operator !=(vChar other){
    return (**data) != (!other);
}

//brief Suma un char a la clase
//param char other: numero a sumar
//return vChar: la clase modificada
vChar vChar::operator +(char param){
    (**data) += param;
    return *this;
}

//brief Suma un char a la clase
//param char other: numero a sumar
void vChar::operator +=(char pls){
    (**data) += pls;
}

//brief Compara dos vChar
//param vChar other: numero a comparar
//return bool: true si la clase es igual que el parámetro
void vChar::operator =(char var){
    (**data) = var;
}

//brief Compara dos vChar
//param char other: numero a comparar
//return bool: true si la clase es menor que el parámetro
bool vChar::operator <(char other){
    return (**data) < other;
}

//brief Compara dos vChar
//param char other: numero a comparar
//return bool: true si la clase es menor o igual que el parámetro
bool vChar::operator <=(char other){
    return (**data) <= other;
}

//brief Compara dos vChar
//param char other: numero a comparar
//return bool: true si la clase es mayor que el parámetro
bool vChar::operator >(char other){
    return (**data) > other;
}

//brief Compara dos vChar
//param char other: numero a comparar
//return bool: true si la clase es mayor o igual que el parámetro
bool vChar::operator >=(char other){
    return (**data) >= other;
}

//brief Compara dos vChar
//param char other: numero a comparar
//return bool: true si la clase es igual que el parámetro
bool vChar::operator ==(char other){
    return (**data) == other;
}

//brief Compara dos vChar
//param char other: numero a comparar
//return bool: true si la clase es diferente que el parámetro
bool vChar::operator !=(char other){
    return (**data) != other;
}

//brief resta una unidad al dato
void vChar::operator --(){
    --(**data);
}

//brief suma una unidad al dato
void vChar::operator ++(){
    ++(**data);
}