//
// Created by alex on 18/03/15.
//
#include "vObject.h"

#include <vObject.h>
#include "vRef.h"
vRef::vRef(vObject newObject,int* id){
    object = newObject;
    referenceID=id;
}
vRef::~vRef()
{
    delete this;
}


<vObject> vRef::operator*() {
    return vRef::object;

}
void vRef::changeID(int *id) {
    referenceID = id;
}
<vRef> vRef::operator--() {

}
<vRef> vRef::operator=() {

}
<vRef> vRef::operator==() {

}