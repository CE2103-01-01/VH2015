#ifndef SRC_XMLREADER_H_
#define SRC_XMLREADER_H_
#include <string>
using namespace std;

class xmlReader {
public:
    xmlReader();
    ~xmlReader();
    string* vHeapOptions();
private:
    string* opciones;
};

#endif /* SRC_XMLREADER_H_ */
