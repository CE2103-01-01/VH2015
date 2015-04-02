using namespace pugi;

xmlReader::xmlReader() {};

xmlReader::~xmlReader() {};

void xmlReader::read(vHeapOptions* ret) {
    xml_document doc;
    doc.load_file(ret->xmlPath);
    xml_node raiz = doc.child("VH2015");
    *ret+raiz.child("vdebug").attribute("activo").as_bool();
    *ret+raiz.child("vdebug").attribute("vdebug-file-path").value();
    *ret+raiz.child("vHeap").attribute("size").as_int();
    *ret+raiz.child("vHeap").attribute("overweight").as_float();
};
