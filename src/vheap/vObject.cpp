//
// Created by roberto on 29/03/15.
//

#include "vObject.h"

vObject::vObject(){

};

vObject::~vObject(){

};

vRef vObject::operator *(){
    return *ref;
};

char const vObject::getInstance(){
    return (char const) typeid(valor).name();
};