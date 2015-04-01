//
// Created by pablo on 31/03/15.
//

#include <vHeap/Headers/vMallocMDEntry.h>
#include <stddef.h>

vMallocMDEntry::vMallocMDEntry(int pIdRef, int pDataSize, void *pOffset) {
    idRef = pIdRef;
    size_t a = typeid(1).hash_code();

    dataSize = pDataSize;
    offset = pOffset;
}

void *vMallocMDEntry::getOffSet() {
    return offset;
}


int vMallocMDEntry::getDataSize() {
    return dataSize;
}

bool vMallocMDEntry::getUseFlag() {
    return useFlag;
}

int vMallocMDEntry::getIdRef() {
    return idRef;
}

vMallocMDEntry::vMallocMDEntry() {
    numReferences = 1;
}

void *vMallocMDEntry::operator&() {
    return offset;
};

int vMallocMDEntry::operator!() {
    return idRef;
};

void vMallocMDEntry::changeFlag() {
    if (useFlag) {
        useFlag = false;
    }
    else {
        useFlag = true;
    }
}

unsigned int vMallocMDEntry::getNumReferences() {
    return numReferences;
}

void vMallocMDEntry::decreaseNumReferences() {
    numReferences--;
}

void vMallocMDEntry::increaseNumReferences() {
    numReferences++;
}
