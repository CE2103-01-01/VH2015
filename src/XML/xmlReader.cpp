#include <string>
#include <iostream>
#include "xmlReader.h"
#include "XML/pugixml.hpp"
using namespace std;
using namespace pugi;

xmlReader::xmlReader() {
}

xmlReader::~xmlReader() {
    delete this;
}

Opciones xmlReader::vHeapOptions() {

    xml_document doc;
    doc.load_file("vHeap.xml");
    xml_node raiz = doc.child("VH2015");

    opciones.activo = raiz.child("vdebug").attribute("activo").as_bool();
    opciones.path = raiz.child("vdebug").attribute("vdebug-file-path").value();
    opciones.size = raiz.child("vHeap").attribute("size").as_int();
    opciones.overweight = raiz.child("vHeap").attribute("overweight").as_float();

    return opciones;
}