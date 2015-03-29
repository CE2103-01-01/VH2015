#include <string>
#include <iostream>
#include "xmlReader.h"
#include "XML/pugixml.hpp"
using namespace std;
using namespace pugi;

xmlReader::xmlReader() {
    opciones = new string[4];
}

xmlReader::~xmlReader() {
    delete this;
}

string* xmlReader::vHeapOptions() {

    xml_document doc;
    doc.load_file("vHeap.xml");
    xml_node raiz = doc.child("VH2015");

    opciones[0] = raiz.child("vdebug").attribute("activo").value();
    opciones[1] = raiz.child("vdebug").attribute("vdebug-file-path").value();
    opciones[2] = raiz.child("vHeap").attribute("size").value();
    opciones[3] = raiz.child("vHeap").attribute("overweight").value();

    return opciones;
}
