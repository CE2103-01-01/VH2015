using namespace std;
using namespace pugi;

static char const *const xmlPath = "vHeap.xml";

xmlReader::xmlReader() {
}

xmlReader::~xmlReader() {
    delete this;
}

Opciones xmlReader::vHeapOptions() {

    xml_document doc;
    doc.load_file(xmlPath);
    xml_node raiz = doc.child("VH2015");

    opciones.activo = raiz.child("vdebug").attribute("activo").as_bool();
    opciones.path = raiz.child("vdebug").attribute("vdebug-file-path").value();
    opciones.size = raiz.child("vHeap").attribute("size").as_int();
    opciones.overweight = raiz.child("vHeap").attribute("overweight").as_float();

    return opciones;
}
