//
// Created by pablo on 31/03/15.
//

#ifndef VH2015_VMALLOCMDENTRY_H
#define VH2015_VMALLOCMDENTRY_H


class vMallocMDEntry {
private:
    unsigned int idRef = 0;
    void *offset = 0;
    unsigned int dataSize = 0;
    bool useFlag = false;
    unsigned int numReferences;

public:
    vMallocMDEntry();

    vMallocMDEntry(int, int, void *);

    int operator!();

    void changeFlag();

    void *operator&();

    int getIdRef();

    void *getOffSet();

    // std::type_info getTypeInfo();
    int getDataSize();

    bool getUseFlag();

    unsigned int getNumReferences();

    void decreaseNumReferences();

    void increaseNumReferences();

};


#endif //VH2015_VMALLOCMDENTRY_H
