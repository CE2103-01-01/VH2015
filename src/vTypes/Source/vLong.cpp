//
// Created by roberto on 30/03/15.
//

#include "vTypes/Headers/vLong.h"

//brief Construye un vLong inicializando su dado con un vMalloc y un vPlacement de 0.
vLong::vLong(){
    data = vMalloc(sizeof(long));
    vPlacement(data,(long)0);
};

//brief Crea un vLong inicializando su dado con un vMalloc y un vPlacement del parametro recibido.
//param long dataParam: dato a insertar
vLong::vLong(long dataParam){
    data = vMalloc(sizeof(long));
    vPlacement(data,dataParam);
};

//borra el dato
vLong::~vLong(){
    //vFree(data);
}

//brief Devuelve el dato envuelto por la clase
//return long
long vLong::operator !(){
    return (**data);
};

//brief Suma el parametro al dato contenido en la clase, devolviendola modificada
//param vLong param: dato a sumar
//return vLong: la clase con la suma
vLong vLong::operator +(vLong param){
    (**data) += !param;
    return *this;
};

//brief Suma al dato, el parametro recibido
//param vLong pls: dato a sumar
void vLong::operator +=(vLong pls){
    (**data) += !pls;
};

//brief Asigna un nuevo valor al contenido de la clase
//param vLong var: variable a sumar
void vLong::operator =(vLong var){
    if((!data) != 0){
        vPlacement(data, !var);
    }else{
        data = vMalloc(sizeof(long));
        vPlacement(data, !var);
    }
};

//brief Compara dos vLong
//param vLong other: numero a comparar
//return bool: true si la clase es menor que el parámetro
bool vLong::operator <(vLong other){
    return (**data) < (!other);
};

//brief Compara dos vLong
//param vLong other: numero a comparar
//return bool: true si la clase es menor o igual que el parámetro
bool vLong::operator <=(vLong other){
    return (**data) <= (!other);
};

//brief Compara dos vLong
//param vLong other: numero a comparar
//return bool: true si la clase es mayor que el parámetro
bool vLong::operator >(vLong other){
    return (**data) > (!other);
};

//brief Compara dos vLong
//param vLong other: numero a comparar
//return bool: true si la clase es mayor o igual que el parámetro
bool vLong::operator >=(vLong other){
    return (**data) >= (!other);
};

//brief Compara dos vLong
//param vLong other: numero a comparar
//return bool: true si la clase igual que el parámetro
bool vLong::operator ==(vLong other){
    return (**data) == (!other);
};


//brief Compara dos vLong
//param vLong other: numero a comparar
//return bool: true si la clase es diferente que el parámetro
bool vLong::operator !=(vLong other){
    return (**data) != (!other);
};

//brief Suma un long a la clase
//param long other: numero a sumar
//return vLong: la clase modificada
vLong vLong::operator +(long param){
    (**data) += param;
    return *this;
};

//brief Suma un long a la clase
//param long other: numero a sumar
void vLong::operator +=(long pls){
    (**data) += pls;
};

//brief Compara dos vLong
//param vLong other: numero a comparar
//return bool: true si la clase es igual que el parámetro
void vLong::operator =(long var){
    (**data) = var;
};

//brief Compara dos vLong
//param long other: numero a comparar
//return bool: true si la clase es menor que el parámetro
bool vLong::operator <(long other){
    return (**data) < other;
};

//brief Compara dos vLong
//param long other: numero a comparar
//return bool: true si la clase es menor o igual que el parámetro
bool vLong::operator <=(long other){
    return (**data) <= other;
};

//brief Compara dos vLong
//param long other: numero a comparar
//return bool: true si la clase es mayor que el parámetro
bool vLong::operator >(long other){
    return (**data) > other;
};

//brief Compara dos vLong
//param long other: numero a comparar
//return bool: true si la clase es mayor o igual que el parámetro
bool vLong::operator >=(long other){
    return (**data) >= other;
};

//brief Compara dos vLong
//param long other: numero a comparar
//return bool: true si la clase es igual que el parámetro
bool vLong::operator ==(long other){
    return (**data) == other;
};

//brief Compara dos vLong
//param long other: numero a comparar
//return bool: true si la clase es diferente que el parámetro
bool vLong::operator !=(long other){
    return (**data) != other;
};

//brief resta una unidad al dato
void vLong::operator --(){
    --(**data);
};

//brief suma una unidad al dato
void vLong::operator ++(){
    ++(**data);
};