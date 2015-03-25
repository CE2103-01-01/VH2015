#include "xmlWriter.h"
#include "XML/pugiconfig.hpp"
#include "XML/pugixml.hpp"
#include <assert.h>

using namespace std;

xmlWriter::xmlWriter(){

}

void xmlWriter::crearXML(){
	pugi::xml_node nodoDeclaracion = doc.append_child(pugi::node_declaration);
	nodoDeclaracion.append_attribute("version") = "1.0";

	pugi::xml_node raiz = doc.append_child("Raiz");

	pugi::xml_node nodoHijo = raiz.append_child("Hijo1");
	nodoHijo.append_attribute("Dato") = "primer dato";
	nodoHijo.append_child("Nombre");

	bool guardar = doc.save_file("prueba.xml", PUGIXML_TEXT("   "));
	assert(guardar);
}
