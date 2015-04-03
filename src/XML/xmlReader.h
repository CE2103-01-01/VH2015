#ifndef SRC_XMLREADER_H_
#define SRC_XMLREADER_H_

#include "vHeapOptions.h"

class xmlReader {
public:
    xmlReader();
    ~xmlReader();
    void read(vHeapOptions*);
};

#endif /* SRC_XMLREADER_H_ */
