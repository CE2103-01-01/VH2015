#ifndef SRC_XMLREADER_H_
#define SRC_XMLREADER_H_
#include <string>
using namespace std;

struct Opciones {
    bool activo;
    string path;
    int size;
    float overweight;
};

class xmlReader {
public:
    xmlReader();
    ~xmlReader();
    Opciones vHeapOptions();
private:
    Opciones opciones;
};

#endif /* SRC_XMLREADER_H_ */
