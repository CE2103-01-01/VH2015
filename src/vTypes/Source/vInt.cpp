//
// Created by roberto on 30/03/15.
//

#include "vTypes/Headers/vInt.h"
//brief Construye un vInt inicializando su dado con un vMalloc y un vPlacement de 0.
vInt::vInt(){
    data = vMalloc(sizeof(int));
    vPlacement(data,(int)0);
}

//brief Crea un vInt inicializando su dado con un vMalloc y un vPlacement del parametro recibido.
//param int dataParam: dato a insertar
vInt::vInt(int dataParam){
    data = vMalloc(sizeof(int));
    vPlacement(data,dataParam);
}

//borra el dato
vInt::~vInt(){
    //vFree(data);
}

//brief Devuelve el dato envuelto por la clase
//return int
int vInt::operator !(){
    return (**data);
}

//brief Suma el parametro al dato contenido en la clase, devolviendola modificada
//param vInt param: dato a sumar
//return vInt: la clase con la suma
vInt vInt::operator +(vInt param){
    (**data) += !param;
    return *this;
}

//brief Suma al dato, el parametro recibido
//param vInt pls: dato a sumar
void vInt::operator +=(vInt pls){
    (**data) += !pls;
}

//brief Asigna un nuevo valor al contenido de la clase
//param vInt var: variable a sumar
void vInt::operator =(vInt var){
    if((!data) != 0){
        vPlacement(data, !var);
    }else{
        data = vMalloc(sizeof(long));
        vPlacement(data, !var);
    }
}

//brief Compara dos vInt
//param vInt other: numero a comparar
//return bool: true si la clase es menor que el parámetro
bool vInt::operator <(vInt other){
    return (**data) < (!other);
}

//brief Compara dos vInt
//param vInt other: numero a comparar
//return bool: true si la clase es menor o igual que el parámetro
bool vInt::operator <=(vInt other){
    return (**data) <= (!other);
}

//brief Compara dos vInt
//param vInt other: numero a comparar
//return bool: true si la clase es mayor que el parámetro
bool vInt::operator >(vInt other){
    return (**data) > (!other);
}

//brief Compara dos vInt
//param vInt other: numero a comparar
//return bool: true si la clase es mayor o igual que el parámetro
bool vInt::operator >=(vInt other){
    return (**data) >= (!other);
}

//brief Compara dos vInt
//param vInt other: numero a comparar
//return bool: true si la clase igual que el parámetro
bool vInt::operator ==(vInt other){
    return (**data) == (!other);
}


//brief Compara dos vInt
//param vInt other: numero a comparar
//return bool: true si la clase es diferente que el parámetro
bool vInt::operator !=(vInt other){
    return (**data) != (!other);
}

//brief Suma un int a la clase
//param int other: numero a sumar
//return vInt: la clase modificada
vInt vInt::operator +(int param){
    (**data) += param;
    return *this;
}

//brief Suma un int a la clase
//param int other: numero a sumar
void vInt::operator +=(int pls){
    (**data) += pls;
}

//brief Compara dos vInt
//param vInt other: numero a comparar
//return bool: true si la clase es igual que el parámetro
void vInt::operator =(int var){
    (**data) = var;
}

//brief Compara dos vInt
//param int other: numero a comparar
//return bool: true si la clase es menor que el parámetro
bool vInt::operator <(int other){
    return (**data) < other;
}

//brief Compara dos vInt
//param int other: numero a comparar
//return bool: true si la clase es menor o igual que el parámetro
bool vInt::operator <=(int other){
    return (**data) <= other;
}

//brief Compara dos vInt
//param int other: numero a comparar
//return bool: true si la clase es mayor que el parámetro
bool vInt::operator >(int other){
    return (**data) > other;
}

//brief Compara dos vInt
//param int other: numero a comparar
//return bool: true si la clase es mayor o igual que el parámetro
bool vInt::operator >=(int other){
    return (**data) >= other;
}

//brief Compara dos vInt
//param int other: numero a comparar
//return bool: true si la clase es igual que el parámetro
bool vInt::operator ==(int other){
    return (**data) == other;
}

//brief Compara dos vInt
//param int other: numero a comparar
//return bool: true si la clase es diferente que el parámetro
bool vInt::operator !=(int other){
    return (**data) != other;
}

//brief resta una unidad al dato
void vInt::operator --(){
    --(**data);
}

//brief suma una unidad al dato
void vInt::operator ++(){
    ++(**data);
}